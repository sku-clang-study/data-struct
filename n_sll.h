#include <stddef.h>

struct node {
	void *data;
	struct node *next;
};

typedef struct {
	struct node *head;
	struct node *tail;
	size_t val_size;
	size_t len;
} sll;

n_sll n_sll_new(size_t);
int n_sll_push(struct n_sll *, const void *);
int n_sll_pop(struct n_sll *, const void *);
int n_sll_append(struct n_sll *, struct n_sll);
int n_sll_insert(struct n_sll *, void *, size_t);
int n_sll_insert_sll(struct n_sll *, struct n_sll, size_t);
int n_sll_remove(struct n_sll *, void *);
int n_sll_remove_sll(struct n_sll *, struct n_sll);
int n_sll_getnth(struct n_sll *, size_t, void *);
int n_sll_setnth(struct n_sll *, size_t, void *);
