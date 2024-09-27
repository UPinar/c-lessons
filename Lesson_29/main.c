#include <stdio.h>

/*
                          ============
                          | Pointers |
                          ============        
*/

/*
  - Pointer, means address.

  - In C, addresses are divided into two categories;
    1. Object Pointers    (nesnelerin adresleri)
    2. Function Pointers  (fonksiyonların adresleri)
*/

/*
  - expressions(ifade) have data type, value category and value.
  - some expression's data type is address.

  - farklı türlerden değişkenlerin adresleri olan ifadeler 
    farklı türden ifadeler.
      double türden bir nesnenin adresinin türü(double*)ile
      int türden bir nesnenin adresinin türü(int*) farklıdır.

  - x, T türünden bir değişken(variable) olsun, eğer bir ifade(expression)
    x değişkeninin adresi anlamına geliyorsa, bu ifadenin türü, T* olarak
    ifade edilir.

    int     -> int*
    double  -> double*
    char    -> char*
    T       -> T*

  - in a system(x86(x32) - x64), all object pointers sizes are same.

  int*    -> pointer to int 
  double* -> pointer to double
  long*   -> pointer to long

  - int* ptr;  
    ptr değişkeninin değeri(value), 
    int türden bir nesnenin(object) adresi
*/

/*
  float* ptr;  -> there are 3 tokens in this decla

  float -> keyword
  *     -> declarator
  ptr   -> identifier
*/

/*
  "int* p;" is a declaration statement not an expression.

  - if a token(*) in a declaration is used for 
  declaring the type of an object, it's a declarator.

  - eğer bir token(*) bir bildirimde(declaration) bir varlığın(objects)
  türünü(data type) belirtmek için kullanılıyorsa, bu bir deklaratördür.
*/

/*
  int main(void){
    int* p;

    *p = 0;  // "*p" is an expression so (*) token is an operator.
  }
*/

/*
  int main(void){
    printf("sizeof(char) = %zu\n", sizeof(char));
    // output -> sizeof(char) = 1
    printf("sizeof(char*) = %zu\n", sizeof(char*));
    // output -> sizeof(char*) = 8 

    printf("sizeof(short) = %zu\n", sizeof(short));
    // output -> sizeof(short) = 2
    printf("sizeof(short*) = %zu\n", sizeof(short*));
    // output -> sizeof(short*) = 8

    printf("sizeof(int) = %zu\n", sizeof(int));
    // output -> sizeof(int) = 4
    printf("sizeof(int*) = %zu\n", sizeof(int*));
    // output -> sizeof(int*) = 8

    printf("sizeof(long) = %zu\n", sizeof(long));
    // output -> sizeof(long) = 4
    printf("sizeof(long*) = %zu\n", sizeof(long*));
    // output -> sizeof(long*) = 8

    printf("sizeof(long long) = %zu\n", sizeof(long long));
    // output -> sizeof(long long) = 8
    printf("sizeof(long long*) = %zu\n", sizeof(long long*));
    // output -> sizeof(long long*) = 8

    printf("sizeof(float) = %zu\n", sizeof(float));
    // output -> sizeof(float) = 4
    printf("sizeof(float*) = %zu\n", sizeof(float*));
    // output -> sizeof(float*) = 8

    printf("sizeof(double) = %zu\n", sizeof(double));
    // output -> sizeof(double) = 8
    printf("sizeof(double*) = %zu\n", sizeof(double*));
    // output -> sizeof(double*) = 8
  }
*/

/*
  int foo(void);

  int main(void){
    int x = 10;
    int a[10] = { 0 };


    34;       
    // "34" is an expression, its data type is int
    // "34" is an RValue expression 
    
    x;        
    // "x" is an expression, its data type is int
    // "x" is an LValue expression

    x + 12;   
    // "x + 12" is an expression, its data type is int
    // "x + 12" is an RValue expression

    a[3];     
    // "a[3]" is an expression, its data type is int
    // "a[3]" is an LValue expression

    foo();    
    // "foo()" is an expression, its data type is int
    // "foo()" is an RValue expression
  }
*/

/*
  int foo(void);
  int* bar(void);

  int main(void){
    int x = 10;
    int a[10] = { 0 };
    int* ptr = a;
    int* pa[5];


    &x;     // "&x" is an expression,     its data type is int*
    a;      // "a" is an expression,      its data type is int*
    a + 3;  // "a + 3" is an expression,  its data type is int*   
    ptr;    // "ptr" is an expression,    its data type is int*
    bar();  // "bar()" is an expression,  its data type is int*
    pa[2];  // "pa[2]" is an expression,  its data type is int*
  }
*/

/*
  int main(void){
    int* p1, p2, p3;
    // Those declarations are same as below

    int* p1;
    int p2;
    int p3;
  }
*/

/*
  int main(void){
    int x, y[3], z, t[10];
    // Those declarations are same as below

    int x;
    int y[3];
    int z;
    int t[10];
  }
*/

/*
  int main(void){
    int* p1, p2[10], p3, *p4;
    // Those declarations are same as below

    int* p1;
    int p2[10];
    int p3;
    int* p4;
  }
*/

/*
  int main(void){
    int x[5], *y, *z[4];
    // Those declarations are same as below

    int x[5];
    int* y;
    int* z[4];
  }
*/

/*
  int* gp;            
  // global pointer variable (static storage duration)

  void func(float* fptr); 
  // function's parameter pointer variable (automatic storage duration)


  int main(void){
    int* p;           
    // local pointer variable (automatic storage duration)

    static int* sp;   
    // static local pointer variable (static storage duration)
  }
*/

/*
  int g;        // zero initialized (static storage duration)

  int main(){
    int x;      // defining without initialization (garbage value)
    int y = 10; // defining with initialization

    static int z; // zero initialized (static storage duration)
  }
*/

/*
  int* gp;  // null pointer - (static storage duration)

  int main(void){
    int* p;   // defining without initialization (garbage value)

    static int* sp;  // null pointer - (static storage duration)
  }
*/

/*
  int main(void){
    // int* p = init_expr;
    // init_expr should be an address of an int object

    // p = expr;
    // expr should be an address of an int object
  }
*/

