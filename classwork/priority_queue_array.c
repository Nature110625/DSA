#include <stdio.h>
int que[10], prirt[10], front=-1, rear=-1, size=10;

int isfull();   //returns 1 if full else 0
int isempty();  //returns 1 if empty else 0
int inque();   //don't allow duplicate priority entry
int display();  //display if queue is not empty
int deque();    //delete highest priority element
int delpr(int j);   //delete element at given priority
int searchhp(); //search index of highest priority element
int searchpr(int val);  //search index of given priority

int main(){
    int ans;
    printf("1. to insert into queue \n2. to delete from queue \n3. to display queue\n4. get info of highest priority");
    printf("\n5. to get info of given priority.\n6. to end program\n");
    do{
        printf("\nEnter your choice: ");
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
                ans=searchhp();
                ans==-1?:printf("%d is the value of highest priority %d\n", que[ans], prirt[ans]);
                break;
            case 5:
                printf("Enter the priority: ");
                scanf("%d", &ans);
                ans=searchpr(ans);
                ans==-1?printf("Entered priority does not exist.\n"):printf("%d is value of given priority\n", que[ans]);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid entry.\n");
        }
    }while(1);
    return 0;
}

int isfull(){
    if(rear==size-1)
        return 1;
    return 0;
}
int inque(){
    if(isfull()){
        printf("Overflow\n");
        return 0;
    }
    int val, valp;
    printf("Enter value and its priority: ");
    scanf("%d%d", &val, &valp);
    if(searchpr(valp)!=-1){
        printf("Entered priority exists, enter another priority.\n");
        return 0;
    }
    if(rear==size-1)
        rear==0;
    else{
        if(isempty())
            rear=front=0;
        else
            rear++;
    }
    que[rear]=val;
    prirt[rear]=valp;
    return 0;
}

int display(){
    if(isempty()){
        printf("underflow\n");
        return 0;
    }
    printf("\nQueue(priority): \n");
    for(int i=front; i<=rear; i++)
        printf("%d(%d)\n", que[i], prirt[i]);
    return 0;  
}

int deque(){
    if(isempty()){
        printf("underflow\n");
        return -1;
    }
    int j;
    j=searchhp();
    printf("The value %d with priority %d got deleted.\n", que[j], prirt[j]);
    delpr(j);
    return j;
}
int isempty(){
    if(rear==-1)
        return 1;
    return 0;
}
int delpr(int j){
    if(isempty()){
        printf("Underflow\n");
        return -1;
    }
    for(int i=j+1; i<=rear; i++, j++){
        que[j]=que[i];
        prirt[j]=prirt[i];
    }
    rear--;
}
int searchhp(){
    if(isempty()){
        printf("underflow\n");
        return -1;
    }
    int j=front;
    for(int i=front+1; i<=rear; i++)
        if(prirt[j]<prirt[i])
            j=i;
    return j;
}
int searchpr(int val){
    if(isempty())
        return -1;
    for(int i=front; i<=rear; i++)
        if(val==prirt[i])
            return i;
    return -1;
}