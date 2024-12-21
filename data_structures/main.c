#include <stdio.h>

/*
                ===================================
                | Data Structures (Veri Yapıları) |
                ===================================
*/

/*
                  --------------------------------
                  | Dynamic Array (Dinamik Dizi) |
                  --------------------------------
*/

/*
*/

#include "vector.h"
#include "../headers/nutility.h"

void test_vector(Vector_p p_vec)
{
  printf( "size = %zu, capacity = %zu\n", 
          vector_get_size(p_vec),
          vector_get_capacity(p_vec));         

  if (vector_is_empty(p_vec)){
    printf("vec = []\n");
    return;
  }
  
  printf("vec = [ ");
  for (size_t i = 0; i < vector_get_size(p_vec) - 1; ++i)
    printf("%d, ", vector_get_element(p_vec, i));

  printf("%d ]\n", 
          vector_get_element(p_vec, vector_get_size(p_vec) - 1));
}

int main(void)
{
  Vector_p vec1 = vector_create();

  test_vector(vec1);
  // output ->
  //  size = 0, capacity = 16
  //  vec = []

  for(int i = 0; i < 16; ++i)
    vector_push_back(vec1, i);

  test_vector(vec1);
  // output ->
  //  size = 16, capacity = 16
  //  vec = [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ]

  vector_push_back(vec1, 111);
  test_vector(vec1);
  // output ->
  //  size = 17, capacity = 32
  //  vec = [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 111 ]
}