#include <stdio.h>

int top =-1;
char stack[50];
int size =50;

void push(char val){
    if(top== size-1){
        printf("Stack is full");
    }
    else{
        stack[++top] = val;
    }
}
char pop(){
    if(top == -1){
        printf("Stack is empty");
        return '\0';
    }else{
        return stack[top--];
    }
}

int validate(char open , char close){
    if(
        (open == '(' && close == ')') || 
        (open == '{' && close == '}') || 
        (open == '[' && close == ']')
    ){
        return 1;
    }
    return 0;
}


int main(){
    char exp[100];
    printf("Enter expression you want to check syntax: ");
    // scanf("%s",exp);            
    // using fgets to take spaces as well as enter lines.
    fgets(exp, 100,stdin);
    int flag =1;            // using checkmark  flag=1 means valid parenthesis  (flag =0 means invalid)

    for(int i=0;exp[i] != '\0';i++){
        char ch =exp[i];
        if(ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}'){
            if(top== -1){
                flag =0;
                break;
            }
            else{
                if((!(validate(pop(),ch)))){
                    flag =0;
                    break;
                }
            }
        }
    }

    if(top != -1){
        flag =0;
    }

    if(flag == 1){
        printf("Valid parenthesis.");
    }
    else printf("invalid parenthesis");
    return 0;
}