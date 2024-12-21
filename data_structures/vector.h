#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>   // size_t
#include <stdbool.h>  // bool macro

#define   NOT_FOUND           ((size_t)(-1))
#define   DEFAULT_CAPACITY    16

/*  FUNCTIONAL MACROS   */

#define   vector_get_element(p_vec, index)    \
          ((p_vec)->mp_arr[(index)])

typedef int DATATYPE;    
// dynamic array will hold int values
typedef int(*VALUE_COMPARE_FN)(const DATATYPE*, const DATATYPE*);

typedef struct {
  DATATYPE*   mp_arr;
  size_t      m_size;
  size_t      m_capacity;
} Vector_t, *Vector_p;

/*  STATIC INLINE FUNCTIONS  */

static inline size_t vector_get_size(Vector_p p_vec)
{
  return p_vec->m_size;
}

static inline size_t vector_get_capacity(Vector_p p_vec)
{
  return p_vec->m_capacity;
}

static inline bool vector_is_empty(Vector_p p_vec)
{
  return p_vec->m_size == 0;
}

Vector_p vector_create(void);
Vector_p vector_create_with_capacity(size_t capacity);
Vector_p vector_create_from_array(const DATATYPE* p_arr, size_t size);
Vector_p vector_create_filled_same_elements(size_t size, DATATYPE val);

void vector_destroy(Vector_p p_vec);

bool vector_reserve(Vector_p p_vec, size_t new_capacity);
bool vector_push_back(Vector_p p_vec, DATATYPE val);
bool vector_pop_back(Vector_p p_vec);
bool vector_insert(Vector_p p_vec, size_t index, DATATYPE val);
bool vector_erase(Vector_p p_vec, size_t index);
size_t vector_erase_all(Vector_p p_vec, DATATYPE val);
bool vector_erase_first_occurrence( Vector_p p_vec, 
                                    DATATYPE val, 
                                    VALUE_COMPARE_FN compare_fn);
size_t vector_find_element( Vector_p p_vec, 
                            DATATYPE val, 
                            VALUE_COMPARE_FN compare_fn);
void vector_shrink_to_fit(Vector_p p_vec);
void vector_clear(Vector_p p_vec);


#endif // VECTOR_H