# C++ Wasm SIMD 128 example

This repo is made to showcase how to emit Wasm SIMD 128 instructions from C++, and use it with [Wasmer](https://github.com/wasmerio/wasmer).

## Dependencies

This depends on the [wasi-sdk](https://github.com/CraneStation/wasi-sdk). If you don't already have it installed, you can build it:

```bash
git clone https://github.com/CraneStation/wasi-sdk.git
make
```

The default installation directory is `/opt/wasi-sdk` and you will need write permissions to that directory.

## Run it!

Build the example with:

```bash
/opt/wasi-sdk/bin/clang++ -msimd128 -O2 particle-repel.cc -o particle-repel.wasm -msimd128
```

and run it with Wasmer:

```bash
wasmer run --backend=llvm --enable-simd particle-repel.wasm
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
