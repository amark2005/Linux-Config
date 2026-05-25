#include <iostream>

double q(double m,double c,double deltaT){
  return m*c*deltaT;
}
double lat_q(double m,double latentenergy){ return m*latentenergy;} 

int main(){
  constexpr double cokeinit=31.0;
  constexpr double freezertemp=18.0;
  constexpr double cokevol=300.0;
  constexpr double cokemass=0.3;
  constexpr static double c=4186.0; //Heat Capacity 
  constexpr static double latentewater=4186.0; //latent heat of water
  double Q=q(cokemass,c,cokeinit); //heat energy joules
  std::cout<<"Q: "<<Q<<" joules\n";


}