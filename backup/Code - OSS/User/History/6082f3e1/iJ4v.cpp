#include <iostream>

double q(double m,double c,double deltaT){return m*c*deltaT;}
double lat_q(double m,double latentenergy){return m*latentenergy;}
double calc_t(double q,double freezerate){return q/freezerate;} 

int main(){
  constexpr double cokeinit=31.0;
  constexpr double freezertemp=18.0;
  constexpr double cokevol=300.0;
  constexpr double cokemass=0.3;
  constexpr static double c=4186.0; //Heat Capacity 
  constexpr static double latentewater=4186.0; //latent heat of water
  double Q=q(cokemass,c,cokeinit); //heat energy joules
  std::cout<<"Q: "<<Q<<" joules\n";
  double LatQ=lat_q(cokemass,latentewater);
  std::cout<<"Latent Q: "<<LatQ<<" joules\n";
  Q=Q+LatQ;
  std::cout<<"Total energy to remove(Q): "<<Q<<" joules\n";
  constexpr double freezertemp_rate=20.0; //1watt=1joule/sec
  double t=calc_t(Q,freezertemp_rate);
  std::cout<<"Total energy to remove(Q): "<<Q<<" joules\n";
}