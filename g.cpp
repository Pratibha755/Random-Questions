#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int f= INT8_MIN;
    int s = INT8_MIN;
    int t = INT8_MIN;
    int smallest = INT8_MAX;
    int secSmallest = INT8_MAX;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        if(f<a[i]){
            t = s;
            s = f;
            f = a[i];
        }
        else if(s<a[i]) {
            t = s;
            s = a[i];
        }
        else if (t<a[i]){
            t=a[i];
        }

        if(a[i]<smallest){
            secSmallest = smallest;
            smallest = a[i];
        }
        else if(a[i]<secSmallest){
            secSmallest = a[i];
        } 
    }
    cout<<endl;
    cout<<max(smallest*secSmallest*f, f*s*t);
    return 0;
}
