#! /bin/sh

echo "Preparing run to avoid usage of bison"

GFILE=GeneratedFiles

for i in location.hh position.hh ValueExpressionLexer.C ValueExpressionParser.C ValueExpressionParser.tab.hh location.hh position.hh stack.hh
do
    cp $GFILE/$i .
done

sed -i -e "s/ValueExpressionParser.yy/ValueExpressionParser.C/g" Make/files
sed -i -e "s/ValueExpressionLexer.ll/ValueExpressionLexer.C/g" Make/files
