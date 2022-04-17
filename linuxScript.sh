#!/bin/bash
DIR="/out/build/"
if [ ! -d "$DIR" ]; then
  mkdir -p out/build/
fi
cd out/build/ && cmake -S ../../ -B . && make &&  cd ../../

if [[ -f ./LanguageDeterminer ]]; then
   echo "--------Success build--------"
   ./LanguageDeterminer
   exit 0
else
   echo "--------Failure build-------"
   rm -r out
   echo "--------dir <out> was removed--------"
   exit 1
fi
exit 0
