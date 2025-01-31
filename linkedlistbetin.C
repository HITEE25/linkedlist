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

struct node* insertelement(struct node* head,int data,int idx){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    for(int i=0;i!=idx-1;i++){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    return head;
}

int main(){
    struct node* head;
    struct node* second;
    struct node* third;

    //allocate memory in heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    //connecting head and second
    head->data = 45;
    head->next = second;

    //connect second and third 
    second->data = 26;
    second->next = third;

    //connect third to null pointer
    third->data = 16;
    third->next = NULL;

    printf("before inerstion\n");
    print(head);
    printf("\nafter insertion\n");
    insertelement(head,90,1);
    print(head);
}