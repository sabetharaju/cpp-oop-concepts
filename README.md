# C++ OOP Fundamentals

A set of self-contained C++ programs demonstrating the four core pillars of Object-Oriented Programming, plus key class mechanics that commonly come up alongside them. Each file builds on a shared `Employee` theme, evolving in complexity from a basic class to full runtime polymorphism.

## Programs

| File | Concept | What It Demonstrates |
|---|---|---|
| [class.cpp](./class.cpp) | Classes & Objects | Class definition, constructor overloading, object arrays |
| [encapsulation.cpp](./encapsulation.cpp) | Encapsulation | Private data, public getters/setters, input validation |
| [abstraction.cpp](./abstraction.cpp) | Abstraction | Pure virtual function, abstract base class |
| [inheritance.cpp](./inheritance.cpp) | Inheritance | Base/derived classes, `protected` access, constructor initializer lists |
| [polymorphism.cpp](./polymorphism.cpp) | Polymorphism | Virtual functions, runtime dispatch via base class pointers, virtual destructors |
| [copy_constructor_destructor.cpp](./copy_constructor_destructor.cpp) | Object Lifecycle | Copy constructor vs. parameterized constructor, destructor order, the `this` pointer |
| [static_members.cpp](./static_members.cpp) | Static Members | Class-level shared state, static member functions |
| [operator_overloading.cpp](./operator_overloading.cpp) | Operator Overloading | Overloading `==`, `+`, and `<<` (via `friend`) for a custom class |

## Key Design Notes

- **Abstraction** (`abstraction.cpp`): `AbstractEmployee` declares `askForPromotion()` as a pure virtual function (`= 0`), making it an abstract class that cannot be instantiated directly — any concrete derived class must implement it.
- **Polymorphism** (`polymorphism.cpp`): `Employee*` base pointers correctly resolve to `Developer::work()` or `Teacher::work()` at runtime. This file also includes a **virtual destructor** on both the abstract base and `Employee` — required because objects are used polymorphically through base pointers, otherwise deleting a derived object through a base pointer is undefined behavior.
- **Operator Overloading** (`operator_overloading.cpp`): `operator==` and `operator+` are marked `const`, which resolves a real C++20 compiler warning around reversed-comparison ambiguity (`b == a` synthesized from `a == b`) — confirmed by compiling with `g++` and observing the warning disappear after the fix.

## Compiling & Running

Each file is independent and self-contained:

```
g++ <filename>.cpp -o <filename>.exe
./<filename>.exe
```

All 8 programs were compiled and run with `g++` (MinGW-w64/UCRT64) and verified to produce correct output.

## Why This Repo

This collection was built to apply core C++ OOP concepts hands-on rather than just reading about them — each file was written, compiled, tested, and in a few cases corrected after review (e.g., fixing default-private inheritance to explicit `public`, adding a missing virtual destructor, and resolving a real compiler warning around `const`-correctness).
