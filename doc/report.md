# Cyclic List (STL-style Container)

## Project Goal

Develop a custom container in C++ (no later than C++20) implementing a cyclic doubly-linked list, following the style and behavior of STL containers such as std::list. The container must support:

- A complete iterator system;
- C++20 standard concepts;
- Error handling;
- Operator support;
- Clean, modular code;
- Unit tests with Google Test;
- Integration-ready for CI.

---

## Implemented Components

### 1. Node<T>
- Represents a single list element.
- Stores T data, pointers to next and prev elements.
- Constructors:
  - Basic constructor initializing data and linking to itself.
  - Full constructor linking to specified next and prev nodes.

### 2. List<T>
A cyclic doubly-linked list that maintains:

- head_: pointer to the first element;
- size_: current number of elements.

Supported operations:
- push_back, push_front
- pop_back, pop_front
- clear, empty, size
- begin, end, cbegin, cend

Error Handling:
- Empty list deletion throws std::underflow_error.

### 3. Iterator<T, IsConst>
- A unified bidirectional iterator with const/non-const support.
- Compliant with std::bidirectional_iterator concept.
- Operators: ++, --, *, ->, ==, !=
- Compatible with range-based for loops and STL algorithms.


| Requirement                         | Status |
| ----------------------------------- | ------ |
| STL-style interface                 | ✅ Yes  |
| Full iterator system                | ✅ Yes  |
| Support for standard C++20 concepts | ✅ Yes  |
| Error handling                      | ✅ Yes  |
| Operator overloading                | ✅ Yes  |
| Clean, modular code                 | ✅ Yes  |
| Unit tests                          | ✅ Yes  |
| CI-ready structure                  | ✅ Yes  |

## Testing (Google Test)
20 unit tests are provided, covering:
 • Basic operations: insertion, deletion, clearing;
 • Iterators: forward/backward traversal, post/pre increment;
 • Const correctness: read-only iteration and protection;
 • Exceptions: underflow on empty list;
 
## Summary
A robust, type-safe, STL-compatible cyclic list container was implemented, fully compliant with modern C++ standards. It supports key functionalities required for real-world use and can be easily extended, tested, and integrated.
