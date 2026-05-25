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
  if (unit >= 100.0 && unit <= 400.0) {
    return 4.70;
} 
  else if (unit >= 401.0 && unit <= 500.0) {
    return 6.30;
} 
  else if (unit >= 501.0 && unit <= 600.0) {
    return 8.40;
} 
  else if (unit >= 601.0 && unit <= 800.0) {
    return 9.45;
} 
  else if (unit >= 801.0 && unit <= 1000.0) {
    return 10.50;
} 
  else if (unit > 1000.0) {
    return 11.55;
}
return 0.0;
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