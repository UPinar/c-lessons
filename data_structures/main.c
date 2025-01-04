#include <stdio.h>

/*
                ===================================
                | Data Structures (Veri Yapıları) |
                ===================================
*/

/*
                  --------------------------------
                  | Dynamic Array (Dinamik Dizi) |
                  --------------------------------
*/

/*
  #include "vector.h"
  #include "../headers/nutility.h"

  void test_vector(Vector_p p_vec)
  {
    printf( "size = %zu, capacity = %zu\n", 
            vector_get_size(p_vec),
            vector_get_capacity(p_vec));         

    if (vector_is_empty(p_vec)){
      printf("vec = []\n");
      return;
    }
    
    printf("vec = [ ");
    for (size_t i = 0; i < vector_get_size(p_vec) - 1; ++i)
      printf("%d, ", vector_get_element(p_vec, i));

    printf("%d ]\n", 
            vector_get_element(p_vec, vector_get_size(p_vec) - 1));
  }

  int main(void)
  {
    Vector_p vec1 = vector_create();

    test_vector(vec1);
    // output ->
    //  size = 0, capacity = 16
    //  vec = []

    for(int i = 0; i < 16; ++i)
      vector_push_back(vec1, i);

    test_vector(vec1);
    // output ->
    //  size = 16, capacity = 16
    //  vec = [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    //          10, 11, 12, 13, 14, 15 ]

    vector_push_back(vec1, 111);
    test_vector(vec1);
    // output ->
    //  size = 17, capacity = 32
    //  vec = [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
    //          11, 12, 13, 14, 15, 111 ]
  }
*/

/*
                    -----------------------------
                    | Linked List (Bağlı Liste) |
                    -----------------------------
*/

/*
  - singly linked list (tekli bağlı liste)
  <---- check singly_linked_list.png ---->

  - doubly linked list (çifte bağlı liste)
  <---- check doubly_linked_list.png ---->

  - circular list (döner bağlı liste)
  <---- check circular_list_singly.png ---->
  <---- check circular_list_doubly.png ----> 

  ---------------------------------------------------------

  - does not need contiguous memory, 
    so if heap memory is fragmented 
    it can be used without a problem.

  - reaching elements with index is linear complexity O(n)

  - adding and removing elements from list is O(1) complexity

  - when swapping needs, only pointers will be swapped,
    it is better for user defined types which have large size.
     
  ---------------------------------------------------------  
*/

/*
  #include "list.h"
  #include <stdlib.h>  // exit, EXIT_FAILURE

  bool print_node_data(int* p_data)
  {
    int N;
    if ((N = printf("%d ", *p_data)) == 0)
      return false;

    return true;
  }

  int main(void)
  {
    List_t* list;

    if ((list = list_create()) == NULL)
    {
      fprintf(stderr, "cannot create list\n");
      exit(EXIT_FAILURE);
    }

    printf("list is created successfully\n");
    printf("size = %zu\n", list_get_size(list));

    Node_t* p_node;

    for (int i = 0; i < 20; ++i) {
      if ((p_node = list_push_back_by_value(list, i)) == NULL) 
      {
        fprintf(stderr, "cannot push back\n");
        exit(EXIT_FAILURE);
      }
    }
    printf("elements are pushed back successfully\n");
    printf("size = %zu\n", list_get_size(list));

    printf("traverse list\n");
    list_traverse(list, &print_node_data);
    printf("\n");

    printf("reverse traverse list\n");
    list_reverse_traverse(list, &print_node_data);
    printf("\n");

    list_clear(list);
    printf("list is cleared\n");

    if (list_is_empty(list))
      printf("list is empty\n");
    else
      printf("list is not empty\n");

    for (int i = 0; i < 20; ++i) {
      if ((p_node = list_push_front_by_value(list, i)) == NULL) 
      {
        fprintf(stderr, "cannot push front\n");
        exit(EXIT_FAILURE);
      }
    }
    printf("elements are pushed front successfully\n");

    printf("traverse list\n");
    list_traverse(list, &print_node_data);
    printf("\n");
    printf("size = %zu\n", list_get_size(list));

    while (!list_is_empty(list)){
      printf( "value = %d, size = %zu\n", 
              *list_get_item_index(list, 0),
              list_get_size(list));
      list_pop_front(list);
    }

    list_destroy(list);
    printf("list is destroyed\n");
  }

  // output ->
  //  list is created successfully
  //  size = 0
  //  elements are pushed back successfully
  //  size = 20
  //  traverse list
  //  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
  //  reverse traverse list
  //  19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
  //  list is cleared
  //  list is empty
  //  elements are pushed front successfully
  //  traverse list
  //  19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
  //  size = 20
  //  value = 19, size = 20
  //  value = 18, size = 19
  //  value = 17, size = 18
  //  value = 16, size = 17
  //  value = 15, size = 16
  //  value = 14, size = 15
  //  value = 13, size = 14
  //  value = 12, size = 13
  //  value = 11, size = 12
  //  value = 10, size = 11
  //  value = 9, size = 10
  //  value = 8, size = 9
  //  value = 7, size = 8
  //  value = 6, size = 7
  //  value = 5, size = 6
  //  value = 4, size = 5
  //  value = 3, size = 4
  //  value = 2, size = 3
  //  value = 1, size = 2
  //  value = 0, size = 1
  //  list is destroyed
*/

/*
                        ------------------
                        | Queue (Kuyruk) |
                        ------------------
*/

/*
  - queue is an abstract data type.
  - FIFO (First In First Out) principle.
*/

