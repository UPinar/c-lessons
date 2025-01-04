#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>   // size_t
#include <stdbool.h>  // bool, true, false

typedef int DATATYPE;

typedef struct {
  DATATYPE* mp_arr;
  size_t    m_head_pos;   // push index
  size_t    m_tail_pos;   // pop index
  size_t    m_size;
  size_t    m_capacity;
} Queue_t, *Queue_p;

/*  INLINE FUNCTIONS  */

static inline size_t queue_get_size(Queue_p queue)
{
  return queue->m_size;
}

static inline size_t queue_get_capacity(Queue_p queue)
{
  return queue->m_capacity;
}

static inline bool queue_is_empty(Queue_p queue)
{
  return queue->m_size == 0;
}

/* FUNCTION PROTOTYPES */

Queue_p queue_create_with_capacity(size_t);
void queue_destroy(Queue_p);

bool queue_push_by_value(Queue_p, DATATYPE);
bool queue_push_by_ref(Queue_p, const DATATYPE*);
bool queue_pop(Queue_p, DATATYPE*);   // out parameter 

bool queue_increase_capacity(Queue_p, size_t);
bool queue_clear(Queue_p);

#endif // QUEUE_H