
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Macro to swap values, since it woks with any type of data type
#define SWAP(x,y,z)((z)=(x), (x)=(y), (y)=(z))  
#define MAX_SIZE 100

void sort(int [], int );
int bs(int [], int, int);
int check(int, int);
int rec_bs(int [], int, int, int);
int main(){
    int n, ans, val;
    int list[MAX_SIZE];
    printf("Enter the number of numbers to generate: ");
    scanf("%d", &n);
    if(n<1 || n>MAX_SIZE){
        fprintf(stderr, "Improper value of n\n");//to write formatted data to a file
        exit(1);
    }

    for(int i=0; i<n; i++){//randomly generates numbers
        list[i]=rand()%1000;    //to get value less than 1000
        printf("%d ", list[i]);
    }

    sort(list, n);

    printf("\nSorted array: \n");   //print out sorted numbers
    for(int i=0; i<n; i++)  
        printf("%d ", list[i]);
    printf("\n");

    printf("1. To binary search a number (implemented using loop)\n2. To binary search a number (implemented using recursion)\n3. To exit");
    while(1){
        printf("\n\nEnter your choice: ");
        scanf("%d", &ans);
        switch(ans){
            case 1:
                printf("Enter the value you want to search: ");
                scanf("%d", &val);
                ans=bs(list, n, val);
                ans>=0?printf("Entered value is at %d position", ans+1):printf("Entered value is not present.");
                break;
            case 2:
                printf("Enter the value you want to search: ");
                scanf("%d", &val);
                ans=rec_bs(list, 0, n, val);
                ans>=0?printf("Entered value is at %d position", ans+1):printf("Entered value is not present.");
                break;
            case 3:
                exit(1);
                break;
            default:
                printf("Entered unavailable choice");
        }
    }
}
void sort(int list[], int n){
    int temp, i, min;
    for(i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(list[i]>list[j])
                SWAP(list[i],list[j],temp);
}
int bs(int list[], int n, int val){
    int left=0, right=n, middle;
    while(left<=right){
        middle=(left+right)/2;
        switch(check(list[middle], val)){
            case -1:
                right=middle-1;
                break;
            case 0:
                return middle;
            case 1:
                left=middle+1;
        }
    }
    return -1;
}
int check(int variable, int constant){
    if(constant<variable)
        return -1;
    else{
        if(constant==variable)
            return 0;
        else
            return 1;
    }
}
int rec_bs(int list[], int left, int right, int val){
    if(left>right)
        return -1;
    int middle=(left+right)/2;
    switch(check(list[middle], val)){
        case -1:
            right=middle-1;
            rec_bs(list, left, right, val);
            break;
        case 0:
            return middle;
        case 1:
            left=middle+1;
            rec_bs(list, left, right, val);
    }
}