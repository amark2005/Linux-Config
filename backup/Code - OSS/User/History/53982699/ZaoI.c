#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){

  printf("Enter your name: ");
  char *name=malloc(50 * sizeof(char));
  fgets(name,100,stdin);
  printf("%s\n",name);
  //free(name);
  //name=NULL;

  return 0;
}