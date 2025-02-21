#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int runrate;
    cin>>runrate;
    float score = float(runrate*20);
    cout<<fixed<<setprecision(2)<<score;
    return 0;
}
