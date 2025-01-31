#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;//to store data
    struct node* next;//to store address
};

void print(struct node* head){
    while(head != NULL){
    printf(" %d",head->data);
    head = head->next;
    }
}

struct node* insertAfter(struct node* head,struct node* prevnode,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = prevnode->next;
    ptr->data = data;
    prevnode->next = ptr;
    return head;
}

int main(){
    struct node* head;
    struct node* second;
    struct node* third;

    //allocate memory
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    //connecting head and second
    head->data = 45;
    head->next = second;

    //connecting second and third
    second->data = 45;
    second->next = third;

    //connecting third and null
    third->data = 58;
    third->next = NULL;
    printf("Before insertion\n");
    print(head);
    printf("\nAfter inertion\n");
    insertAfter(head,second,90);
    print(head);
}