/*
  int main(void){
    int* p;
    int x, y;

    x = 10;
    x = 20;
    // we can change the value of x(int variable)

    p = &x;
    p = &y;
    // we can change the value of p(pointer variable)
  }
*/

/*
  Pointer related operators
  --------------------------
  1. priority level           []    subscript / index operator
  1. priority level           ->    member selection (arrow) operator
  2. priority level           &     address of operator
  2. priority level           *     dereferencing (indirection) operator  

  2. priority level is right associative


  &x       address of (unary prefix) operator
  a & b    bitwise AND (binary infix) operator  

  *p       dereferencing (unary prefix) operator
  a * b    multiplication (binary infix) operator
*/

/*
              -----------------------------------------
              | address of operator (adres operatörü) |
              -----------------------------------------
*/

/*
  - operand must be an LValue expression.
*/

/*
  int main(void){
    &5;       // syntax error
    // error: lvalue required as unary '&' operand

    int x = 6;
    &(x + 5); // syntax error
    // error: lvalue required as unary '&' operand

    &x;       // VALID

    int a[4];
    &a[2];    // VALID

    &+x;      // syntax error
    // error: lvalue required as unary '&' operand
  }
*/

/*
  int main(void){
    int x = 6;
    &x;      // "&x" is an expression, it's data type is int*

    short y = 5;
    &y;      // "&y" is an expression, it's data type is short*
  }
*/

/*
  int main(void){
    int x = 6;
    int y = 56;

    int* ptr = &x;  // initialization
    ptr = &y;       // assignment
  }
*/

/*
  int main(void){
    int x = 5, *p = &x;
    // That line is same as below

    int x = 5;
    int* p = &x;
  }
*/

/*
  int main(void){
    int x = 5;
    int* p1 = &x;
    int* p2 = p1;
    // Those lines are same as below

    int x = 5, *p1 = &x, *p2 = p1;

    // p1 and p2 are pointing the same object(x)
  }
*/

/*
  int main(void){
    int a[5] = { 0 };
    int b[5] = { 0 };

    int* p = a;   
    // "a" expression becomes &a[0] (array decay)
    // int* p = &a[0];  

    p = b;        
    // "b" expression becomes &b[0] (array to pointer conversion)
    // p = &b[0];
  }
*/

/*
  int main(void){
    int* p;
    int x = 10;

    p = x;   // legal in C but gcc compiler gives syntax error
    // error: assignment to 'int *' from 'int' 
    // makes pointer from integer without a cast

    p = (int*)x;
    // warning: cast to pointer from integer of different size
  }
*/

/*
  int main (void){
    int* p;
    double dval = 4.5;

    p = &dval;  
    // legal in C but gcc compiler gives syntax error
    // error: assignment to 'int *' from 
    // incompatible pointer type 'double *' 

    p = (int*)&dval;  // valid
  }
*/

/*
  int main(void){
    int x = 10;

    &x;  // "&x" is RValue expression

    &(&x);  // syntax error
    // error: lvalue required as unary '&' operand
  }
*/

/*
  // variables addresses cannot be changed in programs run time.
  // değişkenlerin adresleri programın çalışma zamanında değiştirilemez.

  int main(void){
    int x = 10;
    int y = 20;
    int* p = &x;

    &x = &y;  // syntax error
    //  error: lvalue required as left operand of assignment
  }
*/

/*
  int main(void){
    int a[10] = { 0 };

    a;    // "a" is LValue expression
    &a;   // "&a" is RValue expression


    // a =         -> becomes &a[0]
    // &a[0] =
    // L value to R value conversion
  }
*/

/*
  L value
    - modifiable L value
    - non-modifiable(unmodifiable) L value 
*/

/*
  int main(void){
    int a[10] = { 0 };
    a;    // "a" is non-modifiable LValue  

    const int x = 10;
    x;    // "x" is non-modifiable LValue
  }
*/

/*
  int main(void){
    int a[10] = { 0 };

    sizeof(&a[0]);  // "&a[0]" is an expression, its data type is int*
    
    printf("%zu\n", sizeof(&a[0]));   // output -> 8
    printf("%zu\n", sizeof(int*));    // output -> 8

    printf("%zu\n", sizeof(a));       // output -> 40
    // array decay is not happening here
    printf("%zu\n", sizeof(int[10])); // output -> 40
  }
*/

/*
  // for pointer expressions %p format specifier is being used.

  int main(void){
    int x = 10;
    int a[] = { 1, 2, 3, 4, 5 };
    int* ptr = &x;
    int* pa = a;

    printf("&x    = %p\n", &x);    
    printf("ptr   = %p\n", ptr);   

    printf("a     = %p\n", a);     
    printf("&a[0] = %p\n", &a[0]); 
    printf("pa    = %p\n", pa);    

    // output ->
    //  &x    = 0000006D5A3FFC3C
    //  ptr   = 0000006D5A3FFC3C
    //  a     = 0000006D5A3FFC20
    //  &a[0] = 0000006D5A3FFC20
    //  pa    = 0000006D5A3FFC20
  }
*/

/*
  int main(void){
    int x = 6;
    int* p = &x;

    // p'nin değeri x'in adresi,  p x'i gösteriyor
    // p's value is address of x, p points to x

    // x and p are variables 
    // x and p both have addresses
  }
*/

/*
  int main(void){
    int x = 6;
    int* ptr = &x;

    printf("&x  = %p\n", &x);   // output -> &x  = 0000008A2DDFFD2C
    printf("ptr = %p\n", ptr);  // output -> ptr = 0000008A2DDFFD2C

    printf("&ptr = %p\n", &ptr);  // output -> &ptr = 0000008A2DDFFD20
  }
*/

/*
  int main(void){
    int x = 6;
    int* ptr = &x;

    // ptr is a pointer, x is a pointee
  }
*/


/*
      ------------------------------------------------------------
      | dereferencing (indirection) operator (içerik operatörü)  |
      ------------------------------------------------------------
*/

/*
  *operand (unary prefix) operator
  - dereferencing operator's operand must be an address.

  - içerik operatörü operandı olan adresteki nesneye erişim sağlar.
    *address -> nesne
    
  - içerik operatörünün operandı hangi nesnenin adresi ise, 
    oluşturulan ifade o nesnenin kendisidir.
    *&x  -> x
*/

