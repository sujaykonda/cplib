# cplib – Competitive Programming Library

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

`cplib` is a lightweight, modular C++ library designed to accelerate competitive programming by providing efficient implementations of commonly used algorithms, data structures, and utilities. It is organized for easy use and quick integration into contest solutions.

## Features

- **Modular Structure**: Organized into headers for data structures, graph algorithms, math utilities, string algorithms, and more.
- **Single-file Expansion**: Use [`exp.py`](exp.py) to merge all required headers into a single file for easy submission.
- **Optimized Implementations**: Fast and reliable code for typical competitive programming tasks.
- **Easy Integration**: Just include the relevant headers or expand to a single file for contests.

## Directory Structure

- [`general.h`](general.h): General utilities and template helpers.
- [`random.h`](random.h): Random number generators.
- [`bs.h`](bs.h): Binary search utilities.
- [`gen.h`](gen.h): Code generation utilities.
- [`exp.py`](exp.py): Python script for single-file expansion.

### Subdirectories

- [`ds/`](ds/): Data structures (BIT, segment trees, sparse tables, etc.)
- [`graph/`](graph/): Graph algorithms (DSU, flows, SCC, trees, etc.)
- [`math/`](math/): Math utilities (modular arithmetic, geometry, hashing, polynomials, etc.)
- [`strings/`](strings/): String algorithms (matching, suffix arrays, etc.)

## Usage

### 1. Direct Include

Include the required header(s) in your C++ solution:

```cpp
#include <cplib/general.h>
#include <cplib/ds/bit.h>
#include <cplib/graph/flow.h>
```

### 2. Single-file Expansion (Recommended for Contests)

Use [`exp.py`](exp.py) to generate a single cpp file (submit.cpp) containing all dependencies to submit to your online judge:

```bash
python3 exp.py merged.cpp
```

## License

This library is released under the [MIT License](https://opensource.org/licenses/MIT)