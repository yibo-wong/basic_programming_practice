#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define read scanf //pascal???
#define write printf //pascal???
using namespace std;
int n,a[1005];
long long dp[1005];
int sushu(int x) //????x???????
{
    int flag[x+10];
    memset(flag,1,sizeof(flag));
    for(int i=2;i<=x;i++)
     {
         if (flag[i])
            for(int j=i*2;j<=x;j+=i)
             flag[j]=0;
     }
    int k=0;
    for(int i=2;i<=x;i++)    
     if (flag[i]) a[++k]=i;
    return k;
}
int main()
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;//?????
    read("%d",&n); //pascal???
     for(int i=1;i<=sushu(n);i++)
      for(int j=a[i];j<=n;j++) 
       dp[j]+=dp[j-a[i]];
    write("%lld",dp[n]); //pascal???
}