/*
  int main(void){
    int x = 6;
    *x;  // syntax error
    // error: invalid type argument of unary '*' (have 'int')
  }
*/

/*
  int main(void){
    int x = 6;

    *&x;    // valid
    *(&x);  // valid
    // Those 2 lines are equivalent
    // & and * operators are same priority level and right associative
  }
*/

/*
  int main(void){
    int x = 6;
    int* p = &x;
    int a[5] = { 0 };

    *p;       // VALID, "p" expressions type is int*

    *a;       // VALID, "a" expressions type is int* -> &a[0]
    *&a[0];   // VALID
    // Those 2 lines are equivalent
  }
*/

/*
  int main(void){
    int x = 6;
    printf("x = %d\n", x);   // output -> x = 6

    *&x = 99;
    printf("x = %d\n", x);   // output -> x = 99

    ++*&x;
    printf("x = %d\n", x);   // output -> x = 100
    // ++, * and & operators are same priority level and 
    // they both right associative
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //  push rbp
  //  mov rbp, rsp  
  //  mov DWORD PTR [rbp-4], 6
  //  mov DWORD PTR [rbp-4], 99 
  //  mov eax, DWORD PTR [rbp-4]
  //  add eax, 1
  //  mov DWORD PTR [rbp-4], eax
  //  mov eax, 0
  //  pop rbp
  //  ret
*/

/*
  int main(void){
    int a[] = { 10, 20, 30 };
    *a = 777;
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-12], 10    : a[0] = 10
  //    mov DWORD PTR [rbp-8], 20     : a[1] = 20
  //    mov DWORD PTR [rbp-4], 30     : a[2] = 30
  //    mov DWORD PTR [rbp-12], 777   : *&a[0] = 777
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  - arr bir dizi olmak üzere 
      arr[0] 
    yazmak ile 
      *arr 
    yazmak aynı anlama gelir.

  - içerik operatörü ile oluşturulan geçerli tüm ifadeler 
    nesne gösterdikleri için LValue expression'dır.
*/

/*
  int main(void){
    int x = 6;
    int* p = &x;

    printf("x = %d\n", x);   // output -> x = 6

    *p = 99;
    printf("x = %d\n", x);   // output -> x = 99

    ++*p;
    printf("x = %d\n", x);   // output -> x = 100
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-12], 6       : x = 6
  //    lea rax, [rbp-12]               : rax = &x  :  [rbp-12] = &x
  //    mov QWORD PTR [rbp-8], rax      : p = &x    :  [rbp-8] = &p
  //    mov rax, QWORD PTR [rbp-8]      : rax = p
  //    mov DWORD PTR [rax], 99         : *p = 99
  //    mov rax, QWORD PTR [rbp-8]      : rax = p
  //    mov eax, DWORD PTR [rax]        : eax = *p
  //    lea edx, [rax+1]                : edx = *p + 1
  //    mov rax, QWORD PTR [rbp-8]      : rax = p
  //    mov DWORD PTR [rax], edx        : *p = edx(*p + 1)
  //    mov eax, 0
  //    pop rbp
  //    ret

  //  LEA — Load Effective Address  
  //  lea rax, [rbp-12]   -> LEA r64,mem
  // https://www.felixcloutier.com/x86/lea
*/

/*
  int main(void){
    int x = 3;
    int* p1 = &x;
    int* p2 = p1;
    int* p3 = p2;

    printf("x = %d\n", x);  // output -> x = 3 

    ++*p1;
    ++*p2;
    ++*p3;

    printf("x = %d\n", x);  // output -> x = 6
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-28], 3       : x = 3
  //    lea rax, [rbp-28]               : rax = &x  :  [rbp-28] = &x  
  //    mov QWORD PTR [rbp-8], rax      : p1 = &x   :  [rbp-8] = &p1
  //    mov rax, QWORD PTR [rbp-8]      : rax = p1
  //    mov QWORD PTR [rbp-16], rax     : p2 = p1   :  [rbp-16] = &p2
  //    mov rax, QWORD PTR [rbp-16]     : rax = p2
  //    mov QWORD PTR [rbp-24], rax     : p3 = p2   :  [rbp-24] = &p3
  //    mov rax, QWORD PTR [rbp-8]      : rax = p1
  //    mov eax, DWORD PTR [rax]        : eax = *p1
  //    lea edx, [rax+1]                : edx = *p1 + 1
  //    mov rax, QWORD PTR [rbp-8]      : rax = p1
  //    mov DWORD PTR [rax], edx        : *p1 = edx(*p1 + 1)
  //    mov rax, QWORD PTR [rbp-16]     : rax = p2
  //    mov eax, DWORD PTR [rax]        : eax = *p2
  //    lea edx, [rax+1]                : edx = *p2 + 1
  //    mov rax, QWORD PTR [rbp-16]     : rax = p2
  //    mov DWORD PTR [rax], edx        : *p2 = edx(*p2 + 1)
  //    mov rax, QWORD PTR [rbp-24]     : rax = p3
  //    mov eax, DWORD PTR [rax]        : eax = *p3
  //    lea edx, [rax+1]                : edx = *p3 + 1
  //    mov rax, QWORD PTR [rbp-24]     : rax = p3
  //    mov DWORD PTR [rax], edx        : *p3 = edx(*p3 + 1)
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void){
    int x = 3;
    int y = 67;

    int* ptr;
    ptr = &x;
    *ptr = 4555;
    ptr = &y;
    *ptr = 4555;

    printf("x = %d\n", x);  // output -> x = 4555
    printf("y = %d\n", y);  // output -> y = 4555
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-12], 3       : x = 3     :  [rbp-12] = &x
  //    mov DWORD PTR [rbp-16], 67      : y = 67    :  [rbp-16] = &y
  //    lea rax, [rbp-12]               : rax = &x  :  [rbp-12] = &x
  //    mov QWORD PTR [rbp-8], rax      : ptr = &x  :  [rbp-8] = &ptr
  //    mov rax, QWORD PTR [rbp-8]      : rax = ptr  
  //    mov DWORD PTR [rax], 4555       : *ptr = 4555
  //    lea rax, [rbp-16]               : rax = &y  :  [rbp-16] = &y
  //    mov QWORD PTR [rbp-8], rax      : ptr = &y  :  [rbp-8] = &ptr
  //    mov rax, QWORD PTR [rbp-8]      : rax = ptr
  //    mov DWORD PTR [rax], 4555       : *ptr = 4555
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void){
    int x = 10;
    int y = 20;
    int* p1 = &x;
    int* p2 = &y;

    *p1 *= 100;
    *p2 /= 5;

    printf("x = %d\n", x);  // output -> x = 1000
    printf("y = %d\n", y);  // output -> y = 4
  }
*/

