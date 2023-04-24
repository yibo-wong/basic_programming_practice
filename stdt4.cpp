#include <iostream> 
#include <map>
#include <cstdio>
using namespace std;
map<int,int> mp;
int main()
{
	int n;cin>>n;
	mp.insert(make_pair(1000000000,1));
	int a,b;
	while(n--){
		scanf("%d %d",&a,&b);
		map<int,int>::iterator it;
		it = mp.upper_bound(b);
		if(it == mp.end())
		{
			--it;
			printf("%d %d\n",a,it->second);
		}
		else if(it == mp.begin())
		{
			printf("%d %d\n",a,it->second);
		}
		else
		{
			map<int,int>::iterator it2 = it;
			--it2;
			if(b-it2->first <= it->first-b){
				printf("%d %d\n",a,it2->second);
			}else{
				printf("%d %d\n",a,it->second);
			}
		}
		mp.insert(make_pair(b,a));
	}
	return 0;
}
