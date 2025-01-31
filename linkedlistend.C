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

struct node* insertEnd(struct node* head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr ->next = NULL;
    return head;
}

int main(){
    struct node* head;
    struct node* second;
    struct node* third;

    //allocate the space in heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    //connext head and second
    head->data = 45;
    head->next = second;

    second->data = 68;
    second->next = third;

    //connect second and third
    third->data = 58;
    third->next = NULL;
    printf("Before insertion\n");
    print(head);
    printf("\nAfter insertion\n");
    insertEnd(head,45);
    print(head);
}