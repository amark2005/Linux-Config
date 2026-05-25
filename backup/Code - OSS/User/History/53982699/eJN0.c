#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){

  
  int *carspeed=calloc(2,sizeof(int));
  int i=1;
  while(1){
    printf("CAR #%d maxspeed= ",i+1);
    if (carspeed[i]==0) {
      break;
      }
    scanf("%d",&carspeed[i]);
    if (i<2) carspeed=realloc(carspeed,i*sizeof(int));
    printf("%ld\n",i*sizeof(*carspeed));
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