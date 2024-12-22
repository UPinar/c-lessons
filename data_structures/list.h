#ifndef LIST_H
#define LIST_H

#include <stdbool.h>  // bool
#include <stddef.h>   // size_t

typedef int DATATYPE;

typedef struct Node {
  DATATYPE m_data;
  struct Node* mp_prev_node;
  struct Node* mp_next_node; 
} Node_t;

typedef struct List {
  Node_t* mp_head_node;
  Node_t* mp_tail_node;
  size_t  m_size;
} List_t;

/*  INLINE FUNCTIONS  */

static inline size_t list_get_size(List_t* list)
{
  return list->m_size;
}

static inline bool list_is_empty(List_t* list)
{
  return list->m_size == 0;
}

List_t* list_create(void);
void list_destroy(List_t*);

Node_t* list_push_back_by_value(List_t*, DATATYPE);
Node_t* list_push_back_by_ref(List_t*, const DATATYPE*);
Node_t* list_push_front_by_value(List_t*, DATATYPE);
Node_t* list_push_front_by_ref(List_t*, const DATATYPE*);
Node_t* list_insert_next_by_value(List_t*, Node_t*, DATATYPE);
Node_t* list_insert_next_by_ref(List_t*, Node_t*, const DATATYPE*);
Node_t* list_insert_prev_by_value(List_t*, Node_t*, DATATYPE);
Node_t* list_insert_prev_by_ref(List_t*, Node_t*, const DATATYPE*);
void list_erase(List_t*, Node_t*);
void list_pop_front(List_t*);
void list_pop_back(List_t*);
DATATYPE* list_get_item_index(List_t*, size_t);
bool list_traverse(List_t*, bool(*)(DATATYPE*));
bool list_reverse_traverse(List_t*, bool(*)(DATATYPE*));
void list_clear(List_t*);


#endif // LIST_H