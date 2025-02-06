#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;    
        }
    return 0;
}

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

void push(struct stack* ptr,int value){
    if(isFull(ptr)){
        printf("stack overflow ,%d can not be added\n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("stack underflow ,element can not be removed ");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack* ptr,int i){
    int idx = ptr->top-i+1;
    if(idx<0){
        return -1;
    }
    else{
        return ptr->arr[idx];
    }
}

int topmost(struct stack* ptr){
    return ptr->arr[ptr->top];
}

int bottom(struct stack* ptr){
    return ptr->arr[0];
}

int main(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    push(s,34);
    push(s,89);
    push(s,78);
    push(s,60);
    push(s,48);
    pop(s);
    if(isEmpty(s)){
        printf("Empty");
    }
    else{
        for(int i=0;i<=s->top;i++){
            printf(" %d",s->arr[i]);
        }
    }
    if(isFull(s)){
        for(int i=0;i<=s->top;i++){
            printf(" %d",s->arr[i]);
        }
    }
    int removed = pop(s);
    if(removed != -1){
    printf("\n%d element has been removed\n",removed);
    }
    for(int i=1;i <= s->top+1;i++){
        printf("number at position %d is %d\n",i,peek(s,i));
    }
    printf("Top most element is %d\n",topmost(s));
    printf("bottom element is %d\n",bottom(s));
    return 0;
}