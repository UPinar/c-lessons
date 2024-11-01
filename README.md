<h1 align="center"> CLessons </h1>

### [C Language](https://github.com/UPinar/CLessons/tree/master/c_language) 
  - C language characteristics
  - C Standarts
  - C program
  - compiler - derleyici
  - tokenizing(atomlarina ayirmak)
  - number systems - sayı sistemleri
  - characters
  - header files
  - seperate compilation model
  - external reference

### [Basic Types](https://github.com/UPinar/CLessons/tree/master/basic_types)
  - basic types of C language
  - declaration(bildirim) and definition(tanimlama)
  - storage duration
  - scope (kapsam - faaliyet alani)
  - naming - naming conventions

### [Functions](https://github.com/UPinar/CLessons/tree/master/functions)
  - function definition syntax
  - return statement
  - function call
  - test functions (query, predicate)
  - `<ctype.h>` module
  - function prototype(s) | function declaration
  - function wrappers

### [Input Output](https://github.com/UPinar/CLessons/tree/master/input_output)
  - standart C library
  - call(pass) by value, call(pass) by reference
  - constants (sabitler) 
  - Input & Output Operations

### [Operators](https://github.com/UPinar/CLessons/tree/master/operators)
  - operator priority, precedence (operatör önceliği)
  - operator associativity (öncelik yönü)
  - arithmetic operators
  - side effect (yan etki)
  - maximal munch (en uzun atom)
  - comparison operators
  - logical operators
  - short circuit behaviour (kısa devre davranışı)
  - assignment operators
  - sequence point (yan etki noktası)
  - comma operator (virgül operatörü)
  - ternary operator (koşul operatörü)
  - `sizeof` operator

### [Control Statements](https://github.com/UPinar/CLessons/tree/master/control_statements)
  - `if` statement
  - `while` statement
  - n kere dönen döngü idiyomu (loop idiom that loops n times)
  - how to get out of a loop (bir döngüden nasıl çıkılır?)
  - infinite loop (sonsuz döngü)[while]
  - `break` statement
  - `<conio.h>` header for Microsoft Compiler `_getch()` and `_getche()` functions
  - `continue` statement
  - `do while` statement
  - `for` statement
  - infinite loop idiom(sonsuz döngü)[for]
  - `switch` statement
  - `goto` statement
  - nested loops

### [Preprocessor](https://github.com/UPinar/CLessons/tree/master/preprocessor)
  - `#include`
  - `#define`
  - object-like macros
  - function-like(functional) macros
  - comparison between functional macros and functions
  - preprocessor operators
  - conditional compiling (koşullu derleme)
  - multiple inclusion guard
  - `#undef`
  - predefined symbolic constants
  - `#error`
  - `#line`
  - `#pragma`

### [Random Number Generation](https://github.com/UPinar/CLessons/tree/master/random_number_generation)
  - `rand()` function
  - `srand()` function
  - randomize idiom

### [Type Conversions](https://github.com/UPinar/CLessons/tree/master/type_conversions)
  - assignment type conversions (implicit)
  - arithmetic type conversions (implicit)
  - type-cast operator

### [Arrays](https://github.com/UPinar/CLessons/tree/master/arrays)
  - information about data structures, algorithms, big O notation
  - arrays
  - array decay (array to pointer conversion)
  - arrays initialization
  - designated initializer(C99)
  - sorting algorithms 
  - bubble sort
  - merge algorithm 
  - binary search
  - multi-dimensional arrays

### [String](https://github.com/UPinar/CLessons/tree/master/string)
  - NTBS (null terminated byte stream)
  - string concatenate - append
  - remove copy algorithm
  - count algorithm
  - count_if algorithm

### [Pointers](https://github.com/UPinar/CLessons/tree/master/pointers)
  - address of operator (adres operatörü)
  - dereferencing (indirection) operator (içerik operatörü)
  - pointer arithmetics
  - subscript operator (köşeli parantez operatörü)
  - diziler üzerinde işlem yapan fonksiyonlar
  - pointer idioms
  - comparison between addresses(pointers)
  - functions that returns pointer(adres döndüren fonksiyonlar)
  - valid and invalid pointers
  - `NULL` - null pointer 
  - more pointer idioms
  - pointer arrays
  - pointer to pointer
  - `const` correctness in pointers
  - `void` pointers
  - function pointers
  - function pointer arrays
  
### [`const` Keyword](https://github.com/UPinar/CLessons/tree/master/const_keyword)
  - why using `const` keyword
  - pointers & `const`
  
### [Type Alias(`typedef`) Declarations](https://github.com/UPinar/CLessons/tree/master/typedef_declarations)
  - `typedef` declarations
  - type aliases in standart library

### [Standart Library](https://github.com/UPinar/CLessons/tree/master/standart_library)
  - string operations in `<string.h>` module
    - `strlen` 
    - `strchr` 
    - `strrchr`
    - `strstr`
    - `strpbrk`
    - `strcpy` and `strncpy`
    - overlapped blocks and `restrict` keyword
    - `strcat` and `strncat`
    - string comparison(yazıların karşılaştırılması)
      - lexicographical compare
      - `strcmp` and `strncmp`
    - `strspn` and `strcspn`
    - `strtok`
  - generic functions in `<string.h>` module
    - `memset`
    - `memcpy` and `memmove`
    - `memchr`
    - `memcmp`
      - Endianness
  - `qsort` and `bsearch` in `<stdlib.h>` module
  - conversion functions between strings and numbers in `stdlib.h` module
    - `atoi` and `atof` and `atol` and `atoll`
    - `strtol` and `strtoll` and `strtoul` and `strtoull`
    - `strtof` and `strtod` and `strtold`
  - formatted input-output functions in `stdio.h` module
    - `printf` and `sprintf`
    - `scanf` and `sscanf`
  - process termination functions in `stdlib.h` module
    - `exit` and `atexit`
    - `abort`
  
### [String Literals](https://github.com/UPinar/CLessons/tree/master/string_literals)

### [Dynamic Memory Management](https://github.com/UPinar/CLessons/tree/master/dynamic_memory_management)
  - `malloc`
  - `free`
  - `calloc`
  - `strdup`