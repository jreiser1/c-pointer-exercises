#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct linkedList{
    int i;
    struct linkedList* next;
} typedef t_linkedList,*p_linkedList;

p_linkedList linkedlist_init_value(int value){
    p_linkedList newNode = malloc(sizeof(t_linkedList));
    newNode->i = value;
    newNode->next = NULL;
    return newNode;
}

void linkedlist_init(p_linkedList *p_head, p_linkedList *p_tail){
    p_head[0] = linkedlist_init_value(0);
    p_tail[0] = linkedlist_init_value(0);
    p_tail[0]->next = p_head[0];
}


void list_insert(p_linkedList *p_head, p_linkedList *p_tail, int val){
    p_linkedList head, tail;
    head = p_head[0];
    tail = p_tail[0];

    if(head->next == NULL)
    {
        head->i = val;
        head->next = tail;
        return;
    }
    if(tail->next == head){
        if(head->i > val){
            int tmp = head->i;
            head->i = val;
            tail->i = tmp;
        }
        else{
            tail->i = val;
        }
        tail->next = NULL;
        return;
    }

    //add new nodes
    p_linkedList newNode = linkedlist_init_value(val);

    //check if val > tail->i
    if(val > tail->i){
        tail->next = newNode;
        p_tail[0] = newNode;
        return;
    }

    p_linkedList cur = head;
    p_linkedList prev = NULL;

    while(cur->i < val){
        prev = cur;
        cur = cur->next;
    }

    if(prev == NULL){
        newNode->next = head;
        p_head[0] = newNode;
        return;
    }

    newNode->next = cur;
    prev->next = newNode;
    return;
}

void linkedlist_free(p_linkedList *head, p_linkedList *tail){
    p_linkedList cur = *head;

    while(cur != NULL){
        p_linkedList node = cur;
        cur = cur->next;

        node->next = NULL;
        free(node);
    } head[0] = NULL; tail[0] = NULL;

    return;
}

void run_linked_list() {
    printf("Running linked list\n");
    p_linkedList head, tail;

    linkedlist_init(&head, &tail);

    //test in-order insert for head and tail
    list_insert(&head, &tail, 1);
    printf("first insert (head) condition\t\t\t\t%s\n", (head->i == 1 && head->next == tail) ? "success" : "failure");

    list_insert(&head, &tail, 2);
    printf("ascending order (tail) condition\t\t\t%s\n",
           (tail->i == 2 && head->next == tail && tail->next == NULL) ? "success" : "failure");

    free(head);
    head = NULL;
    free(tail);
    tail = NULL;

    //test out-of-order insert for head and tail
    linkedlist_init(&head, &tail);
    list_insert(&head, &tail, 2);
    list_insert(&head, &tail, 1);

    printf("descending order head-tail insert\t\t\t%s\n",
           (head->i == 1 && tail->i == 2 && head->next == tail && tail->next == NULL) ? "success" : "failure");
    free(head);
    head = NULL;
    free(tail);
    tail = NULL;

    //now test a ascending order linked list
    linkedlist_init(&head, &tail);

    for (int i = 0; i < 10; i++) {
        list_insert(&head, &tail, i);
    }

    int result = 1;
    p_linkedList current = head;

    for (int i = 0; i < 10; i++) {
        if (current->i != i) {
            result = 0;
            break;
        }
        current = current->next;
    }

    printf("10 ascending order inserts \t\t\t\t%s\n", (result == 1) ? "success" : "failure");
    current = head;

    linkedlist_free(&head, &tail);

    //test 10 random inserts
    linkedlist_init(&head, &tail);

    for (int i = 0; i < 10; i++) {
        list_insert(&head, &tail, rand() % 10);
    }

    current = head;

    while (1) {
        if (current->next == NULL)
            break;
        if (current->i > current->next->i) {
            current = NULL;
            break;
        }
        current = current->next;
    }

    printf("10 random inserts - check ascending order \t\t%s\n", (current != NULL) ? "success" : "failure");
    linkedlist_free(&head, &tail);

    printf("head and tail NULL\t\t\t\t\t%s\n", (head == NULL && tail == NULL) ? "success" : "failure");
}
