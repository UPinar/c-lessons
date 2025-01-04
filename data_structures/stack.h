#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef int DATATYPE;

typedef struct {
  DATATYPE* mp_arr;
  size_t m_size;
  size_t m_capacity;
} Stack_t;

/*  INLINE FUNCTIONS  */

static inline size_t stack_get_size(Stack_t* stack)
{
  return stack->m_size;
}

static inline size_t stack_get_capacity(Stack_t* stack)
{
  return stack->m_capacity;
}

static inline bool stack_is_empty(Stack_t* p_stack)
{
  return p_stack->m_size == 0;
}

/* FUNCTION PROTOTYPES */

Stack_t* stack_create_with_capacity(size_t);
void stack_destroy(Stack_t*);
void stack_clear(Stack_t*);

bool stack_push_by_value(Stack_t*, DATATYPE);
bool stack_push_by_ref(Stack_t*, const DATATYPE*);
bool stack_pop(Stack_t* p_stack, DATATYPE*);  // out parameter
bool stack_top(Stack_t* p_stack, DATATYPE*);  // out parameter

#endif // STACK_H