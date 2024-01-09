# Data Structure Library for C
A collection of data useful data structures written in C99.

## Data structures
| file name | data structure name | insert | remove | search |
|-----------|---------------------|--------|--------|--------|
| ll.h | (double, singly)linked list | O(1) | O(n) | O(n) |
| avl\_map.h, avl\_set.h | avl tree | O(log~2~n) | O(log~2~n) | O(log~2~n) |
| rb\_map.h, rb\_set.h | Red-Black tree | O(log~2~n) | O(log~2~n) | O(log~2~n) |
| splay\_map.h, splay\_set.h | Splay tree | O(log~2~n) ~ O(n) | O(log~2~n) ~ O(n) | O(log~2~n) ~ O(n) |
| hash\_map.h, hash\_set.h | Hash table | O(1) ~ O(n) | O(1) ~ O(n) | O(1) ~ O(n) |