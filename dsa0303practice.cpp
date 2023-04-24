#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int n,a,b;
char s[200];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%d%d",&s,&a,&b);
		if(a<strlen(s) || b==0)
		{
			for(int i=a;i<=a+b-1 && i<strlen(s);i++) printf("%c",s[i]);
			printf("\n");
		}
	}
	return 0;
}
