#include "ll.h"
#include <stdlib.h>
#include <string.h>

sll
sll_new()
{
    sll sll = { NULL, NULL, 0 };
    return sll;
}

int
sll_push_back(sll *sll, const int data)
{
    if ((sll->head == NULL || sll->tail == NULL) && sll->len > 0)
        return -1;

    if (sll->head == NULL) {
        sll->head = sll->tail = malloc(sizeof(struct sll_node));
        sll->head->data = data;
        sll->head->next = NULL;
    } else {
        sll->tail->next = malloc(sizeof(struct sll_node));
        sll->tail->next->data = data;
        sll->tail->next->next = NULL;
        sll->tail = sll->tail->next;
    }

    sll->len++;

    return 0;
}

int
sll_pop_back(sll *sll, int *data)
{
    if (sll->len == 0)
        return -1;
    
    *data = sll->tail->data;
    free(sll->tail);

    if (sll->len == 1) {
        sll->head = sll->tail = NULL;
    } else {
        struct sll_node *tmp = sll->head;
        for (size_t i = 0; i < sll->len - 2; i++)
            tmp = tmp->next;
        sll->tail = tmp;
        sll->tail->next = NULL;
    }

    sll->len--;

    return 0;
}

int
sll_insert(sll *sll, const int data, const size_t at)
{
    if (sll->len < at)
        return -1;
    else if (sll->len == at)
        sll_push_back(sll, data);
    else {
        struct sll_node *tmp = sll->head;
        for (size_t i = 0; i < at - 1; i++)
            tmp = tmp->next;
        struct sll_node *ori = tmp->next;
        tmp->next = malloc(sizeof(struct sll_node));
        tmp->next->data = data;
        tmp->next->next = ori;
    }

    return 0;
}

int
sll_remove(sll *sll, const size_t at, int *data)
{
    if (sll->len <= at)
        return -1;
    
    struct sll_node *tmp = sll->head;
    for (size_t i = 0; i < at - 1; i++)
        tmp = tmp->next;
    struct sll_node *rmv = tmp->next;
    *data = rmv->data;
    tmp->next = rmv->next;
    free(rmv);

    return 0;
}

int
sll_getnth(sll *sll, const size_t at, int *data)
{
    if (sll->len <= at)
        return -1;

    struct sll_node *tmp = sll->head;
    for (size_t i = 0; i < at; i++)
        tmp = tmp->next;
    *data = tmp->data;

    return 0;
}

int
sll_setnth(sll *sll, const size_t at, const int data)
{
    if (sll->len <= at)
        return -1;

    struct sll_node *tmp = sll->head;
    for (size_t i = 0; i < at; i++)
        tmp = tmp->next;
    tmp->data = data;

    return 0;
}

int
sll_search(sll *sll, const int data, size_t *at)
{
    struct sll_node *tmp = sll->head;
    for (*at = 0; tmp != NULL; (*at)++) {
        if (tmp->data == data)
            return 0;
        tmp = tmp->next;
    }

    return -1;
}

int
sll_append(sll *l_sll, const sll *r_sll)
{
    if (r_sll->len == 0)
        return 0;
    if (l_sll->len == 0) {
        memcpy(l_sll, r_sll, sizeof(sll));
        return 0;
    }

    l_sll->tail->next = r_sll->head;
    l_sll->len += r_sll->len;

    return 0;
}

int
sll_append_dll(sll *sll, const dll *dll)
{
    /* TODO */

    return 0;
}

static void
sll_node_free(struct sll_node *node)
{
    if (node != NULL)
        sll_node_free(node->next);
    free(node);
}

void
sll_free(const sll *sll)
{
    sll_node_free(sll->head);
}

dll
dll_new()
{
    dll dll = { NULL, NULL, 0 };
    return dll;
}

int
dll_push_back(dll *dll, const int data)
{
    if ((dll->head == NULL || dll->tail == NULL) && dll->len > 0)
        return -1;

    if (dll->head == NULL) {
        dll->head = dll->tail = malloc(sizeof(struct dll_node));
        dll->head->data = data;
        dll->head->next = NULL;
        dll->head->prev = NULL;
    } else {
        dll->tail->next = malloc(sizeof(struct dll_node));
        dll->tail->next->data = data;
        dll->tail->next->next = NULL;
        dll->tail->next->prev = dll->tail;
        dll->tail = dll->tail->next;
    }

    dll->len++;

    return 0;
}

int
dll_pop_back(dll *dll, int *data)
{
    if (dll->len == 0)
        return -1;

    *data = dll->tail->data;
    struct dll_node *prev = dll->tail->prev;
    free(dll->tail);
    dll->tail = prev;
    dll->tail->next = NULL;
    dll->len--;

    if (dll->len == 0)
        dll->head = dll->tail = NULL;

    return 0;
}

int
dll_push_front(dll *dll, const int data)
{
    if ((dll->head == NULL || dll->tail == NULL) && dll->len > 0)
        return -1;

    if (dll->head == NULL) {
        dll->head = dll->tail = malloc(sizeof(struct dll_node));
        dll->head->data = data;
        dll->head->next = NULL;
        dll->head->prev = NULL;
    } else {
        dll->head->prev = malloc(sizeof(struct dll_node));
        dll->head->prev->data = data;
        dll->head->prev->prev = NULL;
        dll->head->prev->next = dll->head;
        dll->head = dll->head->prev;
    }

    dll->len++;
    
    return 0;
}

int
dll_pop_front(dll *dll, int *data)
{
    if (dll->len == 0)
        return -1;

    *data = dll->head->data;
    struct dll_node *next = dll->head->next;
    free(dll->head);
    dll->head = next;
    dll->head->prev = NULL;
    dll->len--;

    if (dll->len == 0)
        dll->head = dll->tail = NULL;

    return 0;
}

int
dll_insert(dll *dll, const int data, const size_t at)
{
    return 0;
}

static void
dll_node_free(struct dll_node *node)
{
    if (node != NULL)
        dll_node_free(node->next);
    free(node);
}

void
dll_free(const dll *dll)
{
    dll_node_free(dll->head);
}

/* TEST */
#include <stdio.h>
#include <assert.h>

void
print_ll(dll ll)
{
    struct dll_node *tmp = ll.head;
    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

int
main()
{
    dll dll = dll_new();
    dll_push_back(&dll, 1);
    dll_push_back(&dll, 3);

    dll_insert(&dll, 2, 1);

    print_ll(dll);

    return 0;
}
