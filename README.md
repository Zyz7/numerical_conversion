# Numerical Conversion 🔢

<img width="724" height="295" alt="Captura de pantalla de 2026-11-12 09-16-48" src="https://github.com/user-attachments/assets/a6eeb691-1602-427c-b6f6-26717e422182" />

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
gcc -o converter main.c -lm
./converter
```

### Windows (MinGW)

```bash
gcc -o converter.exe main.c
converter.exe
```

## 🧩 Possible improvements

- [ ] Support for fractional numbers
- [ ] Conversion history
- [ ] Continuous conversion mode without returning to the menu

## 🛠️ Tools used

- **[JDoodle](https://www.jdoodle.com/)**
