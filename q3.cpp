#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n], num, diff, count=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>num>>diff;
    for(int i =0; i<n; i++){
        if(abs(arr[i]-num) <= diff){
            count++;
        }

    }
    if(count==0) cout<<-1;
    else cout<<count;
    
}
