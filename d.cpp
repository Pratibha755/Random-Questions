#include<iostream>
using namespace std;
//volume of cylinder question: water (in Litre) in the tank
int main(){
    int n;
    cin>>n;
    int b[n];
    int product = 1;
    for(int i=0; i<n;i++){
        cin>>b[i];
        if(b[i]%7==0) product = product * b[i];
    }
    
    cout<< (product ==1 ? 0 : product);
    return 0;
}
