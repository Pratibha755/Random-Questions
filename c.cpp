#include<iostream>
#include <math.h>
using namespace std;
//volume of cylinder question: water (in Litre) in the tank
int main(){
    int r, h;
    cin>>r>>h;
    float pi=3.14;
    int re = ceil(pi*r*r*h);
    cout<<re;
    return 0;
}
