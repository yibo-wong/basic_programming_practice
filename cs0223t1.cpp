#include <iostream>
using namespace std;

int bitManipulation2(int n, int i) {
	return n^((-1)>>(32-i)<<(32-i));
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation2(n, i) << endl;
	}
	return 0;
}
//n-(((n>>i)&1)<<i)+(((m>>i)&1)<<i)
