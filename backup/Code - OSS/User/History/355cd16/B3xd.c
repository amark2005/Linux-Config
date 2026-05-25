#include<stdio.h>


int main(){
  int x=10;
  int y=5;
  int *p=&x;
  *p=*p+5;
  char text[100];
  printf("%d\n",x);
  FILE *codeW=fopen("test.txt","w");
  
  fflush(codeW);
  fclose(codeW);
  fprintf(codeW,"We dont talk about hello kitty club\n");
  FILE *codeR=fopen("test.txt","r");
  fgets(text,100,codeR);
  printf("%s",text);
  
  fclose(codeR);


  return 0;
}