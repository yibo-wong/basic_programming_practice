 #include <iostream>
 #include <cstring>
 #include <string>
 using namespace std;
 int main()
 {
 	string str;
 	int b[100]={0};
 	while(getline(cin,str))
 	{
 	int i=0;
 	int j=0;
 	int sum=0;
 	int tot=0;
 	bool flag=true;
 	for(int i=0;i<str.size();i++)
 	{
 		if(str[i]=='@')
		 {
		 	sum++;
		 	b[j]=i;
		 	j++;
		 	if(str[i+1]=='.'||str[i-1]=='.') flag=false;
		 }
	 }
	if(sum!=1||str[0]=='@'||str[0]=='.'||str[str.size()-1]=='@'||str[str.size()-1]=='.') flag=false;
	for(int s=b[0];s<str.size()-1;s++)
	{
		if(str[s]=='.') tot++;
	}
	if(tot==0) flag=false;
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	}
 	return 0;
 }
