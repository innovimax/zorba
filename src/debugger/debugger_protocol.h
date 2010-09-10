/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ZORBA_DEBUGGER_PROTOCOL_H
#define ZORBA_DEBUGGER_PROTOCOL_H

#include <errno.h>
#include <exception>
#include <string>
#include <sstream>
#include <ostream>
#include <istream>
#include <map>
#include <stack>

#include "common/common.h"
#include "compiler/parser/query_loc.h"

#include "api/serialization/serializer.h"
#include "debugger/debugger_common.h"

namespace zorba{

/* Type definition of fields */
typedef unsigned char Byte;
typedef uint32_t      Length;
typedef uint32_t      Id;
typedef unsigned char Flags;
typedef uint16_t      ErrorCode;
typedef unsigned char CommandSet;
typedef unsigned char Command;

/* sizeof(HeaderContent) == 12 because of the padding */
const int SIZE_OF_HEADER_CONTENT = 9;
const int SIZE_OF_REPLY_CONTENT = 2;

/* Flags */
const Flags NULL_FLAG           = 0x0;
const Flags VARIABLE_DATA_FLAG  = 0x04;
const Flags REPLY_FLAG          = 0x80;
const Flags REPLY_VARIABLE_FLAG = 0xf0;
const Flags REPLY_SET_FLAG      = 0xf1;
const Flags REPLY_FRAME_FLAG    = 0xf2;
const Flags REPLY_LIST_FLAG     = 0xf3;

/* CommandSet */
const CommandSet EXECUTION    = 0xf1;
const CommandSet BREAKPOINTS  = 0xf2;
const CommandSet STATIC       = 0xf3;
const CommandSet DYNAMIC      = 0xf4;
const CommandSet ENGINE_EVENT = 0xf8;

/* Execution Commands */
const Command RUN       = 0x01; 
const Command SUSPEND   = 0x02;
const Command RESUME    = 0x03;
const Command TERMINATE = 0x04;
const Command STEP      = 0x05;
const Command DETACH    = 0x06;

/* Breakpoints Commands */
const Command SET   = 0x01;
const Command CLEAR = 0x02;

/* Engine event Commands */
const Command STARTED    = 0x01;
const Command TERMINATED = 0x02;
const Command SUSPENDED  = 0x03;
const Command RESUMED    = 0x04;
const Command EVALUATED  = 0x05;

/* Static Commands */
const Command OPTIONS  = 0x01;
const Command DEFAULTS = 0x02;
const Command SETS     = 0x03;
const Command LIST     = 0x04;

/* Dynamic Commands */
const Command DATA        = 0x01;
const Command VARIABLES   = 0x02;
const Command FOCUS       = 0x03;
const Command TIME        = 0x04;
const Command DOCUMENTS   = 0x05;
const Command COLLECTIONS = 0x06;
const Command COLLECTION  = 0x07;
const Command EVAL        = 0x08;
const Command FRAME       = 0x09;

/* Error codes */
const ErrorCode DEBUGGER_NO_ERROR                      = 0;
const ErrorCode DEBUGGER_ERROR_UNKNOWN                 = 1;
const ErrorCode DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT  = 11;
const ErrorCode DEBUGGER_ERROR_INVALID_COMMAND         = 12;
const ErrorCode DEBUGGER_ERROR_COMMAND_NOT_IMPLEMENTED = 13;

/**
 * The header of the packet is always 11 bytes:
 * LLLLIIIIFKC
 *   LLLL � is the 4-byte length of the entire packet. This gives
 *          an upper bound on the length of the packet sent;
 *   IIII � is the 4-byte ID of the meaage;
 *   F    � 1-byte used for flags;
 *   K    � 1-byte identifying the command set;
 *   C    � 1-byte identifying the command
 */
const unsigned short MESSAGE_LENGTH_FIELD_SIZE = 4;
const unsigned short MESSAGE_ID_FIELD_SIZE = 4;
const unsigned short MESSAGE_FLAGS_FIELD_SIZE = 1;
const unsigned short MESSAGE_COMMAND_SET_FIELD_SIZE = 1;
const unsigned short MESSAGE_COMMAND_FIELD_SIZE = 1;

/* The index in the header of each header field */
const unsigned short MESSAGE_LENGTH_FIELD_INDEX = 0;
const unsigned short MESSAGE_ID_FIELD_INDEX = MESSAGE_LENGTH_FIELD_SIZE;
const unsigned short MESSAGE_FLAGS_FIELD_INDEX = MESSAGE_ID_FIELD_INDEX + MESSAGE_ID_FIELD_SIZE;
const unsigned short MESSAGE_COMMAND_SET_FIELD_INDEX = MESSAGE_FLAGS_FIELD_INDEX + MESSAGE_COMMAND_SET_FIELD_SIZE;
const unsigned short MESSAGE_COMMAND_FIELD_INDEX = MESSAGE_COMMAND_SET_FIELD_INDEX + MESSAGE_COMMAND_SET_FIELD_SIZE;

/* The message header size, or the size of a message without data payload */
const unsigned short MESSAGE_HEADER_SIZE =
    MESSAGE_LENGTH_FIELD_SIZE +
    MESSAGE_ID_FIELD_SIZE +
    MESSAGE_FLAGS_FIELD_SIZE +
    MESSAGE_COMMAND_SET_FIELD_SIZE +
    MESSAGE_COMMAND_FIELD_SIZE;

/* deals with endianness */
// exported for unit testing only
ZORBA_DLL_PUBLIC bool is_little_endian();
ZORBA_DLL_PUBLIC uint32_t uint_swap( uint32_t i );
ZORBA_DLL_PUBLIC uint16_t uint_swap( uint16_t i );

/**
 *   Signals a problem with the debugging protocol.
 */
// all classes are exported for unit testing only
class ZORBA_DLL_PUBLIC MessageException : public std::exception
{
  public:
	  
