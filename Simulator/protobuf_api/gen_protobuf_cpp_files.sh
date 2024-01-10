#!/bin/sh
rm -rf out/
mkdir out/
protoc --cpp_out=./out/ --proto_path=./proto ./proto/*.proto

for f in ./out/*.cc; do 
    mv -- "$f" "${f%.cc}.cpp"
done


