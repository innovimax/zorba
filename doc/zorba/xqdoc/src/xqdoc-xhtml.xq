module namespace xhtml = "http://www.zorba-xquery.com/modules/internal/xqdoc-xhtml";

import module namespace util = "http://www.zorba-xquery.com/zorba/util-functions";

declare namespace xqdoc = "http://www.xqdoc.org/1.0";

declare function xhtml:doc($xqdoc)
{
    <html>{
        xhtml:header($xqdoc),
        xhtml:body($xqdoc)
    }</html>
};

declare function xhtml:header($xqdoc)
{
    <head>
        <title>Documentation for {xhtml:module-uri($xqdoc)}</title>
        <link rel="stylesheet" type="text/css" href="" />
    </head>
};

declare function xhtml:body($xqdoc)
{
    <body>
        <h1>{xhtml:module-uri($xqdoc)}</h1>
        {
            xhtml:module-description($xqdoc/xqdoc:module),
            xhtml:module-variables($xqdoc/xqdoc:variables),
            xhtml:module-function-summary($xqdoc/xqdoc:functions),
            xhtml:module-functions($xqdoc/xqdoc:functions)
        }
    </body>
};

declare function xhtml:module-uri($xqdoc) as xs:string
{
    $xqdoc/xqdoc:module/xqdoc:uri/text()
};

declare function xhtml:parameters($comment) {
    let $params := $comment/xqdoc:param
    return
        if (exists($params)) then (
            <div class="subsubsection">Parameters:</div>,
            for $param in $params
            let $text := string($param/node()[1])
            return
                if (starts-with($text, "$")) then
                    let $name := substring-before($text, " ")
                    let $description := (substring-after($text, " "), subsequence($param/node(), 2))
                    return
                        <table class="parameter"><tr>
                            <td class="parameter"><code>{$name}</code></td>
                            <td class="parameter"> - </td>
                            <td class="parameter">{$description}</td></tr>
                        </table> 
                else
                    ()
        ) else ()
};

declare function xhtml:errors($comment) {
    let $errors := $comment/xqdoc:error
    return
        if (exists($errors)) then (
            <div class="subsubsection">Errors</div>,
            for $error in $errors
            return
                <table class="parameter">
                    <tr>
                        <td class="parameter">{$error/node()}</td>
                    </tr>
                </table> 
        ) else ()
};

declare function xhtml:annotations($comment) {
    let $annotations := $comment/xqdoc:*[not((local-name(.) = ("description", "param", "return", "error")))]
    return
        for $annotation in $annotations
        let $annName := local-name($annotation)
        return ( 
            <div class="subsubsection">{
              concat(upper-case(substring($annName, 1, 1)), substring($annName, 2), ":")
            }</div>,    
(: ********************************************************** :)
(: this hack should be replaced with links everywhere in text :)
            (: replace the @see nodes that start with http:// with HTML a tag :)
            if(($annName = "see") and fn:count($annotation/node()) eq 1 and fn:starts-with(fn:lower-case($annotation/node()), "http://")) then
              <p class="annotationText">{<a href="{$annotation/node()}" target="_blank">{$annotation/node()}</a>}</p>
(: ********************************************************** :)
            else
              <p class="annotationText">{$annotation/node()}</p>
        )
};


declare function xhtml:return($comment) {
    let $return := $comment/xqdoc:return
    return
        if (exists($return)) then (
            <div class="subsubsection">Returns:</div>,
            <p class="annotationText">{$return/node()}</p>
        ) else ()
};

declare function xhtml:description($comment)
{
     <p>{
        if ($comment/xqdoc:description) then
            $comment/xqdoc:description/node()
        else
            "No description available."
     }</p>
};

declare function xhtml:module-description($module)
{
    (<div class="section"><span class="section" id="module_description">Module Description</span></div>,
     xhtml:description($module/xqdoc:comment),
     xhtml:annotations($module/xqdoc:comment))
};

declare function xhtml:module-variables($variables)
{
    if($variables/xqdoc:variable) then
        (<div class="section"><span class="section" id="variables">Variables</span></div>,
        for $variable in $variables/xqdoc:variable
        return (<div class="subsection">{$variable/xqdoc:uri}</div>,
                xhtml:description($variable/xqdoc:comment),
                xhtml:annotations($variable/xqdoc:comment))
        )
    else
        ()
};

declare function xhtml:module-function-summary($functions)
{
    <div class="section"><span class="section" id="function_summary">Function Summary</span></div>,
    if(count($functions/xqdoc:function)) then
        <table class="funclist">{
            for $function in $functions/xqdoc:function
            let $name := $function/xqdoc:name/text(),
                $signature := $function/xqdoc:signature/text(),
                $param-number := count(tokenize($signature, "\$")) - 1
            order by $name, $param-number 
            return
                let $type := normalize-space(substring-after(substring-before($signature, "function"), "declare")),
                    $isExternal := ends-with($signature, "external"),    
                    $paramsAndReturn :=
                        let $searchCrit := concat(":", $name)
                        return
                            if ($isExternal)
                                then normalize-space(substring-before(substring-after($signature, $searchCrit), "external"))
                                else normalize-space(substring-after($signature, $searchCrit))
                return
                    <tr>
                        <td class="type">{$type}</td>
                        <td>
                            <tt><a href="#{$name}-{$param-number}">{$name}</a>{$paramsAndReturn}</tt>
                        </td>
                    </tr>
        }</table>
    else
        <p>No functions declared.</p>
};

declare function xhtml:module-functions($functions) {
    if(count($functions/xqdoc:function)) then (
        <div class="section"><span class="section" id="functions">Functions</span></div>,
        for $function in $functions/xqdoc:function
        let $name := $function/xqdoc:name/text(),
            $signature := $function/xqdoc:signature/text(),
            $param-number := count(tokenize($signature, "\$")) - 1,
            $comment := $function/xqdoc:comment
        return (
            <div class="subsection" id="{$name}-{$param-number}">{$name}</div>,
            <pre class="signature">{xhtml:split-function-signature($signature)}</pre>,
            xhtml:description($comment),
            xhtml:parameters($comment),
            xhtml:return($comment),
            xhtml:errors($comment),
            xhtml:annotations($comment),
            <hr />)                
         )
    else ()
};

declare function xhtml:split-function-signature($signature as xs:string) {
    let $line1 := substring-before($signature, "(")
    let $rest := substring-after($signature, "(")
    let $params :=
        (: if the function has parameter :)
        if (matches($rest, "\$")) then
            let $tmp := substring-before($rest, ") as ")
            return 
                (: if we don't have a return type specified :)
                if ($tmp eq "") then
                    (: en external function declaration :)
                    if (ends-with($rest, ") external")) then
                        substring-before($rest, ") external")
                    (: no external function :)
                    else
                        $rest
                (: the return type is specified :)
                else
                    $tmp
        (: no parameters :)
        else
            ""
    let $after := substring-after($signature, concat($params, ")"))
    return (
        concat($line1, " ("),
        <br />,
        for $param at $pos in tokenize($params, "\$")
        where $pos > 1
        return (
            concat("            $", normalize-space($param)),
            <br/>                    
        ),
        concat(")", $after)
    )
};
