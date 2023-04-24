#include<iostream>
using namespace std;
int f[35];
int main() {
	int n = 0; f[0] = 1, f[2] = 3;
	for (int i = 4; i < 35; i++)f[i] = 4 * f[i - 2] - f[i - 4];
	while (cin >> n && n != -1) {
		cout << f[n] << endl;
	}
}

