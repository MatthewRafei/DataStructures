#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "main.h"

struct double_qeue_head {
    struct double_qeue *front;
    struct double_qeue *back;
    int size;
};

struct double_qeue {
    int value;
    struct double_qeue *next;
    struct double_qeue *prev;
};

struct double_qeue *make_qeue(int value)
{
    struct double_qeue *new_qeue = malloc(sizeof(struct double_qeue));
    if(!new_qeue){
        printf("malloc failed\n");
        exit(1);
    }

    new_qeue->value = value;

    return new_qeue;
}

void push_front(struct double_qeue_head *head, int value)
{
    struct double_qeue *new_qeue = make_qeue(value);

    if(head->size >= 1){
        new_qeue->next = head->front;
        head->front = new_qeue;
    }
    else{
        head->front = new_qeue;
    }


    head->size++;
}

void push_back(struct double_qeue_head *head, int value)
{
    struct double_qeue *new_qeue = make_qeue(value);

    if(head->size >= 1){
        new_qeue->next = head->back;
        head->back = new_qeue;
    }
    else{
        head->back = new_qeue;
    }
    head->size++;
}

void print_front(struct double_qeue_head *head)
{
    printf("The value at the front is %d\n", head->front->value);
}

void print_back(struct double_qeue_head *head)
{
    if(head->back->value){
        printf("This is NULL\n");
    }
    printf("The value at the front is %d\n", head->back->value);
}

void pop_front(struct double_qeue_head *head)
{
    if(!head->front){
        printf("double qeue is empty\n");
        return;
    }

    struct double_qeue *tmp = head->front;
    if(head->size > 1){
        head->front = head->front->next;
        head->front->prev = NULL;
    }
    else{
        head->front = NULL;
        head->back = NULL;
    }
    free(tmp);
    head->size--;
    tmp = NULL;
}

void pop_back(struct double_qeue_head *head)
{
    if(!head->back){
        printf("Double qeue is empty\n");
        return;
    }

    struct double_qeue *tmp = head->back;
    if(head->size > 1){
        head->back = head->back->prev;
        if(head->back){
            head->back->next = NULL;
        }
    }
    else{
        head->front = NULL;
        head->back = NULL;
    }
    free(tmp);
    head->size--;
    tmp = NULL;
}

void print_queue_front(struct double_qeue_head const *head) {
    struct double_qeue *n = head->front;
    for(int i = 0; i < head->size; i++){
        printf("[%d] -> ", n->value);
        if(!n->next){
            break;
        }
        n = n->next;
    }
    printf("\n");
}

void print_queue_back(struct double_qeue_head const *head) {
    struct double_qeue *n = head->back;
    for(int i = 0; i < head->size; i++){
        printf("[%d] -> ", n->value);
        if(!n->prev){
            break;
        }
        n = n->prev;
    }
    printf("\n");
}

int main(void)
{
    struct double_qeue_head deqeue;
    deqeue.size = 0;

    push_front(&deqeue, 7);
    push_front(&deqeue, 10);
    push_back(&deqeue, 11);
    push_back(&deqeue, 12);

    print_queue_front(&deqeue);
    // Something is wrong with the way I'm doing this
    // need to redo the push back
    print_queue_back(&deqeue);


    /*
    push_front(&deqeue, 7);
    push_front(&deqeue, 10);
    push_back(&deqeue, 11);
    push_back(&deqeue, 12);
    print_front(&deqeue);
    print_back(&deqeue);

    pop_front(&deqeue);
    print_front(&deqeue);
    //pop_back(&deqeue);
    print_back(&deqeue);
    */

    return 0;
}
