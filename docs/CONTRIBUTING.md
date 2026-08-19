# Contributing

## Building

You need a MinGW-w64 g++ with C++17 and GNU make. On MSYS2 that's the `ucrt64` toolchain.

```
make            # default build, produces build/stackvm.exe
make debug      # -O0 -g
make release    # -O2 -DNDEBUG
make clean
```

Object files and their generated dependency files go under `build/`, mirroring the layout
of `src/`. Nothing in `build/` is tracked.

## Folder layout

```
include/stackvm/   public headers, one folder per subsystem
src/               implementation, mirrors include/stackvm/ folder for folder
tests/             tests, same subsystem structure again
docs/              these notes
```

Headers are `.hpp`, sources are `.cpp`. A header at `include/stackvm/gc/mark.hpp` has its
implementation at `src/gc/mark.cpp`. That mapping isn't a suggestion — the Makefile walks
`src/` on its own, and anyone reading the tree expects the two sides to line up.

Helpers that aren't meant to be included from outside a subsystem don't belong in the
public header folder. Put them next to the `.cpp` files in `src/<subsystem>/`.

Split a file by responsibility once it grows past a few hundred lines, rather than letting
one translation unit collect everything.
