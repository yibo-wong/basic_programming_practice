#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define MAXN 4004
int a[MAXN], b[MAXN], c[MAXN], d[MAXN], sum1[MAXN*MAXN], sum2[MAXN*MAXN];
int main() 
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        }
        int l1, l2;
        l1 = l2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum1[l1++] = a[i] + b[j];
                sum2[l2++] = c[i] + d[j];
            }
        }
        sort(sum1, sum1 + l1);
        int ans = 0;
        for (int i = 0; i < l2; i++)
        {
            int beg = 0, end = l1 - 1;
            while (beg <= end)
            {
                int mid = (beg + end) / 2;
                if (sum1[mid]+ sum2[i]==0)
                {
                    ans++;
                    for (int p = mid + 1; p < l1; p++)
                        if (sum1[p] + sum2[i] != 0)
                            break;
                        else
                            ans++;
                    for (int p = mid - 1; p >= 0; p--)
                        if (sum1[p] + sum2[i] != 0)
                            break;
                        else
                            ans++;
                    break;
                }
                if (sum1[mid] + sum2[i]<0)
                    beg = mid + 1;
                else
                    end = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
}