    MessageException(const std::string &aMessage ) throw();
 
  /**
   *   Provided just to guarantee that no exceptions are thrown.
   */
    ~MessageException() throw();

  /**
     *   Get the exception message
     *   @return exception message
   */
    const char* what() const throw();

  private:
    std::string userMessage;  // Exception message
};

class ZORBA_DLL_PUBLIC MessageFormatException: public MessageException
{
  public:
    MessageFormatException( const std::string &aMessage ): MessageException( aMessage ){}
};

class ZORBA_DLL_PUBLIC InvalidCommandException: public MessageException
{
   public:
     InvalidCommandException( const std::string &aMessage ): MessageException( aMessage ){}

};

/**
 * Abstract representation of a packet
 * in the debugging protocol
 */
class ZORBA_DLL_PUBLIC AbstractMessage
{
  protected:

    virtual bool isValidMessage() const = 0;

    /*
     * check the integrity of the packet
     * throws an exception is something's wrong
     */
    void checkIntegrity();
    
    struct HeaderContent
    {
      Length theLength;
      Id theId;
      Flags theFlags;
    };

    HeaderContent * theHeaderContent;

    void setLength ( Length aLength ) { theHeaderContent->theLength = uint_swap( aLength ); }

    Length getLength() const { return uint_swap( theHeaderContent->theLength ); }

    void setId ( Id aId ) { theHeaderContent->theId = uint_swap( aId ); }

    void setFlags ( Flags aFlags ) { theHeaderContent->theFlags = aFlags; }

  public:

    AbstractMessage( const Id aId, const Flags aFlags );

    AbstractMessage( Byte *  aMessage );

    virtual ~AbstractMessage();

    virtual Byte * serialize( Length & aLength ) const = 0;

    Id getId() const { return uint_swap( theHeaderContent->theId ); }

    Flags getFlags() const { return theHeaderContent->theFlags; }
    //friend std::ostream& operator << ( std::ostream &os, const AbstractMessage * );
    
    bool operator == ( const AbstractMessage & );

    bool operator != ( const AbstractMessage & );
};

std::ostream& operator << ( std::ostream &os, const AbstractMessage * message);

/**
 * Abstract representation of a reply packet
 */
class ZORBA_DLL_PUBLIC ReplyMessage: public AbstractMessage
{
  protected:
	
    bool isValidMessage() const;

    struct ReplyContent
    {
      ErrorCode theErrorCode; 
    };

    ReplyContent * theReplyContent;

    xqpString theData;

  public:
    ReplyMessage( const Id aId, const ErrorCode aErrorCode );

    ReplyMessage( Byte * aMessage, const unsigned int aLength );

    virtual ~ReplyMessage();
    
    Byte * serialize( Length & aLength ) const;

    bool isOk() const;
    
    ErrorCode getErrorCode() const
    {
      return uint_swap( theReplyContent->theErrorCode );
    }

    void setErrorCode( ErrorCode aErrorCode )
    {
      theReplyContent->theErrorCode = uint_swap(aErrorCode);
    }

    xqpString getData() const
    {
      return theData;
    }

