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

struct node* insertFirst(struct node* head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = head->next;
    while(p->next != head){
        p = p->next;
    }//now it has been reached to last value before head
    p->next = ptr;
    ptr->next = head;
    head = ptr;
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
    head->data=67;
    head->next=second;

    //connecting second and third
    second->data=45;
    second->next=third;

    //connecting third to null
    third->data=56;
    third->next=head;
    printf("Before insertion\n");
    print(head);
    printf("\nAfter insertion\n");
    head = insertFirst(head,89);
    print(head);
}