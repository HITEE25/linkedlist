#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;
}

int main(){
    struct stack* s = (struct stack*) malloc(sizeof(struct stack));
    s->size = 56;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    s->top++;
    s->arr[s->top] = 56;
    s->top++;
    s->arr[s->top] = 90;
    s->top++;
    s->arr[s->top] = 78;
    s->top++;
    s->arr[s->top] = 90;
    if(isEmpty(s)){
        printf("stack is empty\n");
    }
    else{
        printf("stack is not empty\n");
        for(int i=0;i<=s->top;i++){
        printf(" %d",s->arr[i]);
        }
    }
    return 0;
}