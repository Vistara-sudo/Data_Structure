// -------------------- MAJOR DRAWBACKS OF THIS CODE --------------------
// 1. Supports only single-digit operands.
// 2. Does not validate the prefix expression.
// 3. May produce incorrect output for invalid expressions.
// 4. Does not properly handle multiple spaces or tabs.
// 5. Fixed stack size and expression size.
// 7. Assumes every non-digit character is an operator.


#include <stdio.h>
#include<string.h>

int top =-1;
char stack[100][200];
int size = 100;

void push(char* value){                 //char * reason 
   if(top == size-1){
        printf("Stack is full.");
   }
   else{
        strcpy(stack[++top],value);
   }
}

char* pop(){
    if(top == -1){
        printf("The stack is empty.");
        return "";
    }
    else{
        return stack[top--];
    }
}

int main(){
    char exp[200];
    printf("\n============================Prefix to Postfix Conversion code===============================\n");
    printf("Enter the expression: ");
    fgets(exp,200,stdin);

    for(int i =strlen(exp)-1; i >= 0;i--){
        char ch = exp[i];

        if(ch == '\n' || ch == ' '){
            continue;
        }

        if(ch>= '0' && ch<= '9'){
            char temp[2] = {ch,'\0'};
            push(temp);             //Passing string by concatenation..
        }
        else{
            char *v1 =pop();        //first pop = left operand
            char *v2 =pop();        //second pop = right operand

            char res[200];
            sprintf(res, "%s%s%c", v1, v2, ch);

            push(res);
        }
    }
    char *result = pop();
    printf("postfix expression : %s",result);

    return 0;
}