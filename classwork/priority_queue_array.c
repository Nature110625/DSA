#include <stdio.h>
int que[10], prirt[10], front=-1, rear=-1, size=10;

void inque(){
    if(rear==size-1){
        printf("Overflow");
        return;
    }
    printf("Enter value and its priority: ");
    scanf("%d%d", &que[++rear], &prirt[++rear]);
}
void display(){
    if(rear==-1){
        printf("The queue is empty.");
        return;
    }
    printf("Queue(priority): ");
    for(int i=front; i<=rear; i++)
        printf("\n%d(%d)", que[i], prirt[i]);
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

int main(){
    int ans;
    printf("1. to insert into queue \n2. to delete from queue \n3. to display queue\n4. to change priority\n5. to end program\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &ans);
        switch(ans){
            case 1: 
                inque();
                break;
            case 2: 
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                edque();
                break;
            case 5:
                return;
            default:

        }
    }
}