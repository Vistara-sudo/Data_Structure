#include <stdio.h>
#define SIZE 5
    int stack[SIZE];
    int tos=-1;

    void push(int n){
        if(tos==SIZE-1){
            printf("The stack is full.\n");
        }
        else {
            tos++;
            stack[tos]=n;                   //or i can write stack[++tos];
            printf("The element you had just put in stack is: %d\n",n);
        }
    }

    void pop(){
        if(tos==-1){
            printf("The stack is empty.");
        }
        else{
            int temp = stack[tos];       // or i can write stack[tos--];
            tos--;
            printf("The removed element is %d\n",temp);
        }
    }

    void peek() {
        if (tos == -1) {
            printf("The stack is empty.\n");
        } else {
            printf("The top element in the stack is: %d\n", stack[tos]);
        }
    }

    void display() {
        if (tos == -1) {
            printf("The stack is empty.\n");
        } else {
            for (int i = tos; i >= 0; i--) {
                printf("%d ", stack[i]);
            }
            printf("\n");
        }
    }

    int main(){
        int x,n;
        while(1){
            printf("\n\t\t\t*****************************************************************************************\n");
            printf("\t\t\t=================================STACK MENU==============================================\n");
            printf("\t\t\t*****************************************************************************************\n");
            printf("Enter \n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\nChoose the option and enter the value:  ");
            scanf("%d",&x);
            if(x==1){
                printf("Enter the element to push in the stack: ");
                scanf("%d",&n);
                push(n);
            }
            else if(x==2){
                printf("Pop the element.\n");
                pop();
            }
            else if(x==3){
                printf("THe item in your stack is: ");
                display();
            }
            else if(x==4){
                peek();
            }
            else if(x==5){
                printf("\nYou have exited the loop.");
                return 0;
            }
            else{
                printf("The value you entered is wrong.Try again!..\n");
            }
    }
        return 0;
    }