/*
    int main(void){
      int x = 10;
      int y = 20;
      int* p1 = &x;
      int* p2 = &y;

      printf("x = %d\n", x);  // output -> x = 10
      *p1 = *p2;    // x = y;
      printf("x = %d\n", x);  // output -> x = 20
    }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-20], 10        : x = 10    :  [rbp-20] = &x
  //    mov DWORD PTR [rbp-24], 20        : y = 20    :  [rbp-24] = &y
  //    lea rax, [rbp-20]                 : rax = &x  :  
  //    mov QWORD PTR [rbp-8], rax        : p1 = &x   :  [rbp-8] = &p1
  //    lea rax, [rbp-24]                 : rax = &y  :  
  //    mov QWORD PTR [rbp-16], rax       : p2 = &y   :  [rbp-16] = &p2
  //    mov rax, QWORD PTR [rbp-16]       : rax = p2
  //    mov edx, DWORD PTR [rax]          : edx = *p2
  //    mov rax, QWORD PTR [rbp-8]        : rax = p1
  //    mov DWORD PTR [rax], edx          : *p1 = *p2
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void){
    int x = 10;
    int y = 20;
    int* p1 = &x;
    int* p2 = &y;

    int* ptemp = p1;
    p1 = p2;
    p2 = ptemp;
    // swap p1 and p2, p1 points to y, p2 points to x

    ++*p1;
    --*p2;

    printf("x = %d\n", x);  // output -> x = 9
    printf("y = %d\n", y);  // output -> y = 21
  }
*/

/*
  // call by value 

  void foo(int a){
    a = 999;
  }

  int main(void){
    int x = 10;
    printf("x = %d\n", x);  // output -> x = 10

    foo(x);
    printf("x = %d\n", x);  // output -> x = 10
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  foo:
  //    push rbp                        
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-4], edi      : a = edi     :  a = 10
  //    mov DWORD PTR [rbp-4], 999      : a = 999     :  a = 999
  //    nop
  //    pop rbp
  //    ret
  //  main:
  //    push rbp                        
  //    mov rbp, rsp                    
  //    sub rsp, 16                     
  //    mov DWORD PTR [rbp-4], 10       : x = 10
  //    mov eax, DWORD PTR [rbp-4]      : eax = x       :  eax = 10
  //    mov edi, eax                    : edi = eax     :  edi = 10
  //    call foo                        : foo(x)  
  //    mov eax, 0
  //    leave
  //    ret

  // different stack frames rbp's are different in foo and main
  // rdi is first caller save register
*/

/*
  // call by reference

  void foo(int* a){
    *a = 999;
  }

  int main(void){
    int x = 10;
    printf("x = %d\n", x);  // output -> x = 10

    foo(&x);
    printf("x = %d\n", x);  // output -> x = 999
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  foo:
  //    push rbp
  //    mov rbp, rsp
  //    mov QWORD PTR [rbp-8], rdi    : a = rdi       :  a = &x
  //    mov rax, QWORD PTR [rbp-8]    : rax = a
  //    mov DWORD PTR [rax], 999      : *a = 999      :  x = 999
  //    nop
  //    pop rbp
  //    ret
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    sub rsp, 16
  //    mov DWORD PTR [rbp-4], 10     : x = 10
  //    lea rax, [rbp-4]              : rax = &x      
  //    mov rdi, rax                  : rdi = rax     :  rdi = &x
  //    call foo
  //    mov eax, 0
  //    leave
  //    ret
*/

/*
  void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  int main(void){
    int a = 5;
    int b = 10; 
    printf("a = %d, b = %d\n", a, b);   // output -> a = 5, b = 10

    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);   // output -> a = 10, b = 5

    int* p1 = &a;
    int* p2 = &b;
    swap(p1, p2);
    printf("a = %d, b = %d\n", a, b);   // output -> a = 5, b = 10
  }
*/

/*
  void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  int main(void){
    int a[] = {111, 222, 333};
    int b[] = {999, 888, 777};
    printf("a[0] = %d, b[0] = %d\n", a[0], b[0]);
    // output -> a[0] = 111, b[0] = 999

    swap(a, b);
    // swap(&a[0], &b[0]);
    printf("a[0] = %d, b[0] = %d\n", a[0], b[0]);
    // output -> a[0] = 999, b[0] = 111
  }
*/

/* 
  - if a function will change the value of a variable, 
    the address of the variable should be passed to the function.
    i.e swap function

    Why we need to change the variable ?
*/

/*
  #define PI 3.14159265358979323846

  double get_circle_area_1(double radius)
  {
    return PI * radius * radius;
  }

  void get_circle_area_2(double radius, double* p_area)
  {
    *p_area = PI * radius * radius;
  }

  int main(void)
  {
    double radius = 5.3;

    double area_1 = get_circle_area_1(radius);
    printf("area_1 = %f\n", area_1); 
    // output -> area_1 = 88.247337

    double area_2;
    get_circle_area_2(radius, &area_2);
    printf("area_2 = %f\n", area_2);
    // output -> area_2 = 88.247337
  }
*/

/*
  // if the only reason that I need to calculate area is 
  // to use it in another function

  #define PI 3.14159265358979323846

  double get_circle_area_1(double radius)
  {
    return PI * radius * radius;
  }

  void get_circle_area_2(double radius, double* p_area)
  {
    *p_area = PI * radius * radius;
  }

  double do_important_work(double area)
  {
    return area * 2;
  }

  int main(void)
  {
    double radius = 5.3;
    double dval = do_important_work(get_circle_area_1(radius));

    // get_circle_area_1 function is not making us 
    // to create a variable for area 
    // but get_circle_area_2 function is.
  }
*/

