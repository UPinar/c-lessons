#include "list.h"
#include <stdlib.h>  // malloc, free

static Node_t* get_valid_node()
{
  Node_t* p_new_node;
  if ((p_new_node = malloc(sizeof(Node_t))) == NULL)
    return NULL;

  return p_new_node;
}

// ----------------------------------------------------
// ----------------------------------------------------

List_t* list_create(void)
{
  List_t* list = malloc(sizeof(List_t));
  if (list == NULL)
    return NULL;

  list->mp_head_node = NULL;
  list->mp_tail_node = NULL;
  list->m_size = 0;

  return list;
}

// ----------------------------------------------------
// ----------------------------------------------------

void list_destroy(List_t* list)
{
  if (!list_is_empty(list))
    list_clear(list);

  free(list);
}

// ----------------------------------------------------
// ----------------------------------------------------

Node_t* list_push_back_by_value(List_t* list, DATATYPE value)
{
  Node_t* p_new_node = get_valid_node();
  p_new_node->m_data = value;

  p_new_node->mp_next_node = NULL;

  if (list_is_empty(list)) 
  {
    p_new_node->mp_prev_node = NULL;
    list->mp_head_node = p_new_node;
  }
  else 
  {
    list->mp_tail_node->mp_next_node = p_new_node;
    p_new_node->mp_prev_node = list->mp_tail_node;
  }

  list->mp_tail_node = p_new_node;
  ++list->m_size;

  return p_new_node;
}

// ----------------------------------------------------
// ----------------------------------------------------

// refactor later

Node_t* list_push_back_by_ref(List_t* list, const DATATYPE* p_value)
{
  Node_t* p_new_node = get_valid_node();
  p_new_node->m_data = *p_value;

  p_new_node->mp_next_node = NULL;

  if (list_is_empty(list)) 
  {
    p_new_node->mp_prev_node = NULL;
    list->mp_head_node = p_new_node;
  }
  else 
  {
    list->mp_tail_node->mp_next_node = p_new_node;
    p_new_node->mp_prev_node = list->mp_tail_node;
  }

  list->mp_tail_node = p_new_node;
  ++list->m_size;

  return p_new_node;
}

// ----------------------------------------------------
// ----------------------------------------------------

Node_t* list_push_front_by_value(List_t* list, DATATYPE value)
{
  Node_t* p_new_node = get_valid_node();
  p_new_node->m_data = value;

  p_new_node->mp_prev_node = NULL;

  if(list_is_empty(list)) 
  {
    list->mp_tail_node = p_new_node;
    p_new_node->mp_next_node = NULL;
  }
  else 
  {
    list->mp_head_node->mp_prev_node = p_new_node;
    p_new_node->mp_next_node = list->mp_head_node;
  }

  list->mp_head_node = p_new_node;
  ++list->m_size;

  return p_new_node;
}

// ----------------------------------------------------
// ----------------------------------------------------

Node_t* list_push_front_by_ref(List_t* list, const DATATYPE* p_value)
{
  Node_t* p_new_node = get_valid_node();
  p_new_node->m_data = *p_value;

  p_new_node->mp_prev_node = NULL;

  if(list_is_empty(list)) 
  {
    list->mp_tail_node = p_new_node;
    p_new_node->mp_next_node = NULL;
  }
  else 
  {
    list->mp_head_node->mp_prev_node = p_new_node;
    p_new_node->mp_next_node = list->mp_head_node;
  }

  list->mp_head_node = p_new_node;
  ++list->m_size;
  
  return p_new_node;
}

// ----------------------------------------------------
// ----------------------------------------------------


Node_t* list_insert_next_by_value(List_t* list, 
                                  Node_t* p_node, 
                                  DATATYPE value)
{
  Node_t* p_new_node = get_valid_node();
  p_new_node->m_data = value;

  // if p_node is the last node
  if (p_node == list->mp_tail_node) 
  {
    list->mp_tail_node->mp_next_node = p_new_node;
    p_new_node->mp_prev_node = list->mp_tail_node;
    p_new_node->mp_next_node = NULL;
  }
  else
  {
    p_new_node->mp_next_node = p_node->mp_next_node;
    p_node->mp_next_node->mp_prev_node = p_new_node;
    p_new_node->mp_prev_node = p_node;
    p_node->mp_next_node = p_new_node;
  }

  ++list->m_size;
  return p_new_node;
}

// ----------------------------------------------------
// ----------------------------------------------------

Node_t* list_insert_next_by_ref(List_t* list, 
                                Node_t* p_node, 
                                const DATATYPE* p_value)
{
  Node_t* p_new_node = get_valid_node();
  p_new_node->m_data = *p_value;

  // if p_node is the last node
  if (p_node == list->mp_tail_node) 
  {
    list->mp_tail_node->mp_next_node = p_new_node;
    p_new_node->mp_prev_node = list->mp_tail_node;
    p_new_node->mp_next_node = NULL;
  }
  else
  {
    p_new_node->mp_next_node = p_node->mp_next_node;
    p_node->mp_next_node->mp_prev_node = p_new_node;
    p_new_node->mp_prev_node = p_node;
    p_node->mp_next_node = p_new_node;
  }

  ++list->m_size;
  return p_new_node;
}

