#include <stdio.h>
#include <stdlib.h>

struct node* insert(struct node *, int, int);
int isempty(struct node *);
struct node* delete(struct node *);
void display(struct node *);
struct node{
    int data;
    int priority;
    struct node* next;
};

int main(){
    int val, pref;
    struct node * start=NULL;
    printf("1. to insert value in queue\n2. to delete value in queue.\n3. to display queue and its priority\n4. to exit.");
    while(1){
        printf("\n\nEnter your choice: ");
        scanf("%d", &val);
        switch(val){
            case 1:
                printf("Enter the value and it's preference: ");
                scanf("%d%d", &val, &pref);
                start=insert(start, val, pref);
                break;
            case 2: 
                if(isempty(start)){
                    printf("Queue is empty.");
                    break;
                }
                printf("Deletion of %d with priority %d is ", start->data, start->priority);
                start=delete(start);
                printf("successful");
                break;
            case 3:
                if(isempty(start)){
                    printf("Queue is empty.");
                }
                display(start);
                break;
            default:
                printf("Entered choice is unavailable.");
        }
    }
}
struct node* insert(struct node* start, int val, int pref){
    struct node *temp, *curr=start;
    
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->priority=pref;
    temp->next=NULL;
    if(isempty(start))
        return temp;
    else{
        while(curr->next!=NULL){
            if(curr->next->priority<=pref)
                curr=curr->next;
            else
                break;
        }

        if(curr==start&&curr->priority>pref){
            temp->next=start;
            start=temp;
        }
        else{
            if(curr->next==NULL&&curr->priority<pref)
                curr->next=temp;
            else{
                temp->next=curr->next;
                curr->next=temp;
            }
        }
              
    }
    return start;
}
void display(struct node *start){
    printf("\n\nPriority Queue: ");
    while(start!=NULL){
        printf("\n%4d %4d", start->data, start->priority);
        start=start->next;
    }
}
int isempty(struct node * start){
    if(start==NULL)
        return 1;
    return 0;
}
struct node * delete(struct node *start){
    start=start->next;
    return start;
}