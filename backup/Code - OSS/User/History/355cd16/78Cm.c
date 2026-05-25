#include<stdio.h>


int main(){
  int x=10;
  int y=5;
  int *p=&x;
  *p=*p+5;
  printf("%d\n",x);
  FILE *codeW=fopen("apilink.txt","w");
  FILE *codeR=fopen("apilink.txt","r");
  fprintf(codeW,"We dont talk about hello kitty club\n");

  fclose(codeW);
  fclose(codeR);


  return 0;
}