#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){

  printf("Enter Cars max speed: ");
  int n=0;
  scanf("%d",&n);
  int *carspeed=calloc(n,900);
  int i=0;
  while(1){
    printf("CAR #%d maxspeed= ",i+1);
    scanf("%d",&carspeed[i]);
    if (carspeed[i]==NULL) {
      break;
      }
      i++;


  }
  printf("%ld\n",sizeof(*carspeed));
  
  for (int i=0;i<n;i++) {
    printf("%d ",carspeed[i]);
  }
  carspeed=realloc(carspeed,i*sizeof(int));

  free(carspeed);
  carspeed=NULL;

  return 0;
}