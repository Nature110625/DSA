/*Q4*/
#include <stdio.h>
void prnt(int, int, int);
int main(){
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    prnt(a, b, c);
}
void prnt(int a, int b, int c){
    b>a?(b<c?printf("%d %d %d", a, b, c):prnt(a,c,b)):prnt(b,a,c);  //kind of binary sort
}
