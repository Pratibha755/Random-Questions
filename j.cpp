#include<iostream>
using namespace std;
//convey of N vehicles : distance x kimometer
int main(){
    int n;
    cin>>n;
    int fuel[n];

    for(int i=0;i<n;i++){
        cin>>fuel[i];
    }
    sort(fuel);
    int refuel =0;
    int availablefuel=0;
    for(int fuel.length,i>=0;i--){
        availablefuel +=fuel[i];
        if(availablefuel<X){
            refuel++;
            availablefuel+=X;
        }
        availablefuel-=X;

    }
    return 0;
}
