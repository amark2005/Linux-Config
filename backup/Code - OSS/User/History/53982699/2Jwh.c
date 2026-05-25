#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){

  
  int *carspeed=calloc(1,sizeof(int));
  int i=0;
  while(1){
    printf("CAR #%d maxspeed= ",i+1);
    scanf("%d",&carspeed[i]);
    if (carspeed[i]==0) {
      break;
      }
      
      i++;


  }
  printf("%ld\n",i*sizeof(*carspeed));
  
  for (int j=0;j<i;j++) {
    printf("%d ",carspeed[j]);
  }
  

  free(carspeed);
  carspeed=NULL;

  return 0;
}