/*
  // queue implementation with dynamic array

  #include "queue.h"

  int main(void)
  {
    Queue_p queue = queue_create_with_capacity(5);
    if (queue == NULL) {
      fprintf(stderr, "cannot create queue\n");
      return 1;
    }

    for (int i = 10; i < 15; ++i)
      queue_push_by_value(queue, i);

    int ival;
    queue_pop(queue, &ival);
    printf("ival = %d\n", ival);      // output -> ival = 10

    queue_pop(queue, &ival);
    printf("ival = %d\n", ival);      // output -> ival = 11

    if (queue_increase_capacity(queue, 10)) {
      printf("size = %zu, capacity = %zu\n", 
              queue_get_size(queue), 
              queue_get_capacity(queue));
    }
    // output -> size = 3, capacity = 10

    while (queue_pop(queue, &ival))
      printf("ival = %d\n", ival);
    // output ->
    //  ival = 12
    //  ival = 13
    //  ival = 14

    if (queue_is_empty(queue))
      printf("queue is empty\n");
    else
      printf("queue is not empty\n");
    // output -> queue is empty

    for (int i = 10; i < 20; ++i)
      queue_push_by_value(queue, i);

    printf("size = %zu, capacity = %zu\n", 
            queue_get_size(queue), 
            queue_get_capacity(queue));
    // output -> size = 10, capacity = 10

    queue_clear(queue);

    printf("size = %zu, capacity = %zu\n", 
            queue_get_size(queue), 
            queue_get_capacity(queue));
    // output -> size = 0, capacity = 10

    queue_destroy(queue);
    queue = NULL;
  }
*/

/*
  // queue implementation with linked list

  #include "queue_2.h"

  int main(void)
  {
    Queue_t* queue = queue_create();
    if (queue == NULL) {
      fprintf(stderr, "cannot create queue\n");
      return 1;
    }

    for (int i = 10; i < 15; ++i)
      queue_push_by_value(queue, i);

    printf("size = %zu\n", queue_get_size(queue));
    // output -> size = 5

    int ival;
    queue_pop(queue, &ival);
    printf("ival = %d\n", ival);      // output -> ival = 10

    queue_pop(queue, &ival);
    printf("ival = %d\n", ival);      // output -> ival = 11

    while (queue_pop(queue, &ival))
      printf("ival = %d\n", ival);
    // output ->
    //  ival = 12
    //  ival = 13
    //  ival = 14

    if (queue_is_empty(queue))
      printf("queue is empty\n");
    else
      printf("queue is not empty\n");
    // output -> queue is empty

    for (int i = 10; i < 20; ++i)
      queue_push_by_value(queue, i);

    printf("size = %zu\n", queue_get_size(queue));
    // output -> size = 10

    queue_clear(queue);

    printf("size = %zu\n", queue_get_size(queue));
    // output -> size = 0

    queue_destroy(queue);
    queue = NULL;
  }
*/

/*
                        -----------------
                        | Stack (Yığın) |
                        -----------------
*/

/*
  - stack is an abstract data type.
  - LIFO (Last In First Out) principle.
*/

/*
  // stack implementation with dynamic array

  #include "stack.h"

  int main(void)
  {
    Stack_t* stack = stack_create_with_capacity(5ULL);
    if (stack == NULL) {
      fprintf(stderr, "cannot create stack\n");
      return 1;
    }

    for (int i = 10; i < 15; ++i)
      stack_push_by_value(stack, i);

    printf("size = %zu, capacity = %zu\n", 
            stack_get_size(stack), 
            stack_get_capacity(stack));
    // output -> size = 5, capacity = 5

    int ival;
    stack_top(stack, &ival);

    printf("stack top = %d\n", ival);      
    // output -> stack top = 14

    while (stack_pop(stack, &ival)) {
      printf( "%d is popped, size = %zu\n", 
              ival, 
              stack_get_size(stack));
    }
    // output ->
    //  14 is popped, size = 4
    //  13 is popped, size = 3
    //  12 is popped, size = 2
    //  11 is popped, size = 1
    //  10 is popped, size = 0

    for (int i = 10; i < 15; ++i)
      stack_push_by_value(stack, i);

    printf("size = %zu\n", stack_get_size(stack));
    // output -> size = 5
          
    stack_clear(stack);
    printf("size = %zu\n", stack_get_size(stack));
    // output -> size = 0

    stack_destroy(stack);
    stack = NULL;
  }
*/

/*
  // stack implementation with linked list

  #include "stack_2.h"

  int main(void)
  {
    Stack_t* stack = stack_create();
    if (stack == NULL) {
      fprintf(stderr, "cannot create stack\n");
      return 1;
    }

    for (int i = 10; i < 15; ++i)
      stack_push_by_value(stack, i);

    printf("size = %zu\n", stack_get_size(stack));
    // output -> size = 5

    int ival;
    stack_top(stack, &ival);

    printf("stack top = %d\n", ival);      
    // output -> stack top = 14

    while (stack_pop(stack, &ival)) {
      printf( "%d is popped, size = %zu\n", 
              ival, 
              stack_get_size(stack));
    }
    // output ->
    //  14 is popped, size = 4
    //  13 is popped, size = 3
    //  12 is popped, size = 2
    //  11 is popped, size = 1
    //  10 is popped, size = 0

    for (int i = 10; i < 15; ++i)
      stack_push_by_value(stack, i);

    printf("size = %zu\n", stack_get_size(stack));
    // output -> size = 5
          
    stack_clear(stack);
    printf("size = %zu\n", stack_get_size(stack));
    // output -> size = 0

    stack_destroy(stack);
    stack = NULL;
  }
*/