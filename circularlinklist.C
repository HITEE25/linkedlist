#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void printCircular(struct node* head){
    struct node* ptr = head;
    do{
        printf(" %d",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

int main(){
    struct node* head;
    struct node* second;
    struct node* third;
    
    //allocate memory
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    //connect head and second
    head->data = 67;
    head->next = second;

    //connect second and third
    second->data = 45;
    second->next = third;

    //connect third and null
    third->data = 34;
    third->next = NULL;

    printCircular(head);
}