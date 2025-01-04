#include "queue.h"

#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool, true, false

Queue_p queue_create_with_capacity(size_t capacity)
{
  Queue_t* queue = malloc(sizeof(Queue_t));
  if (queue == NULL)
    return NULL;

  queue->mp_arr = malloc(capacity * sizeof(DATATYPE));
  if (queue->mp_arr == NULL) {
    free(queue);
    return NULL;
  }

  queue->m_head_pos = queue->m_tail_pos = 0;
  queue->m_size = 0;
  queue->m_capacity = capacity;

  return queue;
}

// ----------------------------------------------------
// ----------------------------------------------------

void queue_destroy(Queue_p queue)
{
  free(queue->mp_arr);
  free(queue);
}

// ----------------------------------------------------
// ----------------------------------------------------

bool queue_push_by_value(Queue_p queue, DATATYPE val)
{
  if (queue->m_size == queue->m_capacity)
    return false;

  queue->mp_arr[queue->m_tail_pos] = val;

  ++queue->m_tail_pos;
  if (queue->m_tail_pos == queue->m_capacity)
    queue->m_tail_pos = 0;

  ++queue->m_size;

  return true;
}

// ----------------------------------------------------
// ----------------------------------------------------

// _ _ _ _ _ 

bool queue_push_by_ref(Queue_p queue, const DATATYPE* p_val)
{
  if (queue->m_size == queue->m_capacity)
    return false;

  queue->mp_arr[queue->m_tail_pos] = *p_val;

  ++queue->m_tail_pos;
  if (queue->m_tail_pos == queue->m_capacity)
    queue->m_tail_pos = 0;

  ++queue->m_size;

  return true;
}

// ----------------------------------------------------
// ----------------------------------------------------

bool queue_pop(Queue_p queue, DATATYPE* p_val)
{
  if (queue->m_size == 0)
    return false;

  *p_val = queue->mp_arr[queue->m_head_pos];

  ++queue->m_head_pos;
  if (queue->m_head_pos == queue->m_capacity)
    queue->m_head_pos = 0;

  --queue->m_size;

  return true;
}

// ----------------------------------------------------
// ----------------------------------------------------

bool queue_increase_capacity(Queue_p queue, size_t new_cap)
{
  if (new_cap <= queue->m_capacity)
    return false;

  DATATYPE* p_new_arr = malloc(new_cap * sizeof(DATATYPE));
  if (p_new_arr == NULL)
    return false;

  size_t temp_head = queue->m_head_pos;

  for (size_t i = 0; i < queue->m_capacity; ++i) 
  {
    p_new_arr[i] = queue->mp_arr[temp_head++];
    if (temp_head == queue->m_capacity)
      temp_head = 0;
  }

  free(queue->mp_arr);
  queue->mp_arr = p_new_arr;
  queue->m_head_pos = 0;
  queue->m_tail_pos = queue->m_size;
  queue->m_capacity = new_cap;
  
  return true;
}

// ----------------------------------------------------
// ----------------------------------------------------

bool queue_clear(Queue_p queue)
{
  queue->m_head_pos = queue->m_tail_pos = 0;
  queue->m_size = 0;

  return true;
}

// ----------------------------------------------------
// ----------------------------------------------------