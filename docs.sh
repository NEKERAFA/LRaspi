#!/bin/bash

if [-d "docs" ]; then
    rm -rf docs
fi

mkdir -p docs/reference/topics/extra
mkdir -p docs/topics/extra

doxygen
ldoc .
pandoc README.md -f markdown -t html -s -o docs/index.html --metadata pagetitle="LRaspi: A Lua player for Raspberry Pi" 
cp extra/header.png docs/reference/topics/extra/header.png
cp extra/header.png docs/extra/header.png

