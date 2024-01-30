#include <stddef.h>
#include <stdlib.h>

struct sll
{
    struct node *head;
    struct node *tail;
    size_t len;
};

struct node
{
    int data;
    struct node *next;
};

int sll_push_back(struct sll *list, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        return -1;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->len++;
    return 0;
}

int sll_pop_back(struct sll *list, int *data) {
    if(list == NULL) {
        return -1;
    }
    struct node *first = list->head;
    struct node *last = NULL;

    //노드 맨 뒤 찾기.................
    while(first->next != NULL) {
        last = first;
        first = last->next;
    }

    //삭제할 노드의 데이터를 반환값으로 정하기
    *data = first->data;

    //노드 길이, tail
    list->len--;
    list->tail = last;

    if (last != NULL) {
        last->next = NULL;
    }
    else {
        //last가 NULL값?
        list->head = NULL;
    }
    free(first);
    return 0;
}

int sll_insert(struct sll *list, int data, int loc)
{
    if (list == NULL) {
        return -1;
    }

    if (loc <0) {
        return -1;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL) {
        return -1;
    }
    newNode->data = data;

    if(loc == 0) {
        //노드의 맨 앞
        newNode -> next = list->head;
        list->head = newNode;
    }

    if(list->tail == NULL) {
        list->tail = newNode;
    }
    else{
        struct node *first = list->head;
        struct node *last = NULL;
        int cnt = 0;

        while(cnt < loc) {
            last = first;
            first = first->next;
            cnt++;
        }

        last->next = newNode;
        newNode->next = first;

        if(first == NULL) {
            //리스트 맨 뒤
            list->tail = newNode;
        }
    }
    list->len++;
    return 0;
}

// int sll_remove(struct sll *, ) { //삭제
//     if (len == NULL) {
//         return -1;
//     }

// }

// int sll_search() { //탐색
//     if (len == NULL) {
//         return -1;
//     }

// }