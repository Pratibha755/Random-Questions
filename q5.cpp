#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=3) {
        cout<<0; 
        return 0;
    }
    else{
        int arr[n];
        int max=0, sec_max=0, min=0, sec_min=0;
        for(int i=0; i<n;i++){
            cin>>arr[i];
        }
        min = 1000000;
        sec_min = 100000;
        for(int i=0; i<n; i++){
            if(arr[i]>max && i%2==0){
                
                sec_max = max;
                max = arr[i];
            }
            else if(arr[i]>sec_max && i%2==0){
                sec_max=arr[i];
            }
            if(arr[i]<min && i%2==1){
                
                sec_min= min;
                min = arr[i];
            }
            else if(arr[i]<sec_min && i%2==1){
                
                sec_min= arr[i];
            }
        }
        cout<<sec_max+sec_min;
        
    }

}