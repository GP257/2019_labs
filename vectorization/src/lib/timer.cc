#include "timer.h"
#include<iostream>


void timer::print() const{
  double totTime=(double)_totTime.count();
  if(_opsSet){
    double speed= (double) _ncalls*(double) _ops/totTime;
    std::cerr<<_name<<std::string(" totTime=")<<std::to_string(_totTime.count())<<std::string(" calls=")<<std::to_string(_ncalls)<<std::string(" Mcells/Sec=")<<std::to_string(speed)<<std::endl;
  
  }
  else
   std::cerr<<_name<<std::string(" totTime=")<<std::to_string(totTime)<<std::string(" calls=")<<std::to_string(_ncalls)<<std::endl;
  

}


void timer::start(){
  
_start = high_resolution_clock::now();
}
void timer::stop(){
  _totTime+=std::chrono::duration_cast<milliseconds>(high_resolution_clock::now() - _start);
  _ncalls+=1;

}
    