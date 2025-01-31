#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;//stores number
    struct node* next;//points towards next element of same type
};//it is called self-referenced

void print(struct node* ptr){
    while(ptr != NULL){
    printf(" %d",ptr->data);
    ptr = ptr->next;
    }
}

int main(){
    struct node* head;
    struct node* second;
    struct node* third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    //connecting head and second
    head->data = 8;
    head->next = second;

    //connecting second and third
    second->data = 7;
    second->next = third;

    //third pointing towards null
    third->data = 11;
    third->next = NULL;
    print(head);
    return 0;
}

