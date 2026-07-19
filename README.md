# CPP_MODULES
This repository contains my C++ projects written at 42 School

![C++ Modules Overview](./header.png)

# C++ Modules (00 - 09)

![C++](https://img.shields.io/badge/Language-C++98-00599C?style=for-the-badge&logo=c%2B%2B)
![School 42](https://img.shields.io/badge/School-42-000000?style=for-the-badge&logo=42)

## 📖 Description

This repository contains solutions for the C++ Modules (00–09) curriculum at **School 42**.
The primary goal of these modules is to transition from procedural programming (C) to **Object-Oriented Programming (OOP)** while strictly adhering to the **C++98 standard**.

Key focuses include memory management, encapsulation, inheritance, polymorphism, exceptions, type casting, templates, and the Standard Template Library (STL). Starting from Module 02, all classes are designed in the **Orthodox Canonical Form**.

## 📂 Modules Overview

| Module | Topic | Key Concepts |
| :--- | :--- | :--- |
| **Module 00** | **Introduction to C++** | Namespaces, Classes, Member functions, stdio streams, Initialization lists. |
| **Module 01** | **Memory & Pointers** | Memory allocation (new/delete), References vs Pointers, Switch statement, File I/O. |
| **Module 02** | **Ad-hoc Polymorphism** | Operator overloading, Orthodox Canonical Form (OCF), Fixed-point numbers. |
| **Module 03** | **Inheritance** | Inheritance chains, Access specifiers, Diamond problem (ClapTrap -> ScavTrap/FragTrap). |
| **Module 04** | **Subtype Polymorphism** | Abstract classes, Interfaces, Virtual functions & Destructors, Deep copy. |
| **Module 05** | **Repetition & Exceptions** | Try/Catch blocks, Custom exceptions, Nested classes. |
| **Module 06** | **C-style vs C++ Casts** | static_cast, dynamic_cast, reinterpret_cast, const_cast, RTTI. |
| **Module 07** | **C++ Templates** | Function templates, Class templates, Template specialization. |
| **Module 08** | **STL Containers & Algorithms** | std::vector, std::list, std::map, std::stack, iterators, and generic algorithms (std::find, std::sort). |
| **Module 09** | **Advanced STL** | Data parsing, Move Semantics concepts, RPN, PmergeMe, BitcoinExchange. |

## 🛠️ Usage

Each exercise has its own `Makefile`. To run a specific program, navigate to the directory and compile:

```bash
cd cpp_m04/ex00
make
./animal
```