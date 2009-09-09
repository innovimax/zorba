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

import org.zorba.Zorba;
import org.zorba.XQuery;
import org.zorba.ResultIterator;
import org.zorba.Item;
import org.zorba.XmlDataManager;
import org.zorba.InMemoryStore;


public class Test_Zorba 
{

  static 
  {
    System.loadLibrary ( "zorba_api" );
  }

  static boolean example_1(Zorba aZorba)
  {
    XQuery lQuery = aZorba.compileQuery("1+2"); 
    System.out.println ( lQuery.execute() );

    return true;
  }

  static boolean example_2 ( Zorba aZorba )
  {
    XQuery lQuery = aZorba.compileQuery ("(1,2,3,4,5)" );

    ResultIterator lIterator = lQuery.iterator();
    lIterator.open();

    Item lItem = Item.createEmptyItem();
    while ( lIterator.next(lItem) ) 
    {
      System.out.println ( lItem.getStringValue () );
    }

    lIterator.close();
    lIterator.destroy();

    return true;
  }

  static boolean example_3 ( Zorba aZorba )
  {

    XQuery lQuery = aZorba.compileQuery("1 div 0"); 
    try 
    {
      System.out.println ( lQuery.execute () );
    }
    catch ( RuntimeException e ) 
    {
      System.out.println ( e.getMessage() );
      return true;
    }

    return false;
  }


  static boolean example_4 ( Zorba aZorba )
  {

    try 
    {
      XQuery lQuery = aZorba.compileQuery("for $x in (1, 2,");
      System.out.println ( lQuery.execute () );
    }
    catch ( RuntimeException e ) 
    {
      System.out.println ( e.getMessage () );
      return true;
    }

    return false;
  }

  static boolean example_5 ( Zorba zorba )
  {
    XmlDataManager dm = zorba.getXmlDataManager();
    dm.loadDocument("books.xml", "<books><book>Book 1</book><book>Book 2</book></books>");
    XQuery xquery = zorba.compileQuery("doc('books.xml')//book");
    System.out.println (  xquery.execute() );

    return true;
  }

  static boolean example_6 ( Zorba zorba )
  {
    XmlDataManager dm = zorba.getXmlDataManager();
    dm.loadDocument("books.xml", "<books><book>Book 1</book><book>Book 2</book></books>");
    XQuery xquery1 = zorba.compileQuery("insert node <book>Book 3</book> into doc('books.xml')/books");
    
    if (xquery1.isUpdateQuery() ) 
    {
      xquery1.applyUpdates();
    }
    
    XQuery xquery2 = zorba.compileQuery("doc('books.xml')//book");
    System.out.println ( xquery2.execute() );
    return true;
  }


  public static void main ( String argv[] )
  {
    InMemoryStore store = InMemoryStore.getInstance();
    Zorba zorba = Zorba.getInstance ( store );

    boolean res = false;

    System.out.println ("executing example 1" );
    res = example_1( zorba );
    if ( !res ) 
      System.exit ( 1 ); 

    System.out.println ( "executing example 2" );
    res = example_2 ( zorba );
    if (!res) 
      System.exit ( 1 ); 
  
    System.out.println ( "executing example 3" );
    res = example_3 ( zorba );
    if (!res) 
      System.exit ( 1 ); 
  
    System.out.println ( "executing example 4" );
    res = example_4 ( zorba );
    if (!res) 
      System.exit ( 1 ); 

    System.out.println ( "executing example 5" );
    res = example_5 ( zorba );
    if (!res) 
      System.exit ( 1 ); 

    System.out.println ( "executing example 6" );
    res = example_6 ( zorba );
    if (!res) 
      System.exit ( 1 ); 


    zorba.shutdown();
    InMemoryStore.shutdown ( store );

    return;
  } // main

} // class Test_Zorba
