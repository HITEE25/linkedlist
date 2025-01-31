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

struct node* deleteBet(struct node* head,int idx){
    struct node* ptr = head;
    for(int i=0;ptr != NULL && i < idx - 1 ;i++){
        ptr = ptr->next;
    }
    struct node* p = ptr->next;
    ptr->next = p->next;
    free(p);
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

    //connect head and second
    head->data=78;
    head->next=second;

    //connect second and third
    second->data=80;
    second->next=third;

    //connect third and null
    third->data=90;
    third->next=NULL;
    printf("Before deletion\n");
    print(head);
    printf("\nAfter deletion\n");
    deleteBet(head,1);
    print(head);
}