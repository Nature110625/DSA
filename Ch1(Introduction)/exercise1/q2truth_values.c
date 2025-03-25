/*Q3*/
#include <stdio.h>

void comb_of_tv(int *, int, int);
int main(){
    int n;
    printf("Enter number of variables: ");
    scanf("%d", &n);
    int tv[n];
    for(int i=0; i<n; i++)  //initialize array 'tv' with value 'zero'
        tv[i]=0;

    comb_of_tv(tv, n, 0);
}
void comb_of_tv(int *list, int n, int i){
    char temp;
    if(i==n){
        for (int j=0; j<n; j++)
            list[j]==1?printf("T "): printf("F ");
        printf("\n");
    } 
    else
        for(int m=0; m<2; m++){
            temp=list[i];
            list[i]=m;
            comb_of_tv(list, n, i+1); //i counts the level
            list[i]=temp;
        }
}
