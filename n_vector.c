#include "n_vector.h"
#include <stdlib.h>
#include <string.h>

static size_t
vec_index(n_vector *vec, const size_t off)
{
	return vec->val_size * off;
}

n_vector
n_vector_new(const size_t val_size)
{
	n_vector vec;
	vec.val = malloc(0);
	vec.val_size = val_size;
	vec.len = 0;

	return vec;
}

n_vector
n_vector_from(const void *arr,
			  const size_t val_size,
			  const size_t len)
{
	n_vector vec;
	vec.val = malloc(val_size * len);
	vec.val_size = val_size;
	vec.len = len;

	memcpy(vec.val, arr, val_size * len);

	return vec;
}

int
n_vector_append(n_vector *l_vec, const n_vector r_vec)
{
	if (l_vec->val_size != r_vec.val_size)
		return -1;

	if (l_vec->len == 0)
		*l_vec = r_vec;
	else {
		size_t new_len = l_vec->len + r_vec.len;
		l_vec->val = realloc(l_vec->val, vec_index(l_vec, new_len));
		memcpy(l_vec->val + vec_index(l_vec, l_vec->len),
			   r_vec.val,
			   vec_index(l_vec, r_vec.len));
		l_vec->len = new_len;
	}

	return 0;
}

int
n_vector_push_back(n_vector *vec, const void *val)
{
	if (val == NULL)
		return -1;

	vec->val = realloc(vec->val, ++vec->len * vec->val_size);
	memcpy(vec->val + vec_index(vec, vec->len - 1), val, vec->val_size);
	
	return 0;
}

int
n_vector_pop_back(n_vector *vec, void *val)
{
	if (vec->len == 0)
		return -1;

	memcpy(val, vec->val + vec_index(vec, vec->len - 1), vec->val_size);
	vec->val = realloc(vec->val, vec_index(vec, --vec->len));
	
	return 0;
}

int
n_vector_push_front(n_vector *vec, const void *val)
{
	if (val == NULL)
		return -1;

	vec->val = realloc(vec->val, vec_index(vec, ++vec->len));
	memmove(vec->val + vec_index(vec, 1),
			vec->val,
			vec_index(vec, vec->len - 1));
	memcpy(vec->val, val, vec->val_size);

	return 0;
}

int
n_vector_pop_front(n_vector *vec, void *val)
{
	if (vec->len == 0)
		return -1;

	memcpy(val, vec->val, vec->val_size);
	memmove(vec->val,
			vec->val + vec_index(vec, 1),
			vec_index(vec, vec->len - 1));
	vec->val = realloc(vec->val, vec_index(vec, --vec->len));

	return 0;
}

int
n_vector_insert(n_vector *vec, const size_t idx, const void *val)
{
	if (vec->len == 0)
		return -1;
	
	vec->val = realloc(vec->val, vec_index(vec, ++vec->len));
	memmove(vec->val + vec_index(vec, idx + 1),
			vec->val + vec_index(vec, idx),
			vec_index(vec, vec->len) - vec_index(vec, idx));
	memcpy(vec->val + vec_index(vec, idx), val, vec->val_size);
	
	return 0;
}

int
n_vector_insert_vec(n_vector *vec, const n_vector sub, const size_t idx)
{
	/* homework */
}

int
n_vector_remove(n_vector *vec, const size_t idx, void *val)
{
	if (vec->len == 0)
		return -1;
	
	memcpy(val, vec->val + vec_index(vec, idx), vec->val_size);
	memmove(vec->val + vec_index(vec, idx),
			vec->val + vec_index(vec, idx + 1),
			vec_index(vec, vec->len) - vec_index(vec, idx));
	vec->val = realloc(vec->val, vec_index(vec, --vec->len));

	return 0;
}

int
n_vector_getnth(n_vector *vec, const size_t idx, void *val)
{
	if (vec->len == 0 || idx >= vec->len)
		return -1;

	memcpy(val, vec->val + vec_index(vec, idx), vec->val_size);

	return 0;
}

int
n_vector_setnth(n_vector *vec, const size_t idx, const void *val)
{
	if (vec->len == 0 || idx >= vec->len)
		return -1;

	memcpy(vec->val + vec_index(vec, idx), val, vec->val_size);

	return 0;
}

void
n_vector_free(n_vector *vec)
{
	free(vec->val);
}
