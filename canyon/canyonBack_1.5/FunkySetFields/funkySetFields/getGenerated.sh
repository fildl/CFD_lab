#! /bin/sh

echo "To be used on a machine that HAS the right bison (not for the general public)"

GFILE=GeneratedFiles
FROM=Make/$WM_OPTIONS

for i in location.hh position.hh ValueExpressionLexer.C ValueExpressionParser.C ValueExpressionParser.tab.hh location.hh position.hh stack.hh
do
    cp $FROM/$i $GFILE
done
