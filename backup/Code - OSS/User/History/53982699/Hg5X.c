#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){

  printf("Enter Cars max speed: ");
  int n=0;
  scanf("%d",&n);
  int *carspeed=malloc(n * sizeof(int));
  
  printf("%d\n",*carspeed);
  free(carspeed);
  carspeed=NULL;

  return 0;
}