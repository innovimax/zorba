import module namespace file = "http://www.zorba-xquery.com/modules/file";
import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";

import module namespace xqdg = "http://www.zorba-xquery.com/modules/internal/xqdoc-xhtml" at "xqdoc-xhtml.xq";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0" at "xqdoc-1.0.xsd";

declare copy-namespaces preserve, inherit;

(:~
 : This variable contains the relative paths to directories that contain example code fragments that are included
 :)
declare variable $examplePath  as xs:string* := ('test/rbkt/Queries/zorba','test/update/Queries','test/rbkt/ExpQueryResults/zorba','test/update/ExpectedTestResults');

(:~
 : This variable contains the modules directory path in the source directory
 :)
declare variable $modulesPath as xs:string external;

(:~
 : This variable contains the path where to generate the XQDoc
 :)
declare variable $xqdocBuildPath as xs:string external;

(:~
 : This variable contains the to the index.html main page
 :)
declare variable $indexHtmlPath as xs:string external;

declare variable $indexCollector := <modules/>;

(:~
 : This function generates the XQDoc XML for all the modules found in $modulesPath
 : and write the resulting XML documents in $targetPath. The hierarchy is preserved. 
 :
 : @param $modulePath where to search for modules recursively.
 : @param $targetPath where to generate the XQDoc XML documents.
 :)
