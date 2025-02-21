/*
You are given a function.
int CheckPassword(char str[], int n);
The function accepts string str of size n as an argument. Implement the function which returns 1 if given string str is valid password else 0.
str is a valid password if it satisfies the below conditions.

– At least 4 characters
– At least one numeric digit
– At Least one Capital Letter
– Must not have space or slash (/)
– Starting character must not be a number
Assumption:
Input string will not be empty.

Example:

Input 1:
aA1_67
Input 2:
a987 abC012

Output 1:
1
Output 2:
0
*/





#include<iostream>
#include<string.h>
using namespace std;
int fun(const char str[], int n){
    if(n<4){
        return 0;
    }
    if(str[0] - '0' >=0 && str[0]-'0' <= 9){
        return 0;
    }
    int cap =0;
    int num =0;
    int i = 0;
    while(i<n){
        if(str[i]==' ' || str [i]=='/'){
            return 0;
        }
        if(str[i]>=65 && str[i]<=90){
            cap++;
        }
        else if(str[i] - '0' >=0 && str[i]-'0' <= 9){
            num++;
        }
        i++;
    }
    return cap>0 && num>0;
}
int main(){
    string str;
    getline(cin, str);
    int n = str.length();
    cout<<fun(str.c_str(), n);

}