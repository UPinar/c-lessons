#ifndef QUEUE_2_H
#define QUEUE_2_H

#include <stddef.h>   // size_t
#include <stdbool.h>  // bool

typedef int DATATYPE;

typedef struct Node {
  DATATYPE m_data;
  struct Node* mp_next_node;
} Node_t;

typedef struct {
  Node_t* mp_head_node;
  Node_t* mp_tail_node;
  size_t  m_size;
} Queue_t;

/*  INLINE FUNCTIONS  */

static inline size_t queue_get_size(Queue_t* queue)
{
  return queue->m_size;
}

static inline bool queue_is_empty(Queue_t* queue)
{
  return queue->m_size == 0;
}

/* FUNCTION PROTOTYPES */

Queue_t* queue_create(void);
void queue_destroy(Queue_t*);

bool queue_push_by_value(Queue_t*, DATATYPE);
bool queue_push_by_ref(Queue_t*, const DATATYPE*);
bool queue_pop(Queue_t*, DATATYPE*);
void queue_clear(Queue_t*);

#endif // QUEUE_2_H