#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void print(struct node* head){
    while(head != NULL){
    printf(" %d",head->data);
    head = head->next;
    }
}

struct node* linkedlistDelend(struct node* head){
    struct node* ptr = head;
    struct node* p = head->next;
    while(p->next != NULL){
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}

int main(){
    struct node* head;
    struct node* second;
    struct node* third;

    //allocate the memory
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    //connect head and second
    head->data = 67;
    head->next = second;

    //connect second and third
    second->data = 89;
    second->next = third;

    //third to null
    third->data = 68;
    third->next = NULL;

    printf("Before deletion\n");
    print(head);
    printf("\nAfter deletion\n");
    linkedlistDelend(head);
    print(head);
}