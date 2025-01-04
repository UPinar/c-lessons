#include <stdio.h>

/*
                    ========================
                    | C11 standard changes |
                    ========================
*/

/*
                      ---------------------
                      | generic selection |
                      ---------------------
*/

/*
  -----------------------------------------------------

  - "_Generic" keyword is added in C11 standard. 
  - generic selection will be done in compile time.
  - generic selection is used in macros for simulating 
    function overloading.

  -----------------------------------------------------

  syntax:
  _Generic(expression, 
    type1: value1, 
    type2: value2, 
    type3: value3,
    type4: value4
  );

  -----------------------------------------------------

  _Generic(expression, 
    int     : max_int, 
    float   : max_float, 
    double  : max_double
  );

  - expression's type is int, max_int will be selected
  - expression's type is float, max_float will be selected
  - expression's type is double, max_double will be selected
  - expression's type is none of them syntax error 

  _Generic(expression, 
    int     : max_int, 
    float   : max_float, 
    double  : max_double,
    default : max_xxx
  );

  - expression's type is int, max_int will be selected
  - expression's type is float, max_float will be selected
  - expression's type is double, max_double will be selected
  - expression's type is none of them, max_xxx will be selected

  -----------------------------------------------------
*/

/*
  #define   get_max(a, b)   _Generic((a),           \
                              int     : max_int,    \
                              long    : max_long,   \
                              float   : max_float,  \
                              double  : max_double  \
                            )(a, b)

  int max_int(int a, int b) 
  {
    printf("max_int called\n");
    return a > b ? a : b;
  }

  long max_long(long a, long b) 
  {
    printf("max_long called\n");
    return a > b ? a : b;
  }

  float max_float(float a, float b) 
  {
    printf("max_float called\n");
    return a > b ? a : b;
  }

  double max_double(double a, double b) 
  {
    printf("max_double called\n");
    return a > b ? a : b;
  }

  int main(void)
  {
    int ival = get_max(11, 22);       
    // output -> max_int called

    long lval = get_max(33L, 44L);
    // output -> max_long called

    float fval = get_max(55.5f, 66.6f);
    // output -> max_float called

    double dval = get_max(77.7, 88.8);
    // output -> max_double called
  }
*/

/*
  #include <math.h>   // cbrt(cube root)

  #define   cbrt(X)     _Generic((X),             \
                          long double : cbrtl,    \
                          default     : cbrt,     \
                          float       : cbrtf     \
                        )(X)
                
  int main(void)
  {
    double dval = 111.1;
    const float cfval = 222.2f;

    double dresult = cbrt(dval);
    float fresult = cbrt(cfval);

    printf("cbrt(111.1) = %f\n", cbrt(dval));   
    // output -> cbrt(111.1) = 4.807338
    printf("cbrt(222.2f) = %f\n", cbrt(cfval));
    // output -> cbrt(222.2f) = 6.056867
  }
*/

/*
  #include <tgmath.h>   // type generic math header file

  int main(void)
  {
    double dres = sqrt(4.0);    
    // sqrt will be selected for double

    float lres = sqrt(16.2f);    
    // sqrtf will be selected for float

    long double ldres = sqrt(25.5L);
    // sqrtl will be selected for long double
  }
*/

/*
  #define   printf_dec_format(X)    _Generic((X),     \
      char                                  : "%c",   \
      signed char                           : "%hhd", \
      unsigned char                         : "%hhu", \
      signed short                          : "%hd",  \
      unsigned short                        : "%hu",  \
      signed int                            : "%d",   \
      unsigned int                          : "%u",   \
      long int                              : "%ld",  \
      unsigned long int                     : "%lu",  \
      long long int                         : "%lld", \
      unsigned long long int                : "%llu", \
      float                                 : "%f",   \
      double                                : "%f",   \
      long double                           : "%Lf",  \
      char *                                : "%s",   \
      void *                                : "%p"    \
    )

  #define   print(x)    printf(printf_dec_format(x), x)
  #define   println(x)  printf(printf_dec_format(x), x), printf("\n")

  int main(void)
  {   
    println('A');         // output -> 65
    println((char)'B');   // output -> B
    println(111);         // output -> 111
    println(222.2);       // output -> 222.200000
  }
*/