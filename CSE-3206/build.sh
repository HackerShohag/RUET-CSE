#!/bin/bash

# check if build exists
mkdir -p build

# configure environment
cmake -B build

# build target
make -C build
