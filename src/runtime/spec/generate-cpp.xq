declare namespace zorba="http://www.zorba-xquery.com";

import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "generate-utils.xq";

declare function local:get-iterators($XMLdoc) as xs:string
{
  string-join(for $iter in $XMLdoc//zorba:iterator return local:process-iterator($iter),$gen:newline)
};

declare function local:process-iterator($iter) as xs:string
{
  string-join(('// &lt;',$iter/@name,'&gt;',$gen:newline,
  local:serializable-class-versions($iter/@name),
  local:end-serializable-class-versions($iter/@name),

  (: generate the visitor if requested :)
  if(fn:not($iter/@generateAccept) or $iter/@generateAccept eq "true") 
  then
    local:generate-accept($iter/@name)
  else
    (),

  (: generate the destructor if requested :)
  if(fn:not($iter/@generateDestructor) or $iter/@generateDestructor eq "true") 
  then 
    local:generate-destructor($iter)
  else (),

  if (exists($iter/zorba:state))
  then
    (
    (: generate the state's init and reset functions if requested :)
    if (fn:not($iter/zorba:state/@generateInit) or $iter/zorba:state/@generateInit eq "true")
    then
      local:generate-init($iter) 
    else (),

    if (fn:not($iter/zorba:state/@generateReset) or $iter/zorba:state/@generateReset eq "true")
    then
      local:generate-reset($iter)
    else ()
    )
  else (),

  (: finish iterator implementation with a closing comment :)
  '// &lt;/',$iter/@name,'&gt;',$gen:newline,$gen:newline),'')
};

declare function local:generate-init-values($state) as xs:string
{
  string-join(($gen:newline,for $member in $state//zorba:member return 
  string-join(($gen:indent,string($member/@name),' = ',string($member/@defaultValue),';',$gen:newline),''))
  ,'')
};

declare function local:generate-destructor($iter) as xs:string
{
  fn:concat($iter/@name, "::~", $iter/@name, "() {}", $gen:newline, $gen:newline)
};

declare function local:generate-reset($iter) as xs:string
{
  string-join(($gen:newline,'void ',string($iter/@name),'State::reset(PlanState&amp; planState) {',$gen:newline,
  $gen:indent,'PlanIteratorState::reset(planState);',$gen:newline,
  local:generate-init-values($iter/zorba:state),'}',$gen:newline
  ),'')
};

declare function local:generate-init($iter) as xs:string
{
  string-join(($gen:newline,'void ',string($iter/@name),'State::init(PlanState&amp; planState) {',$gen:newline,
  $gen:indent,'PlanIteratorState::init(planState);',$gen:newline,
  local:generate-init-values($iter/zorba:state),'}',$gen:newline
  ),'')
};

declare function local:generate-accept($name as xs:string) as xs:string
{
  string-join(($gen:newline,'void ',$name,'::accept(PlanIterVisitor&amp; v) const {',$gen:newline,
  $gen:indent,'v.beginVisit(*this);',$gen:newline,$gen:newline,
  $gen:indent,'std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();',$gen:newline,
  $gen:indent,'std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();',$gen:newline,
  $gen:indent,'for ( ; lIter != lEnd; ++lIter ){',$gen:newline,
  $gen:indent,$gen:indent,'(*lIter)->accept(v);',$gen:newline,
  $gen:indent,'}',$gen:newline,$gen:newline,
  $gen:indent,'v.endVisit(*this);',$gen:newline,'}',$gen:newline),'')
};

declare function local:get-include($XMLdoc, $name) as xs:string*
{
  fn:concat(
    '#include "runtime/visitors/planiter_visitor.h"',
    $gen:newline, $gen:newline,
    '#include "', fn:replace($name, "_", "/"), '.h"',
    string-join(for $include in $XMLdoc//zorba:source/zorba:include[@form='Angle-bracket']
      return concat('#include <', $include/text(), '>'), $gen:newline
    ),
    string-join(for $include in $XMLdoc//zorba:source/zorba:include[@form='Quoted'] 
      return concat('#include "', $include/text(), '"'), $gen:newline
    )
  )
};

declare function local:serializable-class-versions($name as xs:string) as xs:string
{
  string-join(('const char* ',$name,'::class_name_str = "',$name,'";',$gen:newline,
  $name,'::class_factory<',$name,'>',$gen:newline,$name,'::g_class_factory;',$gen:newline,$gen:newline,
  'const serialization::ClassVersion ',$gen:newline,$name,'::class_versions[] =',
  '{{ 1, ',$gen:zorba_version,', ',string(not($gen:backward_compatible)),'}')
  ,'')
};

declare function local:end-serializable-class-versions($name as xs:string) as xs:string
{
  string-join(('};',$gen:newline,$gen:newline, 'const int ',$name,'::class_versions_count =',$gen:newline,
  'sizeof(',$name,'::class_versions)/sizeof(struct serialization::ClassVersion);',$gen:newline)
  ,'')
};

declare variable $input external;
declare variable $name as xs:string external;

string-join((gen:add-copyright(),
             local:get-include($input, $name),
             'namespace zorba {',
             local:get-iterators($input),
             '}')
             ,string-join(($gen:newline,$gen:newline),''))
