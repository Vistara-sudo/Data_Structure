#include <stdio.h>
#include<string.h>

int top=-1;
int stack[50];
int size=50;

void push(int value){
    if(top==size-1){
        printf("The stack is full.");
    }
    else{
        stack[++top]= value;
    }
}

int pop(){
    if(top==-1){
        printf("The stack is empty.");
        return -1;
    }
    else{
        return stack[top--];
    }
}


int evaluation(int v1,int v2,char op){
        if(op == '+') return v1+v2;
        if(op == '-') return v1-v2;
        if(op == '*') return v1*v2;
        if(op == '/') return v1/v2;

        return 0;

}

int main(){

    printf("\t\t\t\t\t==================PREFIX EVALUATION============\n\n");
    
    char exp[100];
    printf("Enter the prefix expression you want to evaluate: ");
    scanf("%s",exp);

    for(int i=strlen(exp)-1;i>=0;i--){
        char ch = exp[i];

        if(ch >='0' && ch<='9'){        // If number
            push(ch - '0');        // making the character integer;
        }
        
        else{
            int v1 = pop();          
            int v2 = pop();         

            int result = evaluation(v1, v2, ch);
            push(result);
        }

    }


    int result = pop();    // by popping out we are getting the whole stack empty!!
    printf("\nThe result of this prefix evaluated expression is: %d",result);

    return 0;
}

