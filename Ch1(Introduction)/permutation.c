#include <stdio.h>
#define SWAP(a, b, c)((c)=(a), (a)=(b), (b)=(c))

void permute(char *, int, int);

int main(){
    int n=5;
    // printf("Enter the number of values: ");
    // scanf("%d", &n);
    char arr[]={'a', 'b', 'c', 'd', 'e'};
    // printf("Enter the values: \n");
    // for(int i=0; i<n; i++)
    //     scanf("%c", &arr[i]);
    printf("Pemutations of these values: \n");
    permute(arr, 0, n-1);
}
void permute(char *list, int i, int n){
    char temp;
    if(i==n){
        for(int j=0; j<=n; j++)
            printf("%c ", list[j]);
        printf("\n");
    }
    else{
        for(int j=i; j<=n; j++){
            SWAP(list[i], list[j], temp);
            permute(list, i+1, n);
            SWAP(list[i], list[j], temp);
        }
    }
}