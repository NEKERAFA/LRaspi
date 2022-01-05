#!/bin/bash

if [ ! -d "build" ]; then
    ./build.sh
fi

cd build
./lraspi
cd ..

