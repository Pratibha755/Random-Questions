#include<iostream>
#include<string.h>
using namespace std;
int fun(const char* str){
    if(str == NULL){
        return -1;
    }
    int a = (*str - '0');
    str++;
    while(*str != '\0'){
        char p = *str;
        str++;
        if(p == 'A'){
            a = a&(*str - '0');
        }
        else if(p == 'B'){
            a = a | (*str - '0');
        }
        else {
            a = a ^ (*str - '0');
        }
        str++;
    }
    return a;
}
int main(){
    string str;
    cout<<"Enter string : ";
    cin>>str;
    cout<<fun(str.c_str());
}