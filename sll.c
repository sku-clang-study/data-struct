#include <stddef.h>
#include <stdlib.h>

// struct sll
// {
//     struct node *head;
//     struct node *tail;
//     size_t len;
// };

// struct node
// {
//     int data;
//     struct node *next;
// };

// int sll_push_back(struct sll *list, int data)
// {
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     if (newNode == NULL)
//     {
//         return -1;
//     }
//     newNode->data = data;
//     newNode->next = NULL;

//     if (list->head == NULL)
//     {
//         list->head = newNode;
//         list->tail = newNode;
//     }
//     else
//     {
//         list->tail->next = newNode;
//         list->tail = newNode;
//     }

//     list->len++;
//     return 0;
// }

// int sll_pop_back(struct sll *list, int *data) {
//     if(list == NULL) {
//         return -1;
//     }
//     struct node *first = list->head;
//     struct node *last = NULL;

//     //노드 맨 뒤 찾기.................
//     while(first->next != NULL) {
//         last = first;
//         first = last->next;
//     }

//     //삭제할 노드의 데이터를 반환값으로 정하기
//     *data = first->data;

//     //노드 길이, tail
//     list->len--;
//     list->tail = last;

//     if (last != NULL) {
//         last->next = NULL;
//     }
//     else {
//         //last가 NULL값?
//         list->head = NULL;
//     }
//     free(first);
//     return 0;
// }

// int sll_insert(struct sll *list, int data, int loc)
// {
//     if (list == NULL) {
//         return -1;
//     }

//     if (loc <0) {
//         return -1;
//     }

//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     if(newNode == NULL) {
//         return -1;
//     }
//     newNode->data = data;

//     if(loc == 0) {
//         //노드의 맨 앞
//         newNode -> next = list->head;
//         list->head = newNode;
//     }

//     if(list->tail == NULL) {
//         list->tail = newNode;
//     }
//     else{
//         struct node *first = list->head;
//         struct node *last = NULL;
//         int cnt = 0;

//         while(cnt < loc) {
//             last = first;
//             first = first->next;
//             cnt++;
//         }

//         last->next = newNode;
//         newNode->next = first;

//         if(first == NULL) {
//             //리스트 맨 뒤
//             list->tail = newNode;
//         }
//     }
//     list->len++;
//     return 0;
// }

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

struct sll {
    struct node *head; //첫번째 노드
    struct node *tail; //마지막 노드 포인터 변수
    size_t len; //전체 노드의 크기
};

struct node {
    int data; //동적할당 노드 데이터
    struct node *next; //다음 노드의 포인터
};

int
sll_push_back(struct sll sll, struct node new_node, int last_data) //맨 뒤에 데이터를 넣음
{ 
    if (last_data == NULL){
        return -1;
    }
    else {
        sll.head = malloc(sizeof(sll) * sll.len); //기본 할당
        sll.len += 1;
        new_node.data = last_data; //새로운 노드에 데이터를 넣음
        new_node.next = NULL; //마지막 노드임을 알려줌
        sll.tail = &new_node; //마지막 노드 포인터 값에 주소 값을 넣음
        sll.head = realloc(sll.head, sizeof(sll) * sll.len);
        return 0;
    }
}

int
sll_pop_back(struct sll sll) //맨 뒤에 값 없애기
{
    if(sll.len == 0){
        return -1;
    }
    else {
        sll.head = malloc(sizeof(sll) * sll.len); //기본 할당
        sll.tail -> data = NULL; //마지막 데이터 값을 없앰
        sll.len -= 1; // 크기를 하나 줄임
        sll.head = realloc(sll.head, sizeof(sll) * sll.len); //맨 뒤에 값을 없앤 후 재할당
        return 0;
    }
}

int
sll_insert(struct sll sll, struct node new_node, int idx, int new_data) //특정 위치에 값 삽입
{
    sll.head = malloc(sizeof(sll) * sll.len); //기본 할당
    if (sll.len == 0 || new_data == NULL){
        return -1;
    }
    else {
        new_node.data = new_data;
        sll.len += 1;
        return 0;
    }
    // sll.head = realloc(sll.head, sizeof(sll) * sll.len);
}

int
sll_remove(struct sll sll, int rm_data) //특정 값 제거
{
    sll.head = malloc(sizeof(sll) * sll.len);
    if (sll.head -> data == rm_data){ //첫번째 데이터와 특정값이 같을 때
        sll.head -> data = NULL;
        sll.len -= 1;
        sll.head = realloc(sll.head, sizeof(sll) * sll.len);
        return 0;
    }
    if (sll.head -> next -> data == rm_data){ //그 뒤의 데이터와 같을 때
        sll.head -> next -> data = NULL;
        sll.len -= 1;
        sll.head = realloc(sll.head, sizeof(sll) * sll.len);
        return 0; 
    }
    else {
        return -1;
    }
}

int
sll_search(struct sll sll, int f_data) //특정 값 찾기
{
    if (sll.head -> data == f_data){ //첫번째 데이터와 특정값이 같을 때
        return 0;
    }
    if (sll.head -> next -> data == f_data){
        return 0;
    }
    if (f_data == NULL){
        return -1;
    }
    else {
        return -1;
    }
}