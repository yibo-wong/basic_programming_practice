#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	register int n,a,b;
	char aa[120];
	while(n--)
	{
		fgets(aa,120,stdin);
		scanf("%d%d",&a,&b);
		getchar();
		int len=strlen(aa);
		if(a>=len) continue;
		for(register int i=a;i<min(b,len);i++)
			printf("%c",aa[i]);
		printf("\n");
	}
}
