#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int dp1[maxn][maxn], dp2[maxn][maxn], dp3[maxn][maxn], dp4[maxn][maxn];
void init() {
    for (int n = 1; n <= 50; n++) {
        for (int k = 1; k <= 50; k++) {
            if (n == k) dp1[n][k] = 1;
            else if (n < k) dp1[n][k] = 0;
            else dp1[n][k] = dp1[n-k][k]+dp1[n-1][k-1];
        }
    }

    for (int n = 1; n <= 50; n++) {
        dp2[n][1] = n==1 ? 1 : 0;
        for (int m = 2; m <= 50; m++) {
            if (n < m) dp2[n][m] = dp2[n][n];
            else if (n == m) dp2[n][m] = dp2[n][m-1]+1;
            else dp2[n][m] = dp2[n][m-1]+dp2[n-m][m-1];
        }
    }

    for (int n = 1; n <= 50; n++) {
        dp3[n][1] = (n%2), dp4[n][1] = (n%2==0);
        dp3[n][0] = dp3[n][1];
        for (int m = 2; m <= 50; m++) {
            if (n < m) dp3[n][m] = dp4[n][m] = 0;
            else if (n == m) dp3[n][m] = 1, dp4[n][m] = 0;
            else {
                dp3[n][m] = dp3[n-1][m-1]+dp4[n-m][m];
                dp4[n][m] = dp3[n-m][m];
            }
            dp3[n][0] += dp3[n][m];
        }
    }
}
int main() {
    init();
    int n, k;
    while (cin >> n >> k) {
        cout << dp1[n][k] << endl;
        cout << dp2[n][n] << endl;
        cout << dp3[n][0] << endl;
    }
    return 0;
}
