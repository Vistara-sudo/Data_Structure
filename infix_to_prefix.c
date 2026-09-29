#include <stdio.h>
#include <string.h>


int valTop=-1;
int opTop=-1;


char opStack[50];
char valStack[50][100];

int size=50;

void pushVal(char value[]){
    if(valTop==size-1){
        printf("The stack is full.");
    }
    else{
        strcpy(valStack[++valTop], value);  //if in input time we make temp to convert char into string and then pass it.

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


char* popVal(){
    if(valTop==-1){
        printf("The stack is empty.");
        return "";
    }
    else{
        return valStack[valTop--];
    }
}

char popOp(){
    if(opTop==-1){
        printf("The stack is empty.");
        return '\0';
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

void infix_to_prefix(){
    char result[100]; 
    char v1[100];
    char v2[100];
    char op;

    strcpy(v2,popVal());
    strcpy(v1,popVal());
    op = popOp();

    sprintf(result,"%c%s%s",op,v1,v2);      // instead of printing it store it in result...

    pushVal(result);

}


int main(){

    printf("\t\t\t\t\t==================INFIX TO PREFIX CONVERSION============\n\n");
    
    char exp[100];
    printf("Enter the infix expression you want to convert to prefix:  ");
    scanf("%s",exp);

    for(int i=0;exp[i]!='\0';i++){
        char ch = exp[i];

        if(ch >='0' && ch<='9'){        // If number
            char temp[2] = {ch, '\0'};
            pushVal(temp);    // Making the character as string    
        }
        else if(ch == ')'){
            while(opStack[opTop] != '('){
                infix_to_prefix();
            }
            popOp();        // it will remove '('
        }
        else{
            if(opTop == -1 || ch == '(' || opStack[opTop] =='(' ){        // operator stack is empty || operator to be push is '(' || operator on opStack is '('
                pushOp(ch);
            }
            else{
                while(opTop != -1 && priority(opStack[opTop]) >= priority(ch) ){
                    infix_to_prefix();
                }
                pushOp(ch);
            }
        }
    }

            // One time traversal done and half expression is evaluated..
            // Perform the remaining operation

    while(opTop != -1){     // perform operation till the opstack get empty...
        infix_to_prefix();
    }

    char* final_result = popVal();    // by popping out we are getting the whole stack empty.

    printf("\nPreifx expression: %s",final_result);

    return 0;
}