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
struct node* insertLast(struct node* head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
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
    head->data = 67;
    head->next = second;

    //connect second and third
    second->data = 45;
    second->next = third;

    //connect third to head
    third->data = 56;
    third->next = head;
    printf("Before insertion\n");
    print(head);
    printf("\nAfter insertion\n");
    head = insertLast(head,98);
    print(head);
}