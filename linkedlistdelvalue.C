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

struct node* delValue(struct node* head,int value){
    struct node* p = head;
    struct node* q = head->next;
    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
    p->next = q->next;
    free(q);
    }
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
    head->data = 78;
    head->next = second;

    //connect second and third
    second->data = 45;
    second->next = third;

    //connect third to null
    third->data = 67;
    third->next = NULL;
    printf("Before deletion\n");
    print(head);
    printf("\nAfter deletion\n");
    delValue(head,45);
    print(head);
}
