#ifndef STACK_2_H
#define STACK_2_H

#include <stddef.h>  // size_t
#include <stdbool.h> // bool

typedef int DATATYPE;

typedef struct Node {
  DATATYPE      m_data;
  struct Node*  mp_next_node;
} Node_t;

typedef struct {
  Node_t* mp_top_node;
  size_t  m_size;
} Stack_t;

/*  INLINE FUNCTIONS  */

static inline size_t stack_get_size(Stack_t* p_stack)
{
  return p_stack->m_size;
}

static inline bool stack_is_empty(Stack_t* p_stack)
{
  return p_stack->m_size == 0;
}

/* FUNCTION PROTOTYPES */

Stack_t* stack_create(void);
void stack_destroy(Stack_t*);
void stack_clear(Stack_t*);

bool stack_push_by_value(Stack_t*, DATATYPE);
bool stack_push_by_ref(Stack_t*, const DATATYPE*);
bool stack_pop(Stack_t* p_stack, DATATYPE*);  // out parameter
bool stack_top(Stack_t* p_stack, DATATYPE*);  // out parameter

#endif // STACK_2_H