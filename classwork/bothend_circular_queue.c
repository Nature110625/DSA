//Circular queue
#include <stdio.h>
#include <stdlib.h>
int *que, size, front=-1, rear=-1;  //front is -1 because condition to check whether the array is full is "rear==front-1" if we put front=0 it will show full even if array is empty
void front_inque();
int front_deque();
void rear_inque();
int rear_deque();
void display();
int isempty();
int isfull();
int main(){
    int ans;
    printf("Enter the size of queue: ");
    scanf("%d", &size);
    que=(int *)malloc(size);
    printf("1. to insert in queue from front.\n2. to delete from queue from front.\n3. to insert in queue from rear.\n2. to delete from queue from rear.\n");
    printf("5. To display queue.\n6. to exit this program.\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ans);
        switch(ans){
            case 1:
                if(isfull()){
                    printf("The queue is full.\n");
                    break;
                }
                front_inque();
                break;
            case 2:
                if(isempty()){
                    printf("The queue is empty.\n");
                    break;
                }
                printf("Successfully deleted %d.\n", front_deque());
                break;
            case 3:
                if(isfull()){
                    printf("The queue is full.\n");
                    break;
                }
                rear_inque();
                break;
            case 4:
                if(isempty()){
                    printf("The queue is empty.\n");
                    break;
                }  
                printf("Successfully deleted %d.\n", rear_deque());
                break;
            case 5:
                if(isempty()){
                    printf("The queue is empty.\n");
                    break;
                }
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Entry.\n");
        }
    }while(1);
}

void display(){
    printf("Queue: ");
    for(int i=front; i<=rear; i++)
        printf("\n%d", que[i]);
}

void rear_inque(){
    int num;
    if(rear==size-1)
        rear=0;
    else
        if(isempty())
            front=rear=0;
        else
            rear++;
    printf("Enter a number to insert in queue: ");
    scanf("%d", &num);
    que[rear]=num;
}
void front_inque(){
    int num;
    if(front==0)
        front=size-1;
    else
        if(isempty())
            front=rear=0;
        else
            front--;
    printf("Enter a number to insert in queue: ");
    scanf("%d", &num);
    que[front]=num;
}
int rear_deque(){
    int val=que[rear];
    if(front==rear){
        front=-1;
        rear=-1;  
    }
    else{
        if(rear==0)
            rear=size-1;
        else
            rear--;
    }
    return val;
}
int front_deque(){
    int val=que[front];
    if(front==rear){
        front=-1;
        rear=-1;  
    }
    else{
        if(front==size-1)
            front=0;
        else
            front--;
    }
    return val;
}
int isempty(){
    if(rear==-1 && front==-1)
        return 1;
    return 0;
}
int isfull(){
    if(rear==front-1||(rear==size-1 && front==0))
        return 1;
    return 0;
}