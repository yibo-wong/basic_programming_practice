# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>
// # include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int M = 5000 + 10;
const int mod = 1e9+7;

# define RG register
# define ST static

int n, m, K, ans = 0;
struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
    friend bool operator == (point a, point b) {
        return a.x == b.x && a.y == b.y;
    }
    friend bool operator != (point a, point b) {
        return !(a==b);
    }
    friend bool operator < (point a, point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    friend bool operator > (point a, point b) {
        return a.x > b.x || (a.x == b.x && a.y > b.y);
    }
}p[M];

bool mp[M][M];

inline bool in(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int main() {
    point cur;
    cin >> n >> m >> K;
    for (int i=1; i<=K; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
        mp[p[i].x][p[i].y] = 1;
    }
    sort(p+1, p+K+1);
    for (int i=1; i<=K; ++i)
        for (int j=i+1,t; j<=K; ++j) {
        	//cout<<endl;
        	//cout<<p[i].x<<" "<<p[i].y<<endl;
        	//cout<<p[j].x<<" "<<p[j].y<<endl;
            int dx = p[j].x - p[i].x, dy = p[j].y - p[i].y;
            if(p[j].x + dx < 1 || p[j].x + dx > n) break;
            //if(in(p[i].x - dx, p[i].y - dy)) continue;//this isnt the case
            //cout<<"##"<<endl;
            if(p[j].y + dy < 1 || p[j].y + dy > m) continue;
            t = 2; cur = p[j];
            while(in(cur.x + dx, cur.y + dy) && mp[cur.x + dx][cur.y + dy]) {
                //cout<<cur.x + dx<<" "<<cur.y + dy<<endl;
				cur = point(cur.x + dx, cur.y + dy);
                ++t;
            }
            //cout<<"$"<<t<<" "<<ans<<endl;
            //if(in(cur.x + dx, cur.y + dy)) continue;
            if(t != 2) ans = max(ans, t);   
			//cout<<endl<<endl<<endl; 
        }
    cout << ans << endl;
    return 0;
}
