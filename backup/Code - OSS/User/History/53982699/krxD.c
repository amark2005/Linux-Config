#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){

  printf("Enter Cars max speed: ");
  int n=0;
  scanf("%d",&n);
  int *carspeed=calloc(n,sizeof(int));

  for (int i=0;i<n;i++) {
    printf("CAR #%d maxspeed= ",i+1);
    scanf("%d",&carspeed[i]);

  }

  for(int i=0;i<n;i++){
    printf("%d ",carspeed[i]);
  }
  free(carspeed);
  carspeed=NULL;

  return 0;
}