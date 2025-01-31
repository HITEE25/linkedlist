#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void print(struct node* ptr){
    while(ptr != NULL){
    printf(" %d",ptr->data);
    ptr = ptr->next;
    }
}

struct node* deleteFirst(struct node* head){
    struct node* ptr = head;
    head = head->next;
    free(ptr);
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

    //connecting head and second
    head->data = 56;
    head->next = second;

    //connecting second and third
    second->data = 45;
    second->next = third;

    //third and null pointer
    third->data = 78;
    third->next = NULL;

    printf("Before deletion\n");
    print(head);
    printf("\nAfter deletion\n");
    head = deleteFirst(head);
    print(head);
}