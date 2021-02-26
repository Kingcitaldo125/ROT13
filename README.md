# ROT13
## Description

From [Wikipedia](https://en.wikipedia.org/wiki/ROT13):
**ROT13** (**"rotate by 13 places"**, sometimes hyphenated **ROT-13**) is a simple letter [substitution cipher](https://en.wikipedia.org/wiki/Substitution_cipher) that replaces a letter with the 13th letter after it in the alphabet. ROT13 is a special case of the [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher) which was developed in ancient Rome.

This repo seeks to retain different programming language implementations of that cypher.

## Languages Supported

The following languages are currently being supported:

- **C++**(C++ 11)
- **Python**(Python 3)

## Usage

### C++

Simply run the `main.cpp` source file though a compiler that is C++11 compliant, then run the executable.
E.x:

**Linux**

```
g++ --std=c++11 -o out main.cpp
./out
```

**Windows**

I had used MSVC++ (Visual Studio 2017) to compile the source.
I have not tried compiling using MinGW.
For more information on Visual Studio, click this [link](https://visualstudio.microsoft.com/).

### Python

Simply open a terminal/command prompt window, and type the following:

`python main.py this is a test string`

The output should appear like the following:

```
Result: guvf vf n grfg fgevat
Original: this is a test string

```

## License

See the [LICENSE](https://github.com/Kingcitaldo125/ROT13/blob/main/LICENSE) file for details
