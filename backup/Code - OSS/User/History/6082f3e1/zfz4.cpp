#include <iostream>

double q(double m,double c,double deltaT){
  return m*c*deltaT;
}

int main(){
  constexpr double cokeinit=31.0;
  constexpr double freezertemp=18.0;
  constexpr double cokevol=300.0;
  constexpr double cokemass=0.3;
  double Q=q(cokemass,4186.0,cokeinit);
  std::cout<<"Q: "<<Q<<"\n";
  
}