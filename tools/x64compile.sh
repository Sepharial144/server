#!/bin/sh

cmake . -Bbuild -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j