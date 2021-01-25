#!/bin/bash
set -e
[ ! -d build ] && mkdir build
cmake -B build . ; make -C build
./build/tests
