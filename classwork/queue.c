//Normal queue
#include <stdio.h>
#include <stdlib.h>
int *que, size, front=0, rear=-1;
void inque();
int deque();
void display();
int main(){
    int ans;
    printf("Enter the size of queue: ");
    scanf("%d", &size);
    que=(int *)malloc(size*sizeof(int));
    printf("1. to insert in queue.\n2. to delete from queue.\n3. To display queue.\n4. to exit this program.");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ans);
        switch(ans){
            case 1:
                inque();
                break;
            case 2:
                ans=deque();
                printf("Successfully deleted %d.", ans);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Entry.");
        }
    }while(1);
}

void display(){
    if(rear==-1){
        printf("The queue is empty.");
        return;
    }
    printf("Queue: ");
    for(int i=front; i<=rear; i++)
        printf("\n%d", que[i]);
}

void inque(){
    int num;
    if(rear==size-1){
        printf("Overflow");
        return;
    }
    printf("Enter a number to insert in queue: ");
    scanf("%d", &que[++rear]);
}
int deque(){
    if(rear==-1){
        printf("underflow");
        return -1;
    }
    int val=que[front];
    front++;
    if(front==rear+1){
        front=0;
        rear=-1;
    }
    return val;
}