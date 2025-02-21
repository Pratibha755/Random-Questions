#include<iostream>
using namespace std;
int clock(int x, int y){
    int product = x*y;
    if (product%12!=0){
        return product%12;
    }
    else return 12;
}
int main(){
    int x, y;
    cin>>x>>y;
    cout<<(clock(x,y));
}