#include <stdio.h>

    int size=5;
    int stack[5];
    int tos=-1;

    void push(int n){
        if(tos==size-1){
            printf("The stack is full.");
        }
        else {
            tos++;
            stack[tos] +=n;
            printf("The element you had just put in stack is: %d\n",n);
        }
    }

    void pop(){
        if(tos==-1){
            printf("The stack is empty.");
        }
        else{
            int temp= stack[tos];       // or i can write stack[tos--];
            tos--;
            printf("The removed element is %d\n",temp);
        }
    }

    void peek(){
        printf("The top element in the stack is: %d\n", stack[tos]);
    }

    void display(){
        for(int i=tos;i>=0;i--){
            printf("%d",stack[i]);
        }
    }

    int main(){
        int x,n;
        while(1){
            printf("\n=========================================================\n");
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