/*
  Question : Which scenarios that we want to select 
              get_circle_area_2 function instead of get_circle_area_1 ?

  - maliyet(cost) 
  - birden fazla değerin iletilmesi (passing multiple values)
*/

/*
  int sum(int a, int b)
  {
    return a + b;
  }

  int main(void)
  {
    int x = 10;
    int y = 20;

    int result = sum(x, y);
  }

  // compiled with x86-64 clang 19.1.0 -std=c11 -O0
  // sum:
  //   push rbp
  //   mov rbp, rsp
  //   mov dword ptr [rbp - 4], edi     : int a = x (x copied to a)
  //   mov dword ptr [rbp - 8], esi     : int b = y (y copied to b)
  //   mov eax, dword ptr [rbp - 4]     : eax = a
  //   add eax, dword ptr [rbp - 8]     : eax += b
  //   pop rbp
  //   ret
  // main:
  //   push rbp
  //   mov rbp, rsp
  //   sub rsp, 16
  //   mov dword ptr [rbp - 4], 10      : int x = 10
  //   mov dword ptr [rbp - 8], 20      : int y = 20
  //   mov edi, dword ptr [rbp - 4]     : edi = x
  //   mov esi, dword ptr [rbp - 8]     : esi = y
  //   call sum
  //   mov dword ptr [rbp - 12], eax    : int result = eax
  //   xor eax, eax
  //   add rsp, 16
  //   pop rbp
  //   ret

  // edi is first caller save register
  // esi is second caller save register
*/

/*
  typedef struct{
    int a[20][20];
    int row, col;
  }Matrix;

  Matrix get_random_matrix_1(void);

  void get_random_matrix_2(Matrix*);

  int main(void)
  {
    printf("sizeof(Matrix) = %zu\n", sizeof(Matrix));
    // output -> sizeof(Matrix) = 1608

    Matrix m; // this object is 1608 bytes

    m = get_random_matrix_1();  
    // 1608 bytes will be copied to m object

    get_random_matrix_2(&m);
    // 8 bytes(Matrix*) will be copied to get_random_matrix_2 function

    // get_random_matrix_1 and get_random_matrix_2 functions
    // are doing the same job but get_random_matrix_2 is cheaper
  }
*/

/*
  typedef struct{
    int a[20][20];
    int row, col;
  }Matrix;

  void get_random_matrix(Matrix*);
  // function is accepting address of an object
  // and it is writing to that object
  // Matrix* : out param(eter)
*/

/*
  // passing multiple values

  // <------------ SCENARIO 1 ------------>
  void get_values(double d1, 
                  double d2, 
                  double* p_alpha, 
                  double* p_beta,
                  double* p_gamma)
  {
    *p_alpha  = d1 + d2;
    *p_beta   = d1 * d2;
    *p_gamma  = d1 - d2;
  }
  // p_alpha, p_beta, p_gamma are being set inside the function

  // <------------ SCENARIO 2 ------------>
  double get_values_2(double d1, 
                      double d2, 
                      double* p_beta, 
                      double* p_gamma)
  {
    *p_beta   = d1 * d2;
    *p_gamma  = d1 - d2;
    return d1 + d2;   
  }
  // returning p_alpha in return value and 
  // p_beta and p_gamma is being set inside the function

  // for this kind of functions, generally return value is 
  // the important value(p_alpha) and others(p_beta, p_gamma) are
  // the values that we might want to change or set but 
  // not as important as the return value

  int main(void)
  {
    double x = 5.3;
    double y = 3.7;
    double alpha, beta, gamma;

    get_values(x, y, &alpha, &beta, &gamma);
  }
*/

/*
  // Write a function that add two matrix objects
  // and pass the sum of the matrices to the caller

  typedef struct{
    int a[20][20];
    int row, col;
  }Matrix;

  Matrix add_matrices_1(Matrix m1, Matrix m2);
  // 3 copies of Matrix object

  void add_matrices_2(Matrix m1, Matrix m2, Matrix* p_result);
  // 2 copies of Matrix object, 1 copy of Matrix* object 

  void add_matrices_3(const Matrix* m1,     
                      const Matrix* m2, 
                      Matrix* p_result);
  // 3 copies of Matrix* object 
  // in params : m1, m2 
  // out param : p_result

  // we do not want to change the values of m1 and m2
  // we will use them as an input of the function
  // so we are using const keyword 

  // void set(T*);          -> function will write to T
  // void access(const T*); -> function will read from T

  int main(void)
  {
    Matrix m1;
    Matrix m2;
    Matrix result;
    // ...

    result = add_matrices_1(m1, m2);

    add_matrices_2(m1, m2, &result);

    add_matrices_3(&m1, &m2, &result);
  }
*/

/*
  // In C, an array CAN NOT call(pass) a function by value 
  // only call it by reference is possible

  void foo(int p[]);
  void bar(int* p);
  // Those 2 functions are equivalent

  int main()
  {
    int a[100] = { 1, 2, 3, 4, 5 };

    // because of array's elements are contigious in memory
    // we can reach every elements of the array 
    // by using the address of the first element

    foo(a);   // a ==> &a[0] (array decay)
    bar(a);   // a ==> &a[0] (array to pointer conversion)
  }
*/

/*
  // some functions get the address of an object,
  // it uses the object as an input and also writes to the object
  // and pass the object to the caller
  // in-out parameter

  // out parameter 
  void foo(int* p);

  // in-out parameter
  void bar(int* p);

  int main()
  {
    int x;  // indeterminate(garbage) value

    foo(&x);    
    // no logic error 
    // foo function's parameter is out param
    // so foo is not using x variable as an input

    bar(&x);  // undefined behavior
    // bar function's parameter is in-out param
    // so bar is will use x variable as an input
    // but x variable has an indeterminate value
    // using indeterminate value is undefined behavior
  }
*/

/*
                    -----------------------
                    | pointer arithmetics |
                    -----------------------
*/

/*
  LEGAL OPERATIONS
  --------------------
  -> address + integer  = address
  -> integer + address  = address
  -> address - integer  = address
  -> address - address  = signed integer

  ILLEGAL OPERATIONS
  ---------------------
  -> integer - address
  -> address + address
*/

