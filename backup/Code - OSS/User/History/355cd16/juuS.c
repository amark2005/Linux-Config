#include<stdio.h>

void addo(int a,int b){
  printf("A and B is d")
}

int main(){
  int x=10;
  int *p=&x;
  *p=*p+5;
  printf("%d\n",x);
  return 0;
}