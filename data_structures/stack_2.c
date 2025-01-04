#include "stack_2.h"

#include <stdlib.h>  // malloc, free

// -----------------------------------------------
// -----------------------------------------------

Stack_t* stack_create(void)
{
  Stack_t* stack = malloc(sizeof(Stack_t));
  if (stack == NULL)
    return NULL;

  stack->mp_top_node = NULL;
  stack->m_size = 0;

  return stack;
}

// -----------------------------------------------
// -----------------------------------------------

static void free_all_nodes(Stack_t* stack)
{
  Node_t* p_current_node = stack->mp_top_node;

  Node_t* p_temp_node;
  while (p_current_node != NULL) {
    p_temp_node = p_current_node;
    p_current_node = p_current_node->mp_next_node;
    free(p_temp_node);
  }
}

// -----------------------------------------------
// -----------------------------------------------

void stack_destroy(Stack_t* stack)
{
  if (stack == NULL)
    return;

  free_all_nodes(stack);
  free(stack);
}

// -----------------------------------------------
// -----------------------------------------------

void stack_clear(Stack_t* stack)
{
  free_all_nodes(stack);
  stack->mp_top_node = NULL;
  stack->m_size = 0;
}

// -----------------------------------------------
// -----------------------------------------------

bool stack_push_by_value(Stack_t* stack, DATATYPE val)
{
  Node_t* p_new_node = malloc(sizeof(Node_t));
  if (p_new_node == NULL)
    return false;

  p_new_node->m_data = val;
  p_new_node->mp_next_node = stack->mp_top_node;
  stack->mp_top_node = p_new_node;
  ++stack->m_size;

  return true;
}

// -----------------------------------------------
// -----------------------------------------------

bool stack_push_by_ref(Stack_t* stack, const DATATYPE* p_val)
{
  Node_t* p_new_node = malloc(sizeof(Node_t));
  if (p_new_node == NULL)
    return false;

  p_new_node->m_data = *p_val;
  p_new_node->mp_next_node = stack->mp_top_node;
  stack->mp_top_node = p_new_node;
  ++stack->m_size;

  return true;
}

// -----------------------------------------------
// -----------------------------------------------

bool stack_pop(Stack_t* stack, DATATYPE* p_val)
{
  if (stack->m_size == 0)
    return false;

  *p_val = stack->mp_top_node->m_data;

  Node_t* p_pop_node = stack->mp_top_node;
  stack->mp_top_node = stack->mp_top_node->mp_next_node;
  free(p_pop_node);
  --stack->m_size;

  return true;
}

// -----------------------------------------------
// -----------------------------------------------

bool stack_top(Stack_t* stack, DATATYPE* p_val)
{
  if (stack->m_size == 0)
    return false;

  *p_val = stack->mp_top_node->m_data;
  return true;
}

// -----------------------------------------------
// -----------------------------------------------
