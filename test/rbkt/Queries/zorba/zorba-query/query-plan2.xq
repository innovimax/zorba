import module namespace zq = 'http://zorba.io/modules/zorba-query';

declare namespace resolver = 'http://zorba.io/modules/zorba-query/url-resolver';
declare namespace op = "http://zorba.io/options/features";
declare namespace f = "http://zorba.io/features";

declare function resolver:url-resolver($namespace as xs:string, $entity as xs:string)
{
  if($namespace = 'http://test')
  then "module namespace test = 'http://test'; declare function test:foo(){'foo'};"
  else ()
};

variable $queryID := zq:prepare-main-module(
  "import module namespace test = 'http://test'; test:foo()",
  resolver:url-resolver#2, ());


variable $query-plan := zq:query-plan($queryID); 

variable $queryID2 := zq:load-from-query-plan($query-plan, resolver:url-resolver#2, ());

zq:evaluate ($queryID2)
