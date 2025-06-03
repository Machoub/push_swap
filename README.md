# 🔄 push_swap – 42 Project

A sorting algorithm challenge using only a limited set of stack operations.  
The goal is to sort a list of integers with the least possible number of operations, using two stacks and a restricted set of instructions.

---

## 📌 Description

The program takes a list of integers as arguments and sorts them in ascending order using two stacks (`a` and `b`).  
It must output the list of operations used to perform the sort.  
Only a limited set of operations is allowed, such as push, swap, rotate, and reverse rotate.

---

## 🧠 Allowed Operations

| Operation | Description                          |
|-----------|--------------------------------------|
| `sa`      | Swap the first 2 elements of stack a |
| `sb`      | Swap the first 2 elements of stack b |
| `ss`      | `sa` and `sb` at the same time       |
| `pa`      | Push top of stack b to stack a       |
| `pb`      | Push top of stack a to stack b       |
| `ra`      | Rotate stack a (first → last)        |
| `rb`      | Rotate stack b                       |
| `rr`      | `ra` and `rb` at the same time       |
| `rra`     | Reverse rotate stack a               |
| `rrb`     | Reverse rotate stack b               |
| `rrr`     | `rra` and `rrb` at the same time     |

---

## 🔧 Build

```
make
## 🔧 Build

```
make
```

---

## ▶️ Usage
```
./push_swap [list of integers]
```
Example
```
./push_swap 3 2 1
```
Output:

```
pb
sa
pa
```

---

## 🚫 Error Handling
Non-integer arguments

Duplicates

Integers out of bounds (INT_MIN, INT_MAX)

## 🧠 What I Learned
Building a custom sorting algorithm adapted to constraints

Managing doubly linked lists and stacks

Implementing and optimizing greedy logic

Handling input parsing, validation, and memory management

Writing efficient code with a focus on performance and optimization

---


