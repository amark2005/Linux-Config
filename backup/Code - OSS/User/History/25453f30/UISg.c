#include <stdio.h>
int is_subsidezed(float *unit){
  if(*unit<=500){
    *unit-=200;
    return 1;
  }
  else if (*unit>=500){
    *unit-=100;
    return 0;
  }
  return 2;
}

float rateperunit(float unit){
}

int main(){
  float userunit=0;
  printf("Enter units consumed bi-monthly: ");
  scanf("%f",&userunit);
  int subsidy=is_subsidezed(&userunit);
  if (subsidy) {
    printf("Subsidized!!\n");
  }
  else if (!subsidy) {
    printf("Not Subsidized!!\n");
  }
  else {
  printf("error\n");
  return 0;
  }
  printf("Units consumed: %.2f\n",userunit);
  
  return 0;
}