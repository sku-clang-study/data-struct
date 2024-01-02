#include <stddef.h>

typedef struct {
	void *val;
	size_t val_size;
	size_t len;
} n_vector;

n_vector n_vector_new(const size_t);
n_vector n_vector_from(const void *, const size_t, const size_t);
int n_vector_append(n_vector *, const n_vector);
int n_vector_push_back(n_vector *, const void *);
int n_vector_pop_back(n_vector *, void *);
int n_vector_push_front(n_vector *, const void *);
int n_vector_pop_front(n_vector *, void *);
int n_vector_insert(n_vector *, const size_t, const void *);
int n_vector_insert_vec(n_vector *, const n_vector, const size_t);
int n_vector_remove(n_vector *, const size_t, void *);
int n_vector_setnth(n_vector *, const size_t, const void *);
int n_vector_getnth(n_vector *, const size_t, void *);
void n_vector_free(n_vector *);