declare sequential function local:generateXQDocXml($modulesPath as xs:string, $targetPath as xs:string) {
    for $file in file:files($modulesPath)
    let $filePath := concat($modulesPath, "/", $file)
    return
        if (file:is-directory($filePath))
        then
            let $newTargetPath := concat($targetPath, "/", $file)
            return local:generateXQDocXml($filePath, $newTargetPath)
        else if (matches($file, "\.xq$")) then (
            let $xqdoc := xqd:xqdoc(file:path-to-uri($filePath))
            let $moduleDoc := $xqdoc/xqdoc:xqdoc/xqdoc:module
            let $moduleName := $moduleDoc/xqdoc:name
            let $moduleUri := $moduleDoc/xqdoc:uri
            let $xqdocFileName := concat($targetPath, "/", $moduleName, ".xml")
            return
                try {
                    file:mkdirs($targetPath, false());
                    file:write($xqdocFileName, $xqdoc, <s method="xml" indent="yes" />/@*);
                    concat("
SUCCESS: ", $moduleUri, " (", $xqdocFileName, ")");
                } catch * ($error_code) {
                    concat("
FAILED: ", $moduleUri, " (", $xqdocFileName, ")")
                }
        )
        else ()
};

(:~
 : This function generates the XQDoc XHTML pages for all the XQDoc XML
 : documents found in $xqdocPath and writes the resulting pages to in
 : $targetPath. The hierarchy is preserved. 
 :
 : @param $xqdocPath where to search for XML XQDoc documents recursively.
 : @param $targetPath where to generate the XQDoc XHTML pages.
 :)
declare sequential function local:generateXQDocXhtml($xqdocPath as xs:string, $targetPath as xs:string, $pathToIndex as xs:string, $cssFileName as xs:string) {
    let $absoluteXqdocPath := concat($xqdocBuildPath, "/", $xqdocPath),
        $absoluteTargetPath := concat($xqdocBuildPath, "/", $targetPath)
    
    for $file in file:files($absoluteXqdocPath)
    let $filePath := concat($absoluteXqdocPath, "/", $file)
    return
        if (file:is-directory($filePath))
        then
            let $newXqdocPath := concat($xqdocPath, "/", $file),
                $newTargetPath := concat($targetPath, "/", $file),
                $newPathToIndex := concat("../", $pathToIndex)
            return local:generateXQDocXhtml($newXqdocPath, $newTargetPath, $newPathToIndex, $cssFileName)
        else if (matches($file, "\.xq\.xml$")) then (
            let $xqdoc := file:read-xml($filePath)/xqdoc:xqdoc
            let $moduleDoc := $xqdoc/xqdoc:module
            let $moduleName := $moduleDoc/xqdoc:name
            let $moduleUri := $moduleDoc/xqdoc:uri
            let $xhtmlFileName := replace($moduleName, "\.xq$", ".html"),
                $xhtmlFilePath := concat($absoluteTargetPath, "/", $xhtmlFileName)
            let $xhtml := xqdg:doc($xqdoc)
            return
                try {
                    let $fileRelativeToBuild := concat($targetPath, "/", $xhtmlFileName),
                        $fileRelativeToIndex := replace($fileRelativeToBuild, "^xhtml/", "")
                    return
                        local:collectModule($moduleDoc, $fileRelativeToIndex);

                    file:mkdirs($absoluteTargetPath, false());

                    local:configure-xhtml($xhtml, $pathToIndex, $cssFileName);

                    file:write($xhtmlFilePath, $xhtml, <s method="xhtml" indent="yes" />/@*);
                    concat("
SUCCESS: ", $moduleUri, " (", $xhtmlFilePath, ")");
                } catch * ($error_code) {
                    concat("
FAILED: ", $moduleUri, " (", $xhtmlFilePath, ")")
                }
        )
        else ()
};

declare sequential function local:collectModule ($module, $relativeFileName as xs:string) {
    let $moduleName := $module/xqdoc:name,
        $moduleUri := $module/xqdoc:uri
    return
        insert node <module uri="{$moduleUri/text()}" file="{$relativeFileName}" /> as last into $indexCollector;
    ();
};    

declare function local:getFilePath ($filename as xs:string) as xs:string*
{
  let $zorbaPath := replace($modulesPath,"/modules","")
  for $relPath in $examplePath
  let $path := concat($zorbaPath,'/',$relPath)
  let $test := file:files($path,concat("^",$filename,"$"),fn:true())[1]
  return
  if (fn:exists($test)) then
    $test
  else 
    ()
};

declare sequential function local:configure-xhtml ($xhtml, $pathToIndex as xs:string, $cssFileName as xs:string) {
    (: add a stylesheet :)
    let $cssPath := concat($pathToIndex, $cssFileName)
    return    
        replace value of node $xhtml/*:head/*:link/@href with $cssPath
    ;    
    (: replace the <test> nodes with eiter links to the actual files or inline the actual files based on the 'type' attribute value :)
    for $file in $xhtml//*:include
    let $type := $file/@type
    let $path := local:getFilePath($file/text())
    return block {
    (: at the moment there is no way to ship the files defined as links with the packages/installers
      if (matches($type, "link")) then 
        replace node $file with 
          <a href="{$path}">{$path}</a> 
      else :)if (matches($type, "inline")) then
        replace node $file with
          if (fn:exists($path)) then
            <pre> {$path}:<br />
            <pre class="fragment">{file:read-text($path)}</pre>
            </pre>
          else
            <pre class="fragment">No example matching pattern '{$file/text()}' was found. Please update 'examplePath' variable.</pre>
      else () 
    };
    (: replace the function type description with images :)
    let $xquSpec := "http://www.w3.org/TR/xquery-update-10/",
        $xqsSpec := "http://www.w3.org/TR/xquery-sx-10/#dt-sequential-function"
    let $imagesPath := concat($pathToIndex, "images/")
    for $typeTd in $xhtml//*:td
    where $typeTd/@class eq "type"
    let $type := $typeTd/text()
    return block {
        if (matches($type, "updating")) then
            replace node $typeTd/text() with
                <a href="{$xquSpec}" title="{$type}" target="_blank"><img src="{concat($imagesPath, "U.gif")}" /></a>
        else if (matches($type, "sequential")) then
            replace node $typeTd/text() with
                <a href="{$xqsSpec}" title="{$type}" target="_blank"><img src="{concat($imagesPath, "S.gif")}" /></a>
        else ();
    }
    ;
    $xhtml;
};


(:~
 : This function reads, updates and returns the new index.html.
 :
 : @param $xqdocPath where to search for XML XQDoc documents recursively.
 : @return the content of the new index.html
 :)
declare sequential function local:generateIndexHtml($indexPath as xs:string) as document-node() {
    let $indexHtmlDoc := file:read-xml($indexPath)
    return block {
        for $module in $indexCollector/module
        return
            insert nodes
                (<a href="{$module/@file}">{data($module/@uri)}</a>, <br />)
                 as last into $indexHtmlDoc/*:html/*:body;
        $indexHtmlDoc;
    }
};

(: generate the XQDoc XML for all the modules :)
let $xqdocXmlDir := concat($xqdocBuildPath, "/xml")
return
    if (file:mkdirs($xqdocXmlDir, false())) then
        local:generateXQDocXml($modulesPath, $xqdocXmlDir)
    else
        error()
;

(: generate the XQDoc XHTML for all the modules :)
let $absoluteXhtmlDir := concat($xqdocBuildPath, "/xhtml")
return
if (file:mkdirs($absoluteXhtmlDir, false())) then
    (: these paths are relative to the XQDoc build directory :)
    let $xqdocXmlDir := "xml",
        $xqdocXhtmlDir := "xhtml"
    (: this path is relative to $xqdocXhtmlDir :)
    let $cssFileName := "css/zorba.css"
    return
        local:generateXQDocXhtml($xqdocXmlDir, $xqdocXhtmlDir, "", $cssFileName)
else
    error()
;

let $doc := local:generateIndexHtml($indexHtmlPath)
return local:configure-xhtml($doc/*:html, "", "css/zorba.css")
;
