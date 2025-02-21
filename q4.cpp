#include<iostream>
using namespace std;
int main(){
    int n, m, oddSum=0, evenSum=0;
    cin>>n>>m;
    for(int i =1; i<=m; i++){
        if(i%n==0){
            evenSum+=i;
        }
        else oddSum+=i;
    }
    cout<<abs(evenSum-oddSum);
}