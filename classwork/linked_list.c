#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *link;
};

struct node *create_list(struct node* start);
void display(struct node *start);
int count(struct node *start);
int search(struct node *start, int data);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addatpos(struct node *start, int data, int pos);
struct node *addbefore(struct node *start, int data, int val);
struct node *addafter(struct node *start, int data, int val);
struct node *delatpos(struct node *start, int pos);
struct node *delval(struct node *start, int val);
struct node *delbeg(struct node *start);
struct node *delend(struct node* start);
struct node* reverse(struct node*start, struct node * prev);

int main(){
    struct node *start=NULL;
    int choice, data, item, pos, temp;
    printf("This is a menu driven program: \n");
    printf("1. create a list\n");
    printf("2. Display\n");
    printf("3. Count\n");
    printf("4. search\n");
    printf("5. Add at beginning\n");
    printf("6. Add at end\n");
    printf("7. Add at given position\n");
    printf("8. Add before node\n");
    printf("9. Add after node\n");
    printf("10. Delete from beginning\n");
    printf("11. Delete from ending\n");
    printf("12. delete at position\n");
    printf("13. Delete value\n");
    printf("14. Reverse\n");
    printf("15. Quit\n\n");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(start!=NULL){
                    printf("List had already been created.\n");
                    break;
                }
                start=create_list(start);
                break;
            case 2:
                if(start==NULL){
                    printf("The list is empty.\n");
                    break;
                }
                display(start);
                break;
            case 3:
                if(start==NULL){
                    printf("The list is empty.\n");
                    break;
                }
                printf("Number of nodes present in linked list: %d", count(start));
                break;
            case 4:
                if(start==NULL){
                    printf("The list is empty.\n");
                    break;
                }
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                temp=search(start, data);
                temp==0?printf("Entered element is not present in list."):printf("Entered element is at position %d", temp);
                break;
            case 5:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                start= addatbeg(start, data);
                break;
            case 6: 
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                start=addatend(start, data);
                break;
            case 7: 
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position at which to insert: ");
                scanf("%d", &pos);
                start=addatpos(start, data, pos);
                break;
            case 8:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &item);
                start=addbefore(start, data, item);
                break;
            case 9:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &item);
                start=addafter(start, data, item);
                break;
            case 10:
                if(start==NULL){
                    printf("The list is empty.\n");
                    break;
                }
                start= delbeg(start);
                break;
            case 11: 
                if(start==NULL){
                    printf("The list is empty.\n");
                    break;
                }
                start=delend(start);
                break;   
            case 12:
                if(start==NULL){
                    printf("The list is empty.\n");
                    break;
                }
                printf("Enter the position of element to be deleted: ");
                scanf("%d", &data);
                start=delatpos(start, data);
                break;
            case 13:
                if(start==NULL){
                    printf("The list is empty.\n");
                    break;
                }
                printf("Enter the value you want to delete: ");
                scanf("%d", &data);
                start=delval(start, data);
                break;
            case 14:
                if(start==NULL){
                    printf("The list is empty.\n");
                    break;
                }
                start=reverse(start, NULL);
                break;
            case 15:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
}

struct node *create_list(struct node* start){
    int val;
    start=(struct node *)malloc(sizeof(struct node));
    start->link=NULL;
    printf("Enter the element to be inserted: ");
    scanf("%d", &start->info);
    return start;
}
void display(struct node *start){
    while(start!=NULL){
        printf("%d ", start->info);
        start=start->link;
    }
    printf("\n");
}
int count(struct node *start){
    int count=0;
    while(start!=NULL){
        count++;
        start=start->link;
    }
    return count;
}
int search(struct node *start, int data){
    int pos=1;
    while(1){
        if(start==NULL)
            return 0;
        if(start->info==data)
            break;
        pos++;
        start=start->link; 
    }
    return pos;
}
struct node *addatbeg(struct node *start, int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    return temp;
}
struct node *addatend(struct node *start, int data){
    struct node *temp, *ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else{
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=temp;
    }
    return start;
}
struct node *addatpos(struct node *start, int data, int pos){
    struct node *temp, *ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(pos<2){  //add a new node at position one in an empty list also
        temp->link=start;
        start=temp;
        return start;
    }
    //no need to update ptr to add at pos 1 and 2
    for(int i=2; i<pos; i++){   
        ptr=ptr->link;
        if(ptr==NULL){
            printf("The required position does not exist in current list.\n");
            return start;
        }
    }
    //after iteration ptr points at position one less than the position were new element is to be added
    temp->link=ptr->link;
    ptr->link=temp;
    return start;
}
struct node *addbefore(struct node *start, int data, int val){
    int pos=search(start, val);
    if(pos==0)
        printf("value is not present in the list\n");
    else
        start=addatpos(start, data, pos);
    return start;
}
struct node *addafter(struct node *start, int data, int val){
    int pos=search(start, val)+1;
    if(pos==1)
        printf("Value is not present in the list\n");
    else
        start=addatpos(start, data, pos);
    return start;
}
struct node *delval(struct node *start, int val){
    int pos=search(start, val);
    if(pos==0)
        printf("Value is not present in theeee list\n");
    else
        start=delatpos(start, pos);
    return start;
}
struct node *delbeg(struct node *start){
    if(start->link==NULL)
        printf("%d was at the beginning, now list is empty.\n", start->info);
    else
        printf("%d was at the beginning, now %d is at the beginning.\n", start->info, start->link->info);
    return start->link;
}
struct node *delend(struct node* start){
    struct node *ptr=start;
    if(ptr->link==NULL){
        printf("%d was at the end, now list is empty.\n", ptr->info);
        return NULL;
    }
    while(ptr->link->link!=NULL)    //points at second last position
        ptr=ptr->link;
    printf("%d was at the end, now %d is at the end.\n", ptr->link->info, ptr->info);
    ptr->link=NULL;
    return start;
}
struct node *delatpos(struct node* start, int pos){
    struct node * ptr=start;
    if(pos<2){
        printf("%d has deleted.\n", start->info);
        return start->link;
    }
    for(int i=2; i<pos; i++){
        ptr=ptr->link;
        if(ptr->link==NULL){
            printf("Entered position does not exists.\n");
            return start;
        }
    }
    printf("%d has deleted\n", ptr->link->info);
    ptr->link=ptr->link->link;
    return start;
}
struct node* reverse(struct node*start, struct node * prev){
    if(start==NULL){
        return prev;
    }
    struct node *ptr;
    ptr=reverse(start->link, start);
    start->link=prev;
    return ptr;
}