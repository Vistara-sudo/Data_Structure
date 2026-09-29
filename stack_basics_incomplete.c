#include <stdio.h>

int tos=-1;
int stack[50];
int size=50;

void push(int value){
    if(tos==size-1){
        printf("The stack is full.");
    }
    else{
        stack[++tos]= value;
    }
    printf("The item you just pushed in stack is: %d",value);
}

int pop(){
    if(tos==-1){
        printf("The stack is empty.");
    }
    else{
        return stack[tos--];
    }
}
int main(){
    int x,n;
    printf("==============================");
    return 0;
}