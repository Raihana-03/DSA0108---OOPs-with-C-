# DSA01 – Assignment 4 (CO4): Designing Reusable Class Hierarchies

## Repository contents
Each task folder contains:
- `code.cpp` – C++17 source code
- `output.txt` – output from the compiled program
- `screenshot.png` – generated image capture of the console output
- `compile.txt` – compilation command and status

## Tasks
1. **Task 1 – Class Design Review:** payroll hierarchy with an abstract `Staff` base class and overridden `pay()`.
2. **Task 2 – From Requirement to Hierarchy:** `Person`, `Student`, `Staff`, `TeachingAssistant`, and `ResearchScholar`; virtual inheritance resolves the diamond.
3. **Task 3 – Constructors and Member Classes:** initializer lists, `Address` and `Course` member objects, and construction/destruction order.
4. **Task 4 – Pointers to Derived Classes:** virtual dispatch, virtual destructor, smart pointers, and an explicit slicing demonstration.
5. **Task 5 – Pointers to Objects and `this`:** direct object, pointer, reference, dynamic allocation, method chaining, and highest-cart search.
6. **Task 6 – Vehicle Rental Fleet:** abstract `Vehicle` class, derived vehicle types, polymorphic rental charges, return/late charge, and an added `ElectricBus`.

## Build and run
Use a C++17 compiler such as g++:
```bash
g++ --version
g++ -std=c++17 -Wall -Wextra code.cpp -o program
./program
```
On Windows, run `program.exe` instead of `./program` if compiling with MinGW.

## Before submission
- Add your **name**, **register number**, and actual compiler/version details.
- Execute every program on your own computer and verify the output.
- The included `screenshot.png` files are generated console-output captures, not photographs/screenshots from your own terminal. Replace them with genuine screenshots if your faculty requires actual execution screenshots.
- The assignment also requires written evidence beyond code. Prepare and add a report containing: Task 1 diagnosis, UML diagram and design defence; Task 2 relationship analysis, virtual diamond explanation and access table; Task 3 construction/destruction traces and initializer-list experiment; Task 4 sanitizer report and prevention rules; Task 5 comparison of object access methods and vector alternative; Task 6 testable requirements, UML hierarchy, pseudocode, and alternative-design complexity analysis.
- The PDF requires progressive commits (at least one commit per task). Commit each task separately rather than uploading everything in one final commit.

Suggested repository name: `DSA01-<RegisterNumber>-Assignment4`.