    void setData( xqpString lData )
    {
      setLength( MESSAGE_HEADER_SIZE + lData.length() );
      theData = lData;
    }
    
    const std::string getMessage()
    {
      switch ( getErrorCode() )
      {
        case DEBUGGER_NO_ERROR:
          return "No error";
        case DEBUGGER_ERROR_INVALID_COMMAND:
          return "Invalid Command";
        case DEBUGGER_ERROR_COMMAND_NOT_IMPLEMENTED:
          return "Command not implemented";
        case DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT:
          return "Invalid message format";
        default:
          return "Unknown error";
      }
    }
};

/**
 * 
 */
class ZORBA_DLL_PUBLIC AbstractCommandMessage: public AbstractMessage
{
  private:
    ReplyMessage *theReply;

    static unsigned long getNextId();
  
  protected:

    struct CommandContent
    {
      CommandSet theCommandSet;
      Command theCommand;
    };

    CommandContent* theCommandContent;

    void setCommandSet( CommandSet aCommandSet ){ theCommandContent->theCommandSet = aCommandSet; }

    void setCommand( Command aCommand ){ theCommandContent->theCommand = aCommand; }

    bool isValidMessage() const;

  public:
    bool isExecutionCommand() const;

    bool isBreakpointsCommand() const;

    bool isEngineEventCommand() const;

    bool isStaticCommand() const;

    bool isDynamicCommand() const;

    /**
     * Compute and assemble a packet implementing the debugger protocol
     * @param id (4 bytes): The packet id
     * @param flags (1 byte)
     * @param command_set (1 byte)
     * @param command (1 byte)
     * @param data (variable)
     */
    AbstractCommandMessage( const CommandSet aCommandSet,
        const Command aCommand, const Flags commandFlags = NULL_FLAG );

    AbstractCommandMessage( Byte * aMessage, const unsigned int aLength );

    virtual ~AbstractCommandMessage();
 
    CommandSet getCommandSet() const { return theCommandContent->theCommandSet; }

    Command getCommand() const { return theCommandContent->theCommand; }

    virtual ReplyMessage * getReplyMessage()
    {
      if ( theReply != 0 )
      {
        return theReply;
      }
      return new ReplyMessage( getId(), DEBUGGER_NO_ERROR );
    }

    virtual void setReplyMessage( ReplyMessage *aReply )
    {
      theReply = aReply;
    }

    virtual Byte * serialize( Length & aLength ) const;
};

/**
 *
 */
class ZORBA_DLL_PUBLIC RunMessage: public AbstractCommandMessage
{
  public:
    RunMessage();

    RunMessage( Byte * aMessage, const unsigned int aLength ); 

    virtual ~RunMessage();
};

/**
 * 
 */
class ZORBA_DLL_PUBLIC SuspendMessage: public AbstractCommandMessage
{
  public:
    SuspendMessage();
    
    SuspendMessage( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~SuspendMessage();
};

/**
 * 
 */
class ZORBA_DLL_PUBLIC ResumeMessage: public AbstractCommandMessage
{
  public:
    ResumeMessage();
    
    ResumeMessage( Byte * aMessage, const unsigned int aLength ); 
    
    virtual ~ResumeMessage();
};

/**
 * 
 */
class ZORBA_DLL_PUBLIC TerminateMessage: public AbstractCommandMessage
{
  public:
    TerminateMessage();

    TerminateMessage( Byte * aMessage, const unsigned int aLength ); 
    
    virtual ~TerminateMessage();
};

/**
 * 
 */
class ZORBA_DLL_PUBLIC DetachMessage: public AbstractCommandMessage
{
  public:
    DetachMessage();

    DetachMessage( Byte * aMessage, const unsigned int aLength ); 
    
    virtual ~DetachMessage();
};

/**
 * 
 */
class ZORBA_DLL_PUBLIC StepMessage: public AbstractCommandMessage
{
	protected:
		StepCommand theKind;

    bool isValidMessage() const;

    std::string getData() const;

	public:
	  StepMessage( const StepCommand aKind);
    
    StepMessage( Byte * aMessage, const unsigned int aLength ); 
    
    virtual ~StepMessage();

    StepCommand getStepKind() const;

    virtual Byte * serialize( Length &aLength ) const;
};

/**
 *
 */
class ZORBA_DLL_PUBLIC SetMessage: public AbstractCommandMessage
{
  protected:
    std::map<unsigned int, xqpString> theExprs;
    std::map<unsigned int, QueryLoc> theLocations;
    std::string getData() const;

