#include <stdio.h>
int is_subsidezed(float *unit){
  if(*unit<=500){
    *unit=-200;
    return 1;
  }
  else if (*unit>=501){
    *unit=-100;
    return 0;
  }
  return 2;
}

int main(){
  float userunit=0;
  printf("Enter units consumed bi-monthly: ");
  scanf("%f",&userunit);
  if (is_subsidezed(&userunit)) {
    printf("Subsidized!!\n");
  }
  else if (is_subsidezed(&unit)) {
    
  }
  printf("Units consumed: %.2f\n",userunit);
  
  return 0;
}