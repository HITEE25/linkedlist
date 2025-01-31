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

struct node* insertion(struct node* head,int data){
    struct node* first = (struct node*)malloc(sizeof(struct node));
    first->data=data;
    first->next=head;
    return first;
}

int main(){
    struct node* head;
    struct node* second;
    struct node* third;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    //connecting head and second
    head->data=56;
    head->next=second;

    //connecting second and third
    second->data=34;
    second->next=third;

    //connexting third and null
    third->data=45;
    third->next=NULL;

    printf("Before insertion \n");
    print(head);
    printf("\n After insertion\n");
    head = insertion(head,90);
    print(head);
    return 0;
}