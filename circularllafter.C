#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void print(struct node* head){
    struct node* ptr = head;
    do{
        printf(" %d",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

struct node* insertAfter(struct node* head,struct node* prevnode,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = prevnode->next;
    ptr->data = data;
    prevnode->next = ptr;
    ptr->next = p;
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

    //connect first and second
    head->data = 45;
    head->next = second;

    //connect second and third
    second->data = 90;
    second->next = third;

    //connect third and head
    third->data = 80;
    third->next = head;
    printf("Before insertion\n");
    print(head);
    printf("\nAfter the insertion\n");
    insertAfter(head,second,98);
    print(head);
}