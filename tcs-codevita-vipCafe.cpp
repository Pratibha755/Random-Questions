#include<iostream>
using namespace std;
int main()
{
    int n,K,m,max;
    cin>>n;
	int p[n];
    for(int i=0;i<n;i++)
	{
        cin>>p[i];
	}
    cin>>K;
    for(int i=0;i<n; i++)
    {   m=-1,max=0;
        for(int j=0; j<n;j++){
            if(max < p[j])
				m=j;
			max=p[m];
        }
        p[m]=0;
        for(int j=0;j <m; j++){
            p[j]=p[j]+1;
        }
        if(m==(K - 1))
		{
            cout<<i+1<< endl;
            break;
        }
    }return 0;
}
