# DSA01 – Assignment 3 (CO3): Constructors, Destructors and Operator Overloading

This repository contains one folder for each of the seven questions in the supplied Assignment 3 PDF.

## Each task folder
- `code.cpp` – C++ implementation
- `output.txt` – output from compiling and running the program
- `screenshot.png` – console-output capture for reference
- `compile.txt` – compiler diagnostics

## Compiler
Prepared using g++ with C++17.

## Compile and run
```bash
g++ -std=c++17 -Wall -Wextra code.cpp -o program
```
Windows: `program.exe`
Linux/macOS: `./program`

## Task summary
1. **Task01:** Uses default, title-only and full-detail constructors, initializer lists, delegation, explicit and validation of negative copies.\n2. **Task02:** Implements deep-copy constructor, copy assignment, destructor, self-assignment protection and independent prescription copies.\n3. **Task03:** Allocates a 2D seat map dynamically, books/cancels seats, and demonstrates stack, block and heap lifetimes.\n4. **Task04:** Stores currency as integer paise and overloads arithmetic, comparison and stream output/input.\n5. **Task05:** Overloads prefix/postfix increment, comparisons and checked const/non-const playlist subscripting.\n6. **Task06:** Implements a dynamically allocated Text class with Rule of Three, concatenation, comparisons and stream output.\n7. **Task07:** Builds Complex from first principles and calculates series/parallel impedances with safe zero-division handling.\n
## Important submission checklist
The included files provide starter implementations and sample output evidence. The PDF also requires written analysis and experiments that are not fully represented by source code alone:
- Q1: constructor state diagrams, compiler-supplied default-constructor behaviour, `-Wreorder` demonstration, and `explicit` compile test.
- Q2: shallow-copy failure under AddressSanitizer, deep-copy memory diagram, Rule of Three, copy timing for 10/1,000/100,000 medicines.
- Q3: missing-delete sanitizer demonstration, allocation measurements for 10x20, 100x200 and 1,000x2,000 seats, memory layout and destructor order.
- Q4: input test, negative-money policy, readability comparison and 1,000,000-addition double comparison.
- Q5: prefix/postfix timing at -O0 and -O2, checked-index cost, and rollover tests.
- Q6: sanitizer evidence, copy counts and comparison with std::string for 100,000 concatenations.
- Q7: hand calculations for circuit impedances, comparison with std::complex<double>, and stated limitation.

Before submission, add your name, register number and actual compiler version. Compile and run each program on your own machine, capture genuine terminal screenshots if required, and record your own measurements. The included PNG files are generated console-output captures, not photographs of your local terminal. Commit progressively, at least one commit per task, as required by the PDF.

Repository name required by the assignment: `DSA01-<RegisterNumber>-Assignment3`.
