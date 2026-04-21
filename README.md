# Student Management System 🎓

A comprehensive C++ application demonstrating advanced **Object-Oriented Programming (OOP)** principles. This system manages student records efficiently using a hierarchical class structure.

## 🚀 Features

- **Hierarchical Design**: Implements base classes and multiple levels of inheritance.
- **Dynamic Polymorphism**: Uses virtual functions and base class pointers for runtime behavior.
- **Encapsulation**: Secures student data using private members and friend functions.
- **Interactive Interface**: Easy-to-use CLI for inputting and viewing student details.
- **Grade Calculation**: Automated grading logic based on performance metrics.

## 🛠️ Technical Implementation

- **Language:** C++
- **OOP Concepts Used:**
  - **Inheritance:** `Person` → `Student` → `GraduateStudent`
  - **Polymorphism:** Method overriding and virtual destructors.
  - **Abstraction:** Design of base classes for shared attributes.
  - **Friend Functions:** Specialized access for grading logic.

## 💻 Getting Started

### Prerequisites
Ensure you have a C++ compiler installed (GCC, Clang, or MSVC).

### Compilation
Use any standard C++ compiler to build the project:

```bash
g++ student.cpp -o student_system
```

### Running the App
Execute the compiled binary:

```bash
./student_system
```

## 📂 Project Structure

| Component | Description |
| :--- | :--- |
| `Person` | Base class containing name and age. |
| `Student` | Derived class adding roll number and marks. |
| `GraduateStudent` | Specialized class for post-graduate students. |
| `showGrade` | Logic for assessing student performance globally. |

---
*Created as a demonstration of C++ OOP capabilities.*
