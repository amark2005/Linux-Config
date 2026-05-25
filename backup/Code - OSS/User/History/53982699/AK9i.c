#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){

  printf("Enter Cars max speed: ");
  int n=0;
  scanf("%d",&n);
  int *cars=malloc(n * sizeof(int));
  
  printf("%d\n",*cars);
  free(cars);
  cars=NULL;

  return 0;
}