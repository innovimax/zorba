import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:centroid(<gml:Surface><gml:patches>
                <gml:PolygonPatch><gml:exterior>
                    <gml:LinearRing><gml:posList>1 1 2 2 3 4 2 4 1 1</gml:posList></gml:LinearRing>
                </gml:exterior></gml:PolygonPatch>
                <gml:PolygonPatch><gml:exterior>
                    <gml:LinearRing><gml:posList>10 10 20 15 30 40 20 40 10 10</gml:posList></gml:LinearRing>
                </gml:exterior></gml:PolygonPatch>
              </gml:patches></gml:Surface>
              )