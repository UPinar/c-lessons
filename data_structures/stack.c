#include "stack.h"

#include <stdlib.h>  // malloc, free

// -----------------------------------------------
// -----------------------------------------------

Stack_t* stack_create_with_capacity(size_t capacity)
{
  Stack_t* stack = malloc(sizeof(Stack_t));
  if (stack == NULL)
    return NULL;

  stack->mp_arr = malloc(capacity * sizeof(DATATYPE));
  if (stack->mp_arr == NULL) {
    free(stack);
    return NULL;
  }

  stack->m_size = 0;
  stack->m_capacity = capacity;

  return stack;
}

// -----------------------------------------------
// -----------------------------------------------

void stack_destroy(Stack_t* stack)
{
  if (stack == NULL)
    return;

  free(stack->mp_arr);
  free(stack);
}

// -----------------------------------------------
// -----------------------------------------------

void stack_clear(Stack_t* stack)
{
  stack->m_size = 0;
}

// -----------------------------------------------
// -----------------------------------------------

bool stack_push_by_value(Stack_t* stack, DATATYPE val)
{
  if (stack->m_size == stack->m_capacity)
    return false;

  stack->mp_arr[stack->m_size] = val;
  ++stack->m_size;

  return true;
}

// -----------------------------------------------
// -----------------------------------------------

bool stack_push_by_ref(Stack_t* stack, const DATATYPE* p_val)
{
  if (stack->m_size == stack->m_capacity)
    return false;

  stack->mp_arr[stack->m_size] = *p_val;
  ++stack->m_size;

  return true;
}

// -----------------------------------------------
// -----------------------------------------------

bool stack_pop(Stack_t* stack, DATATYPE* p_val)
{
  if (stack->m_size == 0)
    return false;

  --stack->m_size;
  *p_val = stack->mp_arr[stack->m_size];

  return true;
}

// -----------------------------------------------
// -----------------------------------------------

bool stack_top(Stack_t* stack, DATATYPE* p_val)
{
  if (stack->m_size == 0)
    return false;

  *p_val = stack->mp_arr[stack->m_size - 1];

  return true;
}

// -----------------------------------------------
// -----------------------------------------------