/*
  int main(void)
  {
    int a[10] = { 0 };

    a + 5;  // legal    (address + integer)
    3 + a;  // legal    (integer + address)

    int* p = a + 7;
    p - 5;  // legal    (address - integer)
    p + 1;  // legal    (address + integer)

    p + a;  // illegal  (address + address)
    3 - a;  // illegal  (integer - address)
  }
*/

/*
  - Bir dizinin 5 indisli elemaının adresi ile 1'i toplarsak 
    o dizinin 6 indisli elemanının adresini elde ederiz.
    &a[5] + 1 = &a[6]
*/

/*
  int main(void)
  {
    char a[10] = { 0 };

    for (int i = 0; i < 10; ++i)
      printf("%p\n", a + i);

    // output ->
    //  00000028D9FFFE22
    //  00000028D9FFFE23  
    //  00000028D9FFFE24
    //  00000028D9FFFE25
    //  00000028D9FFFE26
    //  00000028D9FFFE27
    //  00000028D9FFFE28
    //  00000028D9FFFE29
    //  00000028D9FFFE2A
    //  00000028D9FFFE2B
    // addresses are increasing by 1
  }
*/

/*
  int main(void)
  {
    short a[10] = { 0 };

    for (int i = 0; i < 10; ++i)
      printf("%p\n", a + i);
    
    // output ->
    //  000000E4B6DFFC30
    //  000000E4B6DFFC32
    //  000000E4B6DFFC34
    //  000000E4B6DFFC36
    //  000000E4B6DFFC38
    //  000000E4B6DFFC3A
    //  000000E4B6DFFC3C
    //  000000E4B6DFFC3E
    //  000000E4B6DFFC40
    //  000000E4B6DFFC42
    // addresses are increasing by 2
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0 };

    for (int i = 0; i < 10; ++i)
      printf("%p\n", a + i);
    
    // output ->
    //  00000034CEFFF900
    //  00000034CEFFF904
    //  00000034CEFFF908
    //  00000034CEFFF90C
    //  00000034CEFFF910
    //  00000034CEFFF914
    //  00000034CEFFF918
    //  00000034CEFFF91C
    //  00000034CEFFF920
    //  00000034CEFFF924
    // addresses are increasing by 4
  }
*/

/*
  int main(void)
  {
    double a[10] = { 0 };

    for (int i = 0; i < 10; ++i)
      printf("%p\n", a + i);
    
    // output ->
    //  0000006AB49FF730
    //  0000006AB49FF738
    //  0000006AB49FF740
    //  0000006AB49FF748
    //  0000006AB49FF750
    //  0000006AB49FF758
    //  0000006AB49FF760
    //  0000006AB49FF768
    //  0000006AB49FF770
    //  0000006AB49FF778
    // addresses are increasing by 8
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    // &a[3] -> (a + 3)

    for(int i = 0; i < 10; ++i)
      printf("%2d %2d %2d\n", a[i], *(a + i), *(i + a));

    // output ->
    //   0  0  0
    //  11 11 11
    //  22 22 22
    //  33 33 33
    //  44 44 44
    //  55 55 55
    //  66 66 66
    //  77 77 77
    //  88 88 88
    //  99 99 99
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    int* ptr = a;
    printf("%d\n", *ptr); // output -> 0

    ++ptr;
    printf("%d\n", *ptr); // output -> 11

    ptr++; 
    printf("%d\n", *ptr); // output -> 22

    ptr += 1;
    printf("%d\n", *ptr); // output -> 33

    ptr = ptr + 1;
    printf("%d\n", *ptr); // output -> 44
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    int* ptr = a;
    printf("%d\n", *ptr); // output -> 0

    ptr += 5;
    printf("%d\n", *ptr); // output -> 55
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    int* ptr = a;

    for (int i = 0; i < 10; ++i){
      printf("%2d %2d %2d %2d\n", a[i], *(a + i), *(i + a), *ptr);
      ++ptr;
    }

    // output ->
    //   0  0  0  0
    //  11 11 11 11
    //  22 22 22 22
    //  33 33 33 33
    //  44 44 44 44
    //  55 55 55 55
    //  66 66 66 66
    //  77 77 77 77
    //  88 88 88 88
    //  99 99 99 99
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    int* ptr = a;

    int n  = 10;
    while(n--){
      printf("%d ", *ptr);
      ++ptr;
    }
    // output -> 0 11 22 33 44 55 66 77 88 99
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    int* ptr_1 = a + 3;
    int* ptr_2 = a + 8;

    printf("%d\n", ptr_2 - ptr_1);  // output -> 5
    printf("%d\n", ptr_1 - ptr_2);  // output -> -5

    // warning: format '%d' expects argument of type 'int', 
    // but argument 2 has type 'long long int

    // "ptr_2 - ptr_1" expression's data type is ptrdiff_t(type alias)

    // ptrdiff_t is a signed integer type and implementation-defined
    // because of gcc compiler implemented ptrdiff_t as long long int
    // we are getting this warning
  }
*/

/*
            --------------------------------------------------
            | subscript operator (köşeli parantez operatörü) |
            --------------------------------------------------
*/

/*
  - binary operator
  - 1st priority level operator (left associative)

    x[y]  --> *(x + y)
*/

/*
  int main(void)
  {
    int x = 6;
    printf("%d\n", x);    // output -> 6


    (&x)[0] = 99;   // (&x)[0] ===> *(&x + 0)
    printf("%d\n", x);    // output -> 99
  }
*/

