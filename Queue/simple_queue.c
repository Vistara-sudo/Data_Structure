// -------------------- MAJOR DRAWBACKS --------------------
// 1. Fixed queue size of 5 elements.
// 2. Wasted space after dequeue operations.
// 3. Cannot reuse empty positions at the beginning.
// 4. Linear queue may report full even when some positions are empty.

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;
int count = 0;

void enqueue(int val){
    if(rear == SIZE -1){
        printf("\nQueue is full..\n");
    }
    else{
        if(front == -1){
            front = 0;
        }
        queue[++rear] = val;
        printf("\nYou have successfull enqueued.....\n");
        count++;
    }
}

int dequeue(){
    if(front == -1){
        printf("\nQueue is empty..");
        return -1;
    }
    int val = queue[front];
    count--;

    if(front == rear){          //Resetting queue if single element is present
        front = rear = -1;
    }else{
       front++;
    }
    return val;
}

void capacity(){
    printf("\nThe total element present in your queue is: %d\n",count);
}

void display(){
    if(front == -1){
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nYour queue is: ");
    for(int i = front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    printf("\n\t\t\t===================================================");
    printf("\n\t\t\t====================Queue Menu====================\n");
    printf("\t\t\t===================================================\n");
    
    
    int flag = 1;
    int val,x;
    while(flag){
        printf("\nChoose your choice: 1. Enqueue\t 2. Dequeue\t 3. Size\t 4. Display\t 5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the value you want to put in queue: ");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                if(front == -1){
                    printf("\nQueue is empty. Nothing to delete.\n");
                }else{
                    x = dequeue();
                    printf("\nDeleted element: %d\n", x);
                }
                break;
            case 3:
                capacity();
                break;
            case 4: 
                display();
                break;
            case 5:
                flag = 0;
                break;
            default:
                printf("\nPlease Enter a valid choice!!!");
        }
        
    }
    return 0;
}