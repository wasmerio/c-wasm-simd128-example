#!/bin/bash

# Install wasienv
curl https://raw.githubusercontent.com/wasienv/wasienv/master/install.sh | sh

mkdir -p build-wasm
cd build-wasm
wasimake cmake ..
cd ..
make -C build-wasm