/*
  int main(void)
  {
    int x = 5;
    printf("x = %d\n", x);  // output -> x = 5

    int* ptr = &x;
    ptr[0] = 88;   // ptr[0] ===> *(ptr + 0)
    printf("x = %d\n", x);  // output -> x = 88
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    int* p = a + 5;

    printf("%d\n", *p);     
    // output -> 55

    printf("%d\n", p[0]);   
    // output -> 55  (p[0]  ===> *(p + 0))

    printf("%d\n", p[3]);   
    // output -> 88  (p[3]  ===> *(p + 3))

    printf("%d\n", p[-4]);  
    // output -> 11  (p[-4] ===> *(p - 4))
    
    printf("%d\n", 2[p]);   
    // output -> 77  (2[p]  ===> *(2 + p))
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    int* ptr = a + 5;

    int k = ptr[-4];
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-64], 0       : a[0] = 0 (a[0] is DWORD(int))
  //    mov DWORD PTR [rbp-60], 11
  //    mov DWORD PTR [rbp-56], 22
  //    mov DWORD PTR [rbp-52], 33
  //    mov DWORD PTR [rbp-48], 44
  //    mov DWORD PTR [rbp-44], 55
  //    mov DWORD PTR [rbp-40], 66
  //    mov DWORD PTR [rbp-36], 77
  //    mov DWORD PTR [rbp-32], 88
  //    mov DWORD PTR [rbp-28], 99
  //    lea rax, [rbp-64]               : rax = &a[0]
  //    add rax, 20                     : rax = &a[0] + 5*4[20byte]
  //    mov QWORD PTR [rbp-8], rax      : ptr = &a[5]
  //    mov rax, QWORD PTR [rbp-8]      : rax = ptr
  //    mov eax, DWORD PTR [rax-16]     : eax = *(ptr - 4*4[16byte])
  //    mov DWORD PTR [rbp-12], eax     : int k = eax 
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    int* p = a;

    p += 3;       // p = &a[0] + 3  ===> p = (a + 3)
    p[-2] = 999;  // p[-2] = *(p - 2) = *(a + 3 - 2) = a[1] = 999

    printf("%d\n", a[1]);  // output -> 999
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 }; 

    //------------------------------------------------------

    for(int i = 0; i < 10; ++i)
      printf("%d ", a[i]);
    // output -> 0 11 22 33 44 55 66 77 88 99

    printf("\n");

    //------------------------------------------------------
    
    int* p = a;
    for(int i = 0; i < 10; ++i)
      printf("%d ", p[i]);
    // output -> 0 11 22 33 44 55 66 77 88 99

    printf("\n");

    //------------------------------------------------------

    int size = 10;
    while(size--){
      printf("%d ", *p);
      ++p;
    }
    // output -> 0 11 22 33 44 55 66 77 88 99
      
    //------------------------------------------------------
  }
*/

/*  
            ---------------------------------------------
            | diziler üzerinde işlem yapan fonksiyonlar |
            ---------------------------------------------
            |     functions that operate on arrays      |
            ---------------------------------------------
*/

/*
  void foo(int* ptr)
  {
    for(int i = 0; i < sizeof(ptr) / sizeof(ptr[0]); ++i)
      printf("%d ", ptr[i]);

    // sizeof(ptr) is 8 for x64 systems
    // sizeof(ptr[0]) is 4 for int type

    // for(int i = 0; i < 2; ++i)
    //    printf("%d ", ptr[i]);
  }

  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    for(int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
      printf("%d ", a[i]);

    // output -> 0 11 22 33 44 55 66 77 88 99

    foo(a); // output -> 0 11
  }
*/

/*
  void foo(int* ptr, int size)
  {
    // <---- WAY 1 ---->

    for(int i = 0; i < size; ++i)
      printf("%d ", ptr[i]);

    printf("\n");

    // ptr variable's value is not changed

    // <---- WAY 2 ---->

    while(size--){
      printf("%d ", *ptr);
      ++ptr;
    }

    // ptr variable's value is the address of end of the array
  }
*/

/*
  void aprint_1(int* ptr, int size)
  {
    for(int i = 0; i < size; ++i)
      printf("%d ", ptr[i]);

    printf("\n");
  }

  void aprint_2(int* ptr, int size)
  {
      while(size--){
        printf("%d ", *ptr);
        ++ptr;
      }
      printf("\n");
  }

  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    aprint_1(a, 10);  // output -> 0 11 22 33 44 55 66 77 88 99
    aprint_2(a, 10);  // output -> 0 11 22 33 44 55 66 77 88 99

    aprint_1(a, 4);   // output -> 0 11 22 33

    // Question: call aprint_1 function to output a[3], a[4], a[5]
    aprint_1(a + 2, 3);  // output -> 22 33 44
    aprint_1(&a[2], 3);  // output -> 22 33 44

    // Question: call aprint_2 function to output last 4 elements
    aprint_2(a + 6, 4);  // output -> 66 77 88 99
    aprint_2(&a[6], 4);  // output -> 66 77 88 99
  } 
*/

/*
  void foo(const int ival);
  void foo(int ival);
  // function redeclaration
  - nothing change for function's caller

  difference in pointer arguments constness is important 
  but difference of non-pointer arguments constness is not important
*/

/*
  #include "../nutility.h"

  #define   SIZE  100

  int get_sum_1(const int* p_array, int size)
  {
    int sum = 0;
    for(int i = 0; i < size; ++i)
      sum += p_array[i];
    
    return sum;
  }

  int get_sum_2(const int* p_array, int size)
  {
    int sum = 0;
    while (size--){
      sum += *p_array;
      ++p_array;
    }
    
    return sum;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random_1(a, SIZE);

    printf("sum array = %d\n", get_sum_1(a, SIZE));
    // sum array = 54941
  }
*/

/*
  #include "../nutility.h"

  #define   SIZE  100

  double get_mean(const int* p_array, int size)
  {
    return (double)get_sum(p_array, size) / size;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    printf("mean = %f\n", get_mean(a, SIZE));
    // mean = mean = 530.040000
  }
*/

/*
  #include "../nutility.h"
  #include <math.h>

  #define   SIZE  100

  // standart deviation
  double get_std_dev(const int* p_array, int size)
  {
    double mean = get_mean(p_array, size);
    double sum_square = 0.;

    for(int i = 0; i < size; ++i)
      sum_square += (p_array[i] - mean) * (p_array[i] - mean);

    return sqrt(sum_square / (size - 1));
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    double std_dev = get_std_dev(a, SIZE);
    printf("standart deviation = %f\n", std_dev);
    // output -> standart deviation = 276.183150
  }
*/

/*
  #include "../nutility.h"

  #define   SIZE  20

  void reverse_array(int* p_array, int size)
  {
    for(int i = 0; i < size / 2; ++i)
      swap(&p_array[i], &p_array[size - i - 1]);
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    print_array(a, SIZE); 
    // output ->
    //  424 314 297 657 734 384 669 623 736 798
    //  703 587 605 390 681 768 213  19 330 906

    reverse_array(a, SIZE);
    print_array(a, SIZE);
    // output ->
    //  906 330  19 213 768 681 390 605 587 703
    //  798 736 623 669 384 734 657 297 314 424
  }
*/

