# Changelog

All notable changes to this project are recorded here.

The format follows [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and the
project uses [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- `include/stackvm/version.hpp` defining `STACKVM_VERSION_MAJOR`, `STACKVM_VERSION_MINOR`,
  `STACKVM_VERSION_PATCH` and `STACKVM_VERSION_STRING`.
- `include/stackvm/opcode.hpp` and `include/stackvm/vm.hpp` scaffolding the `Opcode` enum
  and the `VM` class, declarations only.
- `src/opcode.cpp` and `src/vm.cpp` with stub definitions for `opcode_name` and the `VM`
  constructor, destructor and `run`.
- `tests/main.cpp` with a test runner entry point that reports failure count through the
  process exit code.
