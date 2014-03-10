import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "foo",
        "$baseType" : "decimal",
        "$minExclusive" : 10,
        "$maxExclusive" : 11 (: must be > 10 :)
      }
    ]
  }

let $instance := 10.5

return jsd:validate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
