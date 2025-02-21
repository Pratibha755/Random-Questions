#include<iostream>
using namespace std;
//car's speed
int main(){
    int n;
    cin>>n;
    int speed=0;
    for(int i=1; i<=n/2; i++){
        if(n%i==0) speed+=i;    
    }
    cout<< speed+n;
    return 0;
}