// ----------------------------------------------------
// ----------------------------------------------------

Node_t* list_insert_prev_by_value(List_t* list, 
                                  Node_t* p_node, 
                                  DATATYPE value)
{
  Node_t* p_new_node = get_valid_node();
  p_new_node->m_data = value;

  // if p_node is the first node
  if (p_node == list->mp_head_node) 
  {
    list->mp_head_node->mp_prev_node = p_new_node;
    p_new_node->mp_next_node = list->mp_head_node;
    p_new_node->mp_prev_node = NULL;
    list->mp_head_node = p_new_node;
  }
  else
  {
    p_new_node->mp_prev_node = p_node->mp_prev_node;
    p_node->mp_prev_node->mp_next_node = p_new_node;
    p_new_node->mp_next_node = p_node;
    p_node->mp_prev_node = p_new_node;
  }

  ++list->m_size;
  return p_new_node;
}

// ----------------------------------------------------
// ----------------------------------------------------

Node_t* list_insert_prev_by_ref(List_t* list, 
                                Node_t* p_node, 
                                const DATATYPE* p_value)
{
  Node_t* p_new_node = get_valid_node();
  p_new_node->m_data = *p_value;

  // if p_node is the first node
  if (p_node == list->mp_head_node) 
  {
    list->mp_head_node->mp_prev_node = p_new_node;
    p_new_node->mp_next_node = list->mp_head_node;
    p_new_node->mp_prev_node = NULL;
    list->mp_head_node = p_new_node;
  }
  else
  {
    p_new_node->mp_prev_node = p_node->mp_prev_node;
    p_node->mp_prev_node->mp_next_node = p_new_node;
    p_new_node->mp_next_node = p_node;
    p_node->mp_prev_node = p_new_node;
  }

  ++list->m_size;
  return p_new_node;
}

// ----------------------------------------------------
// ----------------------------------------------------

#include <stdio.h>  // printf

void list_erase(List_t* list, Node_t* p_node)
{
  if (list->m_size == 1)
    goto erase_label;

  if (p_node == list->mp_head_node)
  {
    p_node->mp_next_node->mp_prev_node = NULL;
    list->mp_head_node = p_node->mp_next_node;
  }
  else if (p_node == list->mp_tail_node)
  {
    p_node->mp_prev_node->mp_next_node = NULL;
    list->mp_tail_node = p_node->mp_prev_node;
  }
  else
  {
    p_node->mp_prev_node->mp_next_node = p_node->mp_next_node;
    p_node->mp_next_node->mp_prev_node = p_node->mp_prev_node;
  }

erase_label:

  --list->m_size;
  free(p_node);
}

// ----------------------------------------------------
// ----------------------------------------------------

void list_pop_front(List_t* list)
{
  list_erase(list, list->mp_head_node);
}

// ----------------------------------------------------
// ----------------------------------------------------

DATATYPE* list_get_item_index(List_t* list, size_t index)
{
  if (index >= list->m_size)
    return NULL;

  Node_t* p_current_node = list->mp_head_node;

  for (size_t i = 0; i < index; ++i) 
    p_current_node = p_current_node->mp_next_node;

  return &p_current_node->m_data;
}

// ----------------------------------------------------
// ----------------------------------------------------

bool list_traverse(List_t* list, bool(*fp)(DATATYPE*))
{
  for (Node_t* p_current_node = list->mp_head_node; 
       p_current_node != NULL; 
       p_current_node = p_current_node->mp_next_node)
  {
    if (!fp(&p_current_node->m_data))
      return false;
  }

  return true;
}

// ----------------------------------------------------
// ----------------------------------------------------

bool list_reverse_traverse(List_t* list, bool(*fp)(DATATYPE*))
{
  for (Node_t* p_current_node = list->mp_tail_node; 
       p_current_node != NULL; 
       p_current_node = p_current_node->mp_prev_node)
  {
    if (!fp(&p_current_node->m_data))
      return false;
  }

  return true;
}

// ----------------------------------------------------
// ----------------------------------------------------

void list_clear(List_t* list)
{
  Node_t* p_current_node = list->mp_head_node;
  Node_t* p_temp_node;

  while (p_current_node != NULL)
  {
    p_temp_node = p_current_node->mp_next_node;
    free(p_current_node);
    p_current_node = p_temp_node;
  }

  list->mp_head_node = NULL;
  list->mp_tail_node = NULL;
  list->m_size = 0;
}

// ----------------------------------------------------
// ----------------------------------------------------