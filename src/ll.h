/*
 * Copyright (C) 2024 Woohyun Joh <jeremiahjoh@sungkyul.ac.kr>
 *
 * This file is part of dslibc.
 *
 * dslibc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dslibc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stddef.h>

struct sll_node {
    int data;
    struct sll_node *next;
};

typedef struct {
    struct sll_node *head;
    struct sll_node *tail;
    size_t len;
} sll;

struct dll_node {
    int data;
    struct dll_node *next;
    struct dll_node *prev;
};

typedef struct {
    struct dll_node *head;
    struct dll_node *tail;
    size_t len;
} dll;

sll sll_new();
int sll_push_back(sll *, const int);
int sll_pop_back(sll *, int *);
int sll_insert(sll *, const int, const size_t);
int sll_remove(sll *, const size_t, int *);
int sll_getnth(sll *, const size_t, int *);
int sll_setnth(sll *, const size_t, const int);
int sll_search(sll *, const int, size_t *);
int sll_append(sll *, const sll *);
int sll_append_dll(sll *, const dll *);
void sll_free(const sll *);

dll dll_new();
int dll_push_back(dll *, const int);
int dll_pop_back(dll *, int *);
int dll_push_front(dll *, const int);
int dll_pop_front(dll *, int *);
int dll_insert(dll *, const int, const size_t);
int dll_remove(dll *, const size_t, int *);
int dll_getnth(dll *, const size_t, int *);
int dll_setnth(dll *, const size_t, const int);
int dll_search_from_front(dll *, const int, size_t *);
int dll_search_from_back(dll *, const int, size_t *);
int dll_append(dll *, const dll *);
int dll_append_sll(dll *, const sll *);
void dll_free(const dll *);
