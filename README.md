<p align="center"><img width=20% src="https://i.ibb.co/BswF1vN/logo.png"></p>
<p align="center"><img width=50% src="https://i.ibb.co/z54BFpf/text-logo.png"></p>

<p align="center">
  <img alt="language-badge" src="https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-yellow.svg">
  <img alt="travis-ci-badge" src="https://travis-ci.org/Ikirame/NovumEngine.svg?branch=master">
  <img alt="license-badge" src="https://img.shields.io/badge/License-MIT-blue.svg">
</p>

##

NovumEngine is a tiny OpenGL rendering engine wrote in C++. The design goal of this engine is to provide an API usable easily without an advanced knowledge of OpenGL to render graphical scenes.

## Getting started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

This project requires packages. If you are on Linux or macOS you can download this packages directly from your package manager. Otherwise, if you are on Windows you can download the packages from the official websites.

* CMake (https://cmake.org/)
* Git (https://git-scm.com/)
* Compiler
  - Linux (gcc/clang)
  - Windows (Microsoft Visual C++)
  - MacOS (gcc/clang)

### Installation

* Cloning

```bash
# --recursive flag to clone submodules recursively
git clone --recursive https://github.com/Ikirame/NovumEngine.git

# If you have forgotten the --recursive flag 
cd NovumEngine
git submodule update --init
```

* Building

```bash
cd NovumEngine
mkdir build
cd build

# Linux
cmake ..

# MacOS
cmake -G "Xcode" ..

# Windows (32bits && 64bits)
cmake -G "Visual Studio 16" ..
cmake -G "Visual Studio 16 Win64" ..
```

# Usage

In progress...

# Contributing

In progress...

