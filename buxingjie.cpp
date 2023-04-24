#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int left;
	int right;
}a[100100];
bool cmp(node &x,node &y)
{
	return x.right<y.right;
}
int ch[100100],m[100050],l[100050];
int main()
{
	int n=0;
	int tot=0;
	int s=0;
	int t=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m[i]>>l[i];
		a[i].left= m[i]-l[i]>=0 ? m[i]-l[i] : 0;
		a[i].right=m[i]+l[i];
	}
	sort(a,a+n,cmp);
	ch[0]=1;
	for(int j=1;j<n;j++)
	{
		s=ch[j-1];
		for(int i=j;i>=0;i--)
		{
			if(a[i].right<a[j].left)
			{
				t=ch[i]+1;
				break;
			}
		}
		ch[j]=max(s,t);
	}
	/*for(int i=0;i<n;i++)
	{
		cout<<a[i].left<<" "<<a[i].right<<endl;
	}*/
	cout<<ch[n-1]<<endl;
	return 0;
}

