# Numerical Conversion 🔢

<img width="749" height="405" alt="screen143733" src="https://github.com/user-attachments/assets/6108e1c2-3fdc-401f-861c-a3a92b8f4d13" />

A text-mode program written in C that converts numbers between **decimal,
binary, octal and hexadecimal**, through an interactive console interface.

Any base can convert to all the others — e.g. octal can be converted to
decimal, binary and hexadecimal, and the same applies to every other base.

## ✨ Features

- Full conversion matrix between all four number systems:
  - Decimal → Binary, Octal, Hexadecimal
  - Binary → Decimal, Octal, Hexadecimal
  - Octal → Decimal, Binary, Hexadecimal
  - Hexadecimal → Decimal, Binary, Octal
- Interactive console menu
- User input validation
- Handling of negative values *(adjust if applicable)*
- Lightweight, zero dependencies: uses only the C standard library

## 🛠️ Technologies

- Language: **C** ([C99 / C11])
- Libraries: C standard library (`stdio.h`, `stdlib.h`, etc.)

## ▶️ Build and run

Requires a C compiler such as GCC or Clang.

### Linux / macOS

```bash
gcc -Wall -o converter main.c
./converter
```

### Windows (MinGW)

```bash
gcc -Wall -o converter.exe main.c
converter.exe
```

## 🧩 Possible improvements

- [ ] Support for fractional numbers
- [ ] Conversion history
- [ ] Continuous conversion mode without returning to the menu

## tools used

- **[JDoodle](https://www.jdoodle.com/)**