  public:

    SetMessage();

    SetMessage( Byte * aMessage, const unsigned int aLength );

    void addExpr( unsigned int anId, xqpString &anExpr )
    {
      theExprs.insert( std::make_pair( anId,  anExpr ) );
      setLength( MESSAGE_HEADER_SIZE + getData().length() );
    }

    std::map<unsigned int, xqpString> getExprs()
    {
      return theExprs;
    }

    void addLocation( unsigned int anId, QueryLoc &aLocation )
    {
      theLocations.insert( std::make_pair( anId, aLocation ) );
      setLength( MESSAGE_HEADER_SIZE + getData().length() );
    }

    std::map<unsigned int, QueryLoc> getLocations()
    {
      return theLocations;
    }

    virtual ~SetMessage();

    virtual Byte * serialize( Length & aLength ) const;
};

/**
 *
 */
class ZORBA_DLL_PUBLIC ClearMessage: public AbstractCommandMessage
{
  protected:
    std::vector<unsigned int> theIds;
    std::string getData() const;

  public:
    ClearMessage();

    ClearMessage( Byte * aMessage, const unsigned int aLength ); 
    
    void addId( unsigned int id )
    {
      theIds.push_back( id );
      setLength( MESSAGE_HEADER_SIZE + getData().length() );
    }

    std::vector<unsigned int> getIds()
    {
      return theIds;
    }
 
    virtual ~ClearMessage();

    virtual Byte * serialize( Length & aLength ) const;
};

/**
 *
 */
class ZORBA_DLL_PUBLIC StartedEvent: public AbstractCommandMessage
{
  public:
    StartedEvent();
    
    StartedEvent( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~StartedEvent();
};

/**
 *
 */
class ZORBA_DLL_PUBLIC TerminatedEvent: public AbstractCommandMessage
{
  public:
    TerminatedEvent();
    
    TerminatedEvent( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~TerminatedEvent();
};

/**
 *
 */
class ZORBA_DLL_PUBLIC SuspendedEvent: public AbstractCommandMessage
{
  protected:
    QueryLoc theLocation;
    SuspensionCause theCause; 
    std::string getData() const;

  public:
    SuspendedEvent( const QueryLoc &aLocation, const SuspensionCause aCause = CAUSE_USER );
    
    SuspendedEvent( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~SuspendedEvent();

    virtual Byte * serialize( Length & aLength ) const;

    QueryLoc getLocation() const;

    SuspensionCause getCause() const;

};

/**
 *
 */
class ZORBA_DLL_PUBLIC ResumedEvent: public AbstractCommandMessage
{ 
  public:
    ResumedEvent();
    
    ResumedEvent( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~ResumedEvent();
};

/**
 *
 */
class ZORBA_DLL_PUBLIC EvaluatedEvent: public AbstractCommandMessage
{
  protected:
    xqpString theExpr;
    xqpString theError;
    std::list< std::pair<xqpString, xqpString> > theValuesAndTypes;
 
  public:
    EvaluatedEvent( int aId, xqpString anExpr, std::list<std::pair<xqpString, xqpString> > valuesAndTypes );

    EvaluatedEvent(  int aId, xqpString anExpr, xqpString anError );

    EvaluatedEvent( Byte * aMessage, const unsigned int aLength );

    virtual ~EvaluatedEvent();

    virtual Byte * serialize( Length & aLength ) const;
    
    xqpString getExpr() const;

    std::list<std::pair<xqpString, xqpString> > getValuesAndTypes() const;

    xqpString getError() const;

    void setId(Id aId);

  public: // this method is only public for testing purposes
    xqpString getData() const;
};

/**
 *
 */
class ZORBA_DLL_PUBLIC EvalMessage: public AbstractCommandMessage
{
  protected:
    xqpString theExpr;
    xqpString getData() const;

  public:
    EvalMessage( xqpString anExpr );

    EvalMessage( Byte * aMessage, const unsigned int aLength );

    virtual ~EvalMessage();

    virtual Byte * serialize( Length & aLength ) const;

    xqpString getExpr() const;
};

class ZORBA_DLL_PUBLIC ListCommand : public AbstractCommandMessage
{
protected:
  std::string theFilename;
  unsigned long theFirstLine;
  unsigned long theLastLine;
  std::string getData() const;

public:
  ListCommand(Byte * aMessage, const unsigned int aLength);
  ListCommand(std::string aFilename, unsigned long aFirstline,
    unsigned long aLastline);
  virtual ~ListCommand();

