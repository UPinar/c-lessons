#include "vector.h"

#include <stdlib.h>   // malloc, free, realloc
#include <stdio.h>    // fprintf
#include <string.h>   // memmove
#include <stdbool.h>  // true, false

// -----------------------------------------------------
// -----------------------------------------------------

Vector_p vector_create(void)
{
  return vector_create_with_capacity(DEFAULT_CAPACITY);
}

// -----------------------------------------------------
// -----------------------------------------------------

Vector_p vector_create_with_capacity(size_t capacity)
{
  Vector_p p_vec = malloc(sizeof(Vector_t));
  if (!p_vec) {
    fprintf(stderr, "Memory allocation failed.\n");
    return NULL;
  }

  p_vec->m_size = 0;
  p_vec->m_capacity = capacity;

  p_vec->mp_arr = malloc(capacity * sizeof(DATATYPE));
  if (!p_vec->mp_arr) {
    fprintf(stderr, "Memory allocation failed.\n");
    free(p_vec);
    return NULL;
  }

  return p_vec;
}

// -----------------------------------------------------
// -----------------------------------------------------

Vector_p vector_create_from_array(const DATATYPE* p_arr, 
                                  size_t size)
{
  Vector_p p_vec = vector_create_with_capacity(size);
  if (!p_vec) {
    return NULL;
  }

  memmove(p_vec->mp_arr, p_arr, size * sizeof(DATATYPE));
  p_vec->m_size = size;

  return p_vec;
}

// -----------------------------------------------------
// -----------------------------------------------------

Vector_p vector_create_filled_same_elements(size_t size, 
                                            DATATYPE val)
{
  Vector_p p_vec = vector_create_with_capacity(size);
  
  if (!p_vec)
    return NULL;

  p_vec->m_size = size;

  for (size_t i = 0; i < size; ++i)
    p_vec->mp_arr[i] = val;

  return p_vec;
}

// -----------------------------------------------------
// -----------------------------------------------------

void vector_destroy(Vector_p p_vec)
{
  free(p_vec->mp_arr);
  free(p_vec);
}

// -----------------------------------------------------
// -----------------------------------------------------


bool vector_reserve(Vector_p p_vec, size_t new_capacity)
{
  if (new_capacity < p_vec->m_capacity)
    return false;
  else if (new_capacity == p_vec->m_capacity)
    return true;

  DATATYPE* p_new_arr = realloc(p_vec->mp_arr, 
                                new_capacity * sizeof(DATATYPE));
  if (!p_new_arr) {
    fprintf(stderr, "can not reserve capacity\n");
    return false;
  }

  p_vec->mp_arr = p_new_arr;
  p_vec->m_capacity = new_capacity;

  return true;
}

// -----------------------------------------------------
// -----------------------------------------------------

bool vector_push_back(Vector_p p_vec, DATATYPE val)
{
  if (p_vec->m_size == p_vec->m_capacity &&
      !vector_reserve(p_vec, p_vec->m_capacity * 2))
  {
    fprintf(stderr, "can not allocate capacity\n");
    return false;
  }

  p_vec->mp_arr[p_vec->m_size] = val;
  ++(p_vec->m_size);

  return true;
}

// -----------------------------------------------------
// -----------------------------------------------------

bool vector_pop_back(Vector_p p_vec)
{
  if (vector_is_empty(p_vec))
    return false;

  --(p_vec->m_size);

  return true;
}

// -----------------------------------------------------
// -----------------------------------------------------

bool vector_insert(Vector_p p_vec, size_t index, DATATYPE val)
{
  if (index > p_vec->m_size)
    return false;

  if (p_vec->m_size == p_vec->m_capacity &&
      !vector_reserve(p_vec, p_vec->m_capacity * 2))
  {
    fprintf(stderr, "can not allocate capacity\n");
    return false;
  }

  memmove(p_vec->mp_arr + index + 1, 
          p_vec->mp_arr + index, 
          (p_vec->m_size - index) * sizeof(DATATYPE));

  p_vec->mp_arr[index] = val;
  ++(p_vec->m_size);

  return true;
}

// -----------------------------------------------------
// -----------------------------------------------------

bool vector_erase(Vector_p p_vec, size_t index)
{
  if (index >= p_vec->m_size)
    return false;

  memmove(p_vec->mp_arr + index, 
          p_vec->mp_arr + index + 1, 
          (p_vec->m_size - index - 1) * sizeof(DATATYPE));

  --(p_vec->m_size);

  return true;
}

// -----------------------------------------------------
// -----------------------------------------------------

bool vector_erase_first_occurrence( Vector_p p_vec, 
                                    DATATYPE val, 
                                    VALUE_COMPARE_FN compare_fn)
{
  size_t index = vector_find_element(p_vec, val, compare_fn);
  if (index == NOT_FOUND)
    return false;

  return vector_erase(p_vec, index);
}

// -----------------------------------------------------
// -----------------------------------------------------

size_t vector_find_element( Vector_p p_vec, 
                            DATATYPE val, 
                            VALUE_COMPARE_FN compare_fn)
{
  for (size_t i = 0; i < p_vec->m_size; ++i)
    if (compare_fn(p_vec->mp_arr + i, &val) == 0)
      return i;

  return NOT_FOUND;
}

// -----------------------------------------------------
// -----------------------------------------------------

void vector_shrink_to_fit(Vector_p p_vec)
{
  if (p_vec->m_size == p_vec->m_capacity)
    return;

  DATATYPE* p_new_arr = realloc(p_vec->mp_arr, 
                                p_vec->m_size * sizeof(DATATYPE));
  if (!p_new_arr) {
    fprintf(stderr, "can not shrink to fit\n");
    return;
  }

  p_vec->mp_arr = p_new_arr;
  p_vec->m_capacity = p_vec->m_size;
}

// -----------------------------------------------------
// -----------------------------------------------------

void vector_clear(Vector_p p_vec)
{
  p_vec->m_size = 0;
}