#include <stdio.h>


int valTop=-1;
int opTop=-1;


char opStack[50];
int valStack[50];

int size=50;

void pushVal(int value){
    if(valTop==size-1){
        printf("The stack is full.");
    }
    else{
        valStack[++valTop]= value;
    }
}

void pushOp(char op){
    if(opTop==size-1){
        printf("The stack is full.");
    }
    else{
        opStack[++opTop]= op;
    }
}



int popVal(){
    if(valTop==-1){
        printf("The stack is empty.");
        return -1;
    }
    else{
        return valStack[valTop--];
    }
}

char popOp(){
    if(opTop==-1){
        printf("The stack is empty.");
        return -1;
    }
    else{
        return opStack[opTop--];
    }
}

int priority(char op){
    if(op == '+' || op == '-')
        return 1;

    if(op == '*' || op == '/')
        return 2;

    return 0;
}

int evaluation(int v2,int v1,char op){
        if(op == '+') return v1+v2;
        if(op == '-') return v1-v2;
        if(op == '*') return v1*v2;
        if(op == '/') return v1/v2;

        return 0;

}

int main(){

    printf("\t\t\t\t\t==================INFIX EVALUATION============\n\n");
    
    char exp[100];
    printf("Enter the infix expression you want to evaluate: ");
    scanf("%s",exp);

    for(int i=0;exp[i]!='\0';i++){
        char ch = exp[i];

        if(ch >='0' && ch<='9'){        // If number
            pushVal(ch - '0');        // making the character integer;
        }
        else if(ch == ')'){
            while(opStack[opTop] != '('){
                    int v2 = popVal();          
                    int v1 = popVal();          
                    char op = popOp();

                    int result = evaluation(v2, v1, op);

                    pushVal(result);  
            }
            popOp();        // it will remove '('
        }
        else{
            if(opTop == -1 || ch == '(' || opStack[opTop] =='(' ){        // operator stack is empty || operator to be push is '(' || operator on opStack is '('
                pushOp(ch);
            }
            else{
                while(opTop != -1 && priority(opStack[opTop]) >= priority(ch) ){
                    int v2 = popVal();          // v2 is top most element in stack
                    int v1 = popVal();          //v1 is the bottom element
                    char op = popOp();

                    int result = evaluation(v2, v1, op);

                    pushVal(result);
                }
                pushOp(ch);
            }
        }
    }

            // One time traversal done and half expression is evaluated..
            // Perform the remaining operation

    while(opTop != -1){     // perform operation till the opstack get empty...

        int v2 = popVal();
        int v1 = popVal();
        char op = popOp();

        int result = evaluation(v2, v1, op);

        pushVal(result);
    }

    int final_result = popVal();    // by popping out we are getting the whole stack empty.

    printf("\nThe result of this infix evaluated expression is: %d",final_result);

    return 0;
}

