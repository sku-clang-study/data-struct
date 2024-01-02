#include <stddef.h>

struct node {
	void *val;
	struct node *next;
	struct node *prev;
};

typedef struct {
	struct *node head;
	struct *node tail;
	size_t val_size;
	size_t len;
} n_dll;

n_dll n_dll_new(const size_t);
int n_dll_append(n_dll *, const n_dll);
int n_dll_push_back(n_dll *, const void *);
int n_dll_pop_back(n_dll *, void *);
int n_dll_push_front(n_dll *, const void *);
int n_dll_pop_front(n_dll *, void *);
int n_dll_insert(n_dll *, const void *, size_t);
int n_dll_remove(n_dll *, void *, size_t);
int n_dll_getnth(n_dll *, const void *, size_t);
int n_dll_setnth(n_dll *, void *, size_t);
