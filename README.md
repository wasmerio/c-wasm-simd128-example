# C++ Wasm SIMD 128 example

This repo is made to showcase how to emit Wasm SIMD 128 instructions from C++, and use it with [Wasmer](https://github.com/wasmerio/wasmer).

## Build

```bash
./build.sh
```

It will download the [WASI SDK 5](https://github.com/CraneStation/wasi-sdk/releases/tag/wasi-sdk-5) (the macOS or linux version, depending on your system).

## Run it!

You can run the SIMD version with [Wasmer](https://wasmer.io/):

```bash
wasmer run --backend=llvm --enable-simd build/particle-repel-simd.wasm
```

Or run the non-SIMD version

```bash
wasmer run --backend=llvm build/particle-repel.wasm
```

Or run the Native SIMD version

```bash
./build/particle-repel
```


After running it, the results should be something like:

```
Beginning simulation.
5.44089e-21
9.19434e-22
9.98077e-20
1.01414e-17
1.89481e-17
3.61239e-16
2.24645e-14
1.24237e-13
2.39859e-13
3.13435e-13
4.13311e-13
6.31935e-13
4.59395e-10
6.40114e-10
1.15545e-09
2.24414e-10
1.03695e-09
4.06071e-10
7.64414e-10
7.57652e-10
```

## Benchmarks

```
# Native
time ./build/particle-repel # 4.930 total

# Wasmer SIMD
time wasmer run --backend=llvm --enable-simd build/particle-repel-simd.wasm # 4.980 total

# Wasmer Non-SIMD
time wasmer run --backend=llvm build/particle-repel.wasm # 11.630 total
```
