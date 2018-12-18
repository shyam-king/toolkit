# StringTokenizer

## Introduction
This is a C++ library that implements a StringTokenizer class similar to the one available in Java.

## Installation

### Prerequisites
CMake
git (for cloning repository or download as a zip)

### For Ubuntu Linux and similar distros 

#### Build it yourself

1) Clone the toolkit repository if you haven't done already
```
git clone https://github.com/shyam-king/toolkit
```

2) Change into String-Tokenizer/source directory
```
cd String-Tokenizer/source
```

3) Run CMake
```
cmake . 
```

4) Install
```
make
sudo make install
```

#### Use existing binary
The binaries available in bin are built for linux x86_64

1) copy libStringTokenizer.a to /usr/lib and install the header in /usr/include
```
sudo cp bin/libStringTokenizer.la /usr/lib
sudo cp source/StringTokenizer.h /usr/include
```

## Usage

Use the StringTokenizer by including the header

```c++
#include<StringTokenizer.h>
```
Compile by including the flag -lStringTokenizer. For example,
```
g++ -lStringTokenizer -o main main.cpp
```
