#include "queue_2.h"

#include <stdbool.h>  // bool, true, false
#include <stdlib.h>   // malloc, free

// ----------------------------------------------
// ----------------------------------------------

Queue_t* queue_create(void)
{
  Queue_t* queue = malloc(sizeof(Queue_t));
  if (queue == NULL)
    return NULL;

  queue->mp_head_node = queue->mp_tail_node = 0;
  queue->m_size = 0;

  return queue;
}

// ----------------------------------------------
// ----------------------------------------------

static void free_all_nodes(Queue_t* queue)
{
  Node_t* p_current_node = queue->mp_head_node;

  Node_t* p_temp_node;
  while (p_current_node != NULL)
  {
    p_temp_node = p_current_node;
    p_current_node = p_current_node->mp_next_node;
    free(p_temp_node);
  }
}

// ----------------------------------------------
// ----------------------------------------------

void queue_destroy(Queue_t* queue)
{
  if (queue == NULL)
    return;

  free_all_nodes(queue);
  free(queue);
}

// ----------------------------------------------
// ----------------------------------------------

void queue_clear(Queue_t* queue)
{
  if (queue == NULL)
    return;

  free_all_nodes(queue);

  queue->mp_head_node = queue->mp_tail_node = NULL;
  queue->m_size = 0;
}

// ----------------------------------------------
// ----------------------------------------------

bool queue_push_by_value(Queue_t* queue, DATATYPE val)
{
  Node_t* p_new_node = malloc(sizeof(Node_t));
  if (p_new_node == NULL)
    return false;

  p_new_node->m_data = val;
  p_new_node->mp_next_node = NULL;

  if (queue->m_size == 0) 
  {
    queue->mp_head_node = p_new_node;
    queue->mp_tail_node = p_new_node;
  }
  else
  {
    queue->mp_tail_node->mp_next_node = p_new_node;
    queue->mp_tail_node = p_new_node;
  }

  ++queue->m_size;

  return true;
}

// ----------------------------------------------
// ----------------------------------------------

bool queue_push_by_ref(Queue_t* queue, const DATATYPE* p_val)
{
  Node_t* p_new_node = malloc(sizeof(Node_t));
  if (p_new_node == NULL)
    return false;

  p_new_node->m_data = *p_val;
  p_new_node->mp_next_node = NULL;

  if (queue->m_size == 0) 
  {
    queue->mp_head_node = p_new_node;
    queue->mp_tail_node = p_new_node;
  }
  else
  {
    queue->mp_tail_node->mp_next_node = p_new_node;
    queue->mp_tail_node = p_new_node;
  }

  ++queue->m_size;

  return true;
}

// ----------------------------------------------
// ----------------------------------------------

bool queue_pop(Queue_t* queue, DATATYPE* p_val)
{
  if (queue->m_size == 0)
    return false;

  Node_t* p_pop_node = queue->mp_head_node;
  *p_val = p_pop_node->m_data;

  if (queue->m_size == 1) 
  {
    queue->mp_tail_node = NULL;
    queue->mp_head_node = NULL;
  }
  else
    queue->mp_head_node = p_pop_node->mp_next_node;

  free(p_pop_node);
  --queue->m_size;

  return true;
}

// ----------------------------------------------
// ----------------------------------------------