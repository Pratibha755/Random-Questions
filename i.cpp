#include<iostream>
using namespace std;

int main(){
    int time = 240;
    int n, travelT;
    cin>>n>>travelT;
    int timeLeft = 240-travelT, c=0;
    for(int i = 1; i<=n; i++){
        timeLeft -= i*5;
        if(timeLeft<0){
            break;
        }
        c++;
    }
    cout<<c;
    return 0;
}