/*
  #include "../nutility.h"

  #define   SIZE  20

  int get_max_elem(const int* p_array, int size)
  {
    int max = *p_array;
    for(int i = 1; i < size; ++i)
      if(p_array[i] > max)
        max = p_array[i];
    
    return max;
  }

  int get_min_elem(const int* p_array, int size)
  {
    int min = *p_array;
    for(int i = 1; i < size; ++i)
      if(p_array[i] < min)
        min = p_array[i];
    
    return min;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    print_array(a, SIZE);
    // output ->
    //  540 253 228 542 375 838 551 535 836 311
    //  887 883 692 370 225 387 927 989 844 183

    int max = get_max_elem(a, SIZE);
    printf("max elem = %d\n", max);
    // output -> max elem = 989

    int min = get_min_elem(a, SIZE);
    printf("min elem = %d\n", min);
    // output -> min elem = 183
  }
*/

/*
  #include "../nutility.h"

  #define   SIZE  20

  // 2 in param   : p_array, size
  // 2 out param  : min, max
  void get_min_max(const int* p_array, int size, int* p_min, int* p_max)
  {
    *p_min = *p_max = *p_array;

    for(int i = 1; i < size; ++i){
      if(p_array[i] > *p_max)
        *p_max = p_array[i];
      else if(p_array[i] < *p_min)
        *p_min = p_array[i];
    }
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    print_array(a, SIZE);
    // output ->
    //  444 886 816 750 228 361 870 638 301 700
    //  962 794  65 318 895 182 481 991 809 274

    int min, max;

    get_min_max(a, SIZE, &min, &max);
    printf("min = %d, max = %d\n", min, max);
    // output -> min = 65, max = 991
  }
*/

/*
  #include "../nutility.h"

  #define  SIZE  20

  void copy_array_1(int* p_dest, const int* p_source, int size)
  {
    for(int i = 0; i < size; ++i)
      p_dest[i] = p_source[i];
  }

  void copy_array_2(int* p_dest, const int* p_source, int size)
  {
    while (size--)
      *p_dest++ = *p_source++;
  }

  int main(void)
  {
    int a[SIZE];
    int b[SIZE];

    randomize();
    set_array_random(a, SIZE);

    print_array(a, SIZE);
    // output ->
    //  119  26 864 694 188 926 925 506 603 469
    //  622 390 580 671 979 495 551 179 696 806

    copy_array_1(b, a, SIZE);
    print_array(b, SIZE);
    // output ->
    //  119  26 864 694 188 926 925 506 603 469
    //  622 390 580 671 979 495 551 179 696 806
  }
*/

/*
  #include "../nutility.h"

  #define  SIZE  40

  int main(void)
  {
    int a[SIZE];
    int b[SIZE] = { 0 };

    randomize();
    set_array_random(a, SIZE);

    int idx_a = 10, idx_b = 20, n = 10;

    printf("array a : \n");
    print_array(a, SIZE);

    // output ->
    //  array a :
    //  938 112 735 848   6 658 857 414 751 635
    //  542 156 398 167 477 251 965 644 599 847
    //  350 804 667 912 361 786 566  52 116 187
    //  305 970 912  47 411 242 866 127 776 868

    copy_array(b + idx_b, a + idx_a, n);

    printf("array b : \n");
    print_array(b, SIZE);
    // output ->
    //  array b :
    //    0   0   0   0   0   0   0   0   0   0
    //    0   0   0   0   0   0   0   0   0   0
    //  542 156 398 167 477 251 965 644 599 847
    //    0   0   0   0   0   0   0   0   0   0
  }
*/

/*
  #include "../nutility.h"

  #define SIZE 20

  void bubble_sort(int* p, int size)
  {
    for (int i = 0; i < size - 1; ++i){
      for (int k = 0; k < size - i - 1; ++k){
        if (p[k] > p[k + 1])
          swap(p + k, p + k + 1);
      }
    }
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output ->
    //  405  39 408 262 430 125 185 797 612 198
    //  392 455 529 995 461 998  82  11 248 771

    bubble_sort(a, SIZE);
    print_array(a, SIZE);
    // output ->
    //   11  39  82 125 185 198 248 262 392 405
    //  408 430 455 461 529 612 771 797 995 998

    set_array_random(a, SIZE);
    bubble_sort(a, SIZE - 10);  // sort first line(10 elements)
    print_array(a, SIZE);
    // output ->
    //    8  48  83 172 240 331 356 417 512 586
    //  575   7 771 537 941 587  24 348 365 846

    set_array_random(a, SIZE);
    bubble_sort(a + 10, SIZE - 10);  // sort second line(10 elements)
    print_array(a, SIZE);
    // output ->
    //  515 813  21 432   3 295 608 164 492 556
    //   17 152 247 534 573 723 730 843 859 902
  }
*/

/*
  #include "../nutility.h"

  #define SIZE 20

  void swap_arrays(int* p_array1, int* p_array2, int size)
  {
    while (size--)
      swap(p_array1++, p_array2++);
  }

  int main(void)
  {
    int a[SIZE];
    int b[SIZE];

    randomize();
    set_array_random(a, SIZE);
    set_array_random(b, SIZE);

    print_array(a, SIZE);
    print_array(b, SIZE);
    // output ->
    //  470 843 424 350 878 287  36 778 439 776
    //  710  46  74 378 377 352 692 322 238 101
    //  ---------------------------------------
    //   38 868 501 190 644  10  35 668 224 526
    //  492 399 967 682 746 685 972  86 646 705
    //  ---------------------------------------

    swap_arrays(a, b, SIZE);
    print_array(a, SIZE);
    print_array(b, SIZE);
    // output ->
    //   38 868 501 190 644  10  35 668 224 526
    //  492 399 967 682 746 685 972  86 646 705
    //  ---------------------------------------
    //  470 843 424 350 878 287  36 778 439 776
    //  710  46  74 378 377 352 692 322 238 101
    //  ---------------------------------------
  }
*/

/*
  void func(int* p, int size);
  void func(int p[], int size);

  // there is an alternative syntax
  // but this syntax is only for functions, 
  // which have pointers as parameters
*/