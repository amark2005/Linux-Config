#include<stdio.h>

void addo(int a,int b){
  printf("A and B is %d\n",a+b);
}

void hello(void(*func)(int,int),int a,int b){
  printf("Hello\n");
  func(a,b);
}

int main(){
  int x=10;
  int y=5;
  int *p=&x;
  *p=*p+5;
  printf("%d\n",x);
  hello(addo,x,y);
  return 0;
}