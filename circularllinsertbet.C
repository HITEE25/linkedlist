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

struct node* insertBet(struct node* head,int data,int idx){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p =head;
    struct node* q =head->next;
    ptr->data = data;
    for(int i=0;i< idx - 1;i++){
        p = p->next;
        q = q->next;
    }
    ptr->next = q;
    p->next = ptr;
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
    head->data = 78;
    head->next = second;

    //connect second and third
    second->data = 56;
    second->next = third;

    //connect third to head
    third->data = 34;
    third->next = head;
    printf("Before insertion\n");
    print(head);
    printf("\nAfter insertion\n");
    insertBet(head,45,2);
    print(head);
}