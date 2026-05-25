#include <stdio.h>
#include<stdbool.h>
bool is_subsidezed(float *unit){
  if(*unit<=500){
    *unit=-100;
    return false;
  }
  else if (*unit>=501){
    *unit=-200;
    return true;
  }
  return 1;
}

int main(){
  float userunit=0;
  printf("Enter units consumed bi-monthly: ");
  scanf("%f",&userunit);
  printf("Units consumed: %.2f\n",userunit);
  
  return 0;
}