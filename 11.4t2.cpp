#include <stdio.h>
using namespace std;
char a[100];
char temp;
int main()
{
	fgets(a,100,stdin);
	for(int i=0;i<=100;i++)
	{
		temp=a[i];
		if(65<=temp&&temp<=90)
			a[i]+=32;
		if(97<=temp&&temp<=122)
			a[i]-=32;
	}
	printf("%s",a);
	return 0;
}
