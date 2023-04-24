#include<stdio.h>
#include<string.h>
#include<limits.h>
#include <iostream>

int n;
char src[18][18],temp1[18][18];
int dx[4]={-1,0,1,0};//��������
int dy[4]={0,1,0,-1};

int GetBit(int c,int i)//ȡc�ĵ�iλ��i��0��ʼ��
{  return ( c >> i ) & 1;  }
void Flip(int i,int j)//��src[i][j]������ΧԪ��ȡ��
{
    int k,x,y;
    src[i][j]=src[i][j]=='w'?'y':'w';
    for(k=0;k<4;k++)
    {
        x=i+dx[k];
        y=j+dy[k];
        if(x>=0&&x<n&&y>=0&&y<n)
        {
            src[x][y]=src[x][y]=='w'?'y':'w';
        }
    }
}
int main()
{
    int i,j,k,t;
    char str[20];
    int count,min=INT_MAX;

    int T;
    scanf("%d",&T);
    for(;T>0;T--)
    {
        min=INT_MAX;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            for(j=0;j<n;j++)
            {
                temp1[i][j]=src[i][j]=str[j];
            }
        }

        t=(1<<n);//��0���ܹ���2^n�ֲ�ͬ��Ϳ��
        for(i=0;i<=t;i++)//ö������Ϳ������ÿһ��Ϳ����ͳ�Ƹ÷�����ҪͿ������������÷����ܷ�ȫ��Ϊy��
        {
            memcpy(src,temp1,sizeof(src));
            /*for(k=0;k<n;k++)
                for(j=0;j<n;j++)
                    src[k][j]=temp1[k][j];*/
            count=0;

            for(j=0;j<n;j++)//���ݵ�ǰ����i�������ص�ֵȥͿ��0��
            {
                if(GetBit(i,j)==1)//��ȡi�ĵ�j�����ء���Ϊ1������ҪͿ��0��j��λ��
                {
                    Flip(0,j);
                    std::cout<<"0 "<<j<<std::endl;
                    count++;
                }
            }
            for(k=1;k<n;k++)//ɨ����˵�0�������������
            {
                for(j=0;j<n;j++)
                {
                    if(src[k-1][j]=='w')
                    {
                        Flip(k,j);
                        std::cout<<k<<" "<<j<<std::endl;
                        count++;
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
            	for(int j=0;j<n;j++)
            	{
            		std::cout<<src[i][j];
				}
				std::cout<<std::endl;
			}
			std::cout<<std::endl;
            for(j=0;j<n;j++)//ɨ�����һ�м���Ƿ���δ��Ϊy�ĵ�Ԫ
            {
                if(src[n-1][j]=='w') break;
            }
            if(j==n&&count<min)
            {
            	min=count;
            	std::cout<<"ans is "<<count<<std::endl;
			}
        }
        if(min==INT_MAX) printf("inf\n");
        else printf("%d\n",min);
    }
    return 0;
}
