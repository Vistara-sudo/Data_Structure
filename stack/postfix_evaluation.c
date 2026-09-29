#include <stdio.h>

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


int evaluation(int v2,int v1,char op){
        if(op == '+') return v1+v2;
        if(op == '-') return v1-v2;
        if(op == '*') return v1*v2;
        if(op == '/') return v1/v2;

        return 0;

}

int main(){

    printf("\t\t\t\t\t==================POSTFIX EVALUATION============\n\n");
    
    char exp[100];
    printf("Enter the postfix expression you want to evaluate: ");
    scanf("%s",exp);

    for(int i=0;exp[i]!='\0';i++){
        char ch = exp[i];

        if(ch >='0' && ch<='9'){        // If number
            push(ch - '0');        // making the character integer;
        }
        
        else{
            int v2 = pop();          
            int v1 = pop();         

            int result = evaluation(v2, v1, ch);
            push(result);
        }

    }


    int result = pop();    // by popping out we are getting the whole stack empty!!
    printf("\nThe result of this postfix evaluated expression is: %d",result);

    return 0;
}

