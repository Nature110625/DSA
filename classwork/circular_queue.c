//Circular queue
#include <stdio.h>
#include <stdlib.h>
int *que, size, front=-1, rear=-1;  //front is -1 because condition to check whether the array is full is "rear==front-1" if we put front=0 it will show full even if array is empty
void inque();
int deque();
void display();
int isempty();  //return true when queue is empty
int isfull();   //return true when queue is full
int main(){
    int ans;
    printf("Enter the size of queue: ");
    scanf("%d", &size);
    que=(int *)malloc(size*sizeof(int));
    printf("1. to insert in queue.\n2. to delete from queue.\n3. To display queue.\n4. to exit this program.\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ans);
        switch(ans){
        case 1:
            if(isfull()){
                printf("The queue is full");
                break;
            }
            inque();
            break;
        case 2:
            if(isempty()){
                printf("The queue is empty");
                break;
            }
            printf("Successfully deleted %d.", deque());
            break;
        case 3:
            if(isempty()){
                printf("The queue is empty");
                break;
            }
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Entry.");
        }
    } while(1);
}

int isfull(){
    if(rear-front==size-1||front-rear==1)   //true when (front is at 0 and rear is at size-l) OR (front is one greater than rear)
        return 1;
    return 0;
}
int isempty(){
    if(rear==-1&&front==-1)
        return 1;
    return 0;
}
void display(){
    if(rear<front){
        for(int i=front; i<size; i++)
            printf("%d\n", que[i]);
        for(int i=0; i<=rear; i++)
            printf("%d\n", que[i]);
    }
    else
        for(int i=front; i<=rear; i++)
            printf("%d\n", que[i]);
}
void inque(){
    int val;
    if(isempty()){  
        rear=front=0;   //update front and rear from -1 to 0, if first element of queue
    }
    else{
        if(rear==size-1)    //if queue is not full and last element is at siz-1 index, the next element will get added at 0th index
            rear=0;
        else
            rear++;
    }
    printf("Enter a number to insert in the queue: ");
    scanf("%d", &val);
    que[rear]=val;
}

// updates the front counter from present index to index just above it.
int deque(){
    int val=que[front];     
    if(front==size-1)   
        front=0;    //if queue is not empty in the circular queue the index just above the index size-l is 0th index
    else
        front++;
    if(rear-front==size-1||front-rear==1)   //just after deletion of last element of circulat queue, front and rear variable gets updated to -1(condition that shows queue is empty).
                                            //The condition of full queue is same as that of empty queue, So we manually manage emptied queue just after deleting last element to eradicate further confusion 
        front=rear=-1;
    return val;
}