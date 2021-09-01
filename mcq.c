#include<stdio.h>
int main(){
    int a,b,c;
    a=b=c=10;
    c=a++ || ++b && ++c;
    printf("%d %d %d",c,a,b);
    return 0;
}