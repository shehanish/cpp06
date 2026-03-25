<h1 align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" width="100" />
  <br>
  C++ Module 06
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B98-blue?style=for-the-badge&logo=c%2B%2B" />
  <img src="https://img.shields.io/badge/Concept-Type%20Casting-blueviolet?style=for-the-badge" />
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge" />
</p>

---

## 📖 Introduction

This module is dedicated to the study of **Type Casting** in C++. It covers the different ways to convert data between types, moving away from C-style casts to the more explicit and safer C++ casts: `static_cast`, `dynamic_cast`, `reinterpret_cast`, and `const_cast`.

## 🛠️ Exercises

### [ex00: Conversion of scalar types](ex00/)
The foundational casting exercise.
- **Goal**: Create a class that takes a string representation of a C++ scalar type (char, int, float, double) and converts it to its actual type, then casts it to the other three.
- **Concepts**: Handling special values like `nan`, `inf`, and using `static_cast` for safe conversions between basic types.

### [ex01: Serialization](ex01/)
Bit-level data preservation.
- **Goal**: Implement a way to serialize a pointer to a data structure into an `uintptr_t` and deserialize it back.
- **Concepts**: Using `reinterpret_cast` to treat memory as raw data and back to objects without loss of information.

### [ex02: Identify real type](ex02/)
Runtime Type Information (RTTI) without `<typeinfo>`.
- **Goal**: Correctly identify the underlying class type of a pointer or reference to a `Base` class (A, B, or C).
- **Concepts**: Using `dynamic_cast` to safely downcast in an inheritance hierarchy and distinguishing between pointer casting (returns NULL on failure) and reference casting (throws an exception).

## 📝 Learning Objectives

- **`static_cast`**: Standard conversions between related types.
- **`reinterpret_cast`**: Low-level bit reinterpretation.
- **`dynamic_cast`**: Safe downcasting in inheritance hierarchies with polymorphic bases.
- **`const_cast`**: Adding or removing the `const` qualifier.
- Understanding **Implicit vs Explicit** conversions.

## 🚀 Usage

1. Navigate to an exercise folder:
   ```bash
   cd ex02
   ```
2. Build the project:
   ```bash
   make
   ```
3. Run the executable:
   ```bash
   ./identify
   ```

---

<p align="center">
  <i>Part of the 42 C++ Pool. Developed by shkaruna.</i>
</p>
