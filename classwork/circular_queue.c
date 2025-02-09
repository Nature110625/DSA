//Circular queue
#include <stdio.h>
#include <stdlib.h>
int *que, size, front=-1, rear=-1;  //front is -1 because condition to check whether the array is full is "rear==front-1" if we put front=0 it will show full even if array is empty
void inque();
int deque();
void display();
int isempty();
int isfull();
int main(){
    int ans;
    printf("Enter the size of queue: ");
    scanf("%d", &size);
    que=(int *)malloc(size);
    printf("1. to insert in queue.\n2. to delete from queue.\n3. To display queue.\n4. to exit this program.\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ans);
        switch(ans){
            case 1:
                if(isfull())
                    break;
                inque();
                break;
            case 2:
                if(isempty())
                    break;  
                printf("Successfully deleted %d.\n", deque());
                break;
            case 3:
                if(isempty())
                    break;
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Entry.\n");
        }
    }while(1);
}

void display(){
    printf("Queue: ");
    for(int i=front; i<size ; i++)
        printf("\n%d", que[i]);
}

void inque(){
    int num;
    if(rear==size-1)
        rear=0;
    else
        front=front==-1?0:front;
        rear++;
    printf("Enter a number to insert in queue: ");
    scanf("%d", &num);
    que[rear]=num;
}
int deque(){
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
    if(rear==-1){
        printf("The queue is empty.\n");
        return 1; 
    }
    return 0;
}
int isfull(){
    if(rear==front-1||(rear==size-1 && front==0)){
        printf("The queue is full.\n");
        return 1;
    }
    return 0;
}