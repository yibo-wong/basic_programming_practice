#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int x[500];
int howmany=169;
int n;
long long int dp[1010];
int isp(int s)
{
    int t=1;
    if(s==1) return 0;
    if(s==2) return 1;
    for(int i=2;i<=sqrt(s)+1;i++)
    {
        if(s%i==0)
        {
            t=0;
            break;
        }
    }
    return t;
}
int main()
{
    int count=1;
    for(int i=1;i<=1100;i++)
    {
        if(isp(i))
        {
            x[count]=i;
            count++;
        }
    }
    cin>>n;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int y;
    for(int i=1;i<=170;i++)
    {
        //cout<<x[i]<<endl;
        if(x[i]<=n&&n<x[i+1])
        {
            y=i;
            break;
        }
    }
    //cout<<y<<endl;
    for(int i=1;i<=y;i++)
    {
        for(int j=x[i];j<=n;j++)
        {
            dp[j]+=dp[j-x[i]];
        }
    }
    
    cout<<dp[n];
    
    
    return 0;
    
}