  virtual Byte* serialize(Length& aLength) const;

  std::string getFilename() const;
  unsigned long getFirstline() const;
  unsigned long getLastline() const;
};

class ZORBA_DLL_PUBLIC FrameMessage: public AbstractCommandMessage
{
  public:
    FrameMessage();

    FrameMessage(Byte* aMessage, const unsigned int aLength);
    
    virtual ~FrameMessage();
};

/**
 *
 */
class ZORBA_DLL_PUBLIC FrameReply: public ReplyMessage
{
  protected:
    std::stack< std::pair<std::string, QueryLoc> > theStack;
    xqpString getData() const;

  public:
    FrameReply(const Id anId, const ErrorCode aErrorCode,
                       std::stack< std::pair<std::string, QueryLoc> >  aStack);

    FrameReply(Byte* aMessage, const unsigned int aLength);

    virtual ~FrameReply(){}

    virtual Byte* serialize(Length& aLength) const;

    std::stack< std::pair<std::string, QueryLoc> > getStack() const
    {
      return theStack;
    }
};

/**
 *
 */
class ZORBA_DLL_PUBLIC VariableMessage: public AbstractCommandMessage
{ 
  public:
    VariableMessage(bool dataFlag = false);
    
    VariableMessage( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~VariableMessage();

    virtual bool hasToGetData() { return theDataFlag; }

  protected:
    bool theDataFlag;
};

class ZORBA_DLL_PUBLIC ListReply : public ReplyMessage
{
protected:
  std::string theString;
  std::string getData() const;

public:
  ListReply(const Id aId,
    const ErrorCode aErrorCode,
    const std::string& aCode);
  ListReply(Byte* aMessage, const unsigned int aLength);
  virtual ~ListReply();

  virtual Byte* serialize(Length &aLength) const;
  virtual ReplyMessage * getReplyMessage();
  std::string getString() const;
  void setString(std::string aString);
};

/**
 *
 */
class ZORBA_DLL_PUBLIC SetReply: public ReplyMessage
{
  private:
    std::map<unsigned int, QueryLoc> theBreakpoints;
    xqpString getData() const;

  public:
    SetReply(const Id anId, const ErrorCode aErrorCode);

    SetReply(Byte* aMessage, const unsigned int aLength);

    virtual ~SetReply();

    virtual Byte* serialize(Length &aLength) const;

    virtual ReplyMessage * getReplyMessage()
    {
      ReplyMessage * lReply =  new ReplyMessage( getId(), DEBUGGER_NO_ERROR );
      lReply->setData( getData() );
      return lReply;
    }

    void addBreakpoint(unsigned int anId, QueryLoc& aLocation);

    std::map<unsigned int, QueryLoc> getBreakpoints(){ return theBreakpoints; }
};
/**
 *
 */
class ZORBA_DLL_PUBLIC VariableReply: public ReplyMessage
{
  protected:
    std::map<xqpString, xqpString> theGlobals;
    std::map<xqpString, xqpString> theLocals;

    std::vector<std::list<std::pair<xqpString, xqpString> > > theGlobalData;
    std::vector<std::list<std::pair<xqpString, xqpString> > > theLocalData;
    bool theContainsData;

    xqpString getData() const;

  public:
    VariableReply( const Id anId, const ErrorCode aErrorCode, bool containsData = false );

    VariableReply( Byte * aMessage, const unsigned int aLength );

    virtual ~VariableReply();

    virtual Byte * serialize( Length &aLength ) const;

    virtual ReplyMessage * getReplyMessage()
    {
      ReplyMessage * lReply =  new ReplyMessage( getId(), DEBUGGER_NO_ERROR );
      lReply->setData( getData() );
      return lReply;
    }

    std::map<std::pair<xqpString, xqpString>, std::list<std::pair<xqpString, xqpString> > > getVariables() const; 

    std::map<std::pair<xqpString, xqpString>, std::list<std::pair<xqpString, xqpString> > > getLocalVariables() const;

    std::map<std::pair<xqpString, xqpString>, std::list<std::pair<xqpString, xqpString> > > getGlobalVariables() const;

    void addGlobal( xqpString aVariable, xqpString aType );
    void addGlobal( xqpString aVariable, xqpString aType, std::list<std::pair<xqpString, xqpString> > val);
    
    void addLocal( xqpString aVariable, xqpString aType );
    void addLocal( xqpString aVariable, xqpString aType, std::list<std::pair<xqpString, xqpString> > val);
};
}//end of namespace
#endif
