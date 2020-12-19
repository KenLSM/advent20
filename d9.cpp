#include <bits/stdc++.h>

using namespace std;

long q[1000];
void solve(int s, int e, long a) {
	for (int i = s; i < e; i++) {
		for (int j = s; j < e; j++) {
			if (i == j) {
				continue;
			}
			if ((q[i] + q[j]) == a)
				return;
		}
	}

	cout << a << endl;
	throw new exception;
}

long sum(int s, int e) {
	long a = 0;
	for (int i = s; i <= e; i++) {
		a += q[i];
	}
	// cout << a << endl;
	return a;
}

int main() {
	for (int i = 0; i < 1000; i++) {
		long t;
		cin >> t;
		q[i] = t;
	}

	// for (int i = 25; i < 1000; i++) {
	// 	solve(i - 25, i, q[i]);
	// }
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < i; j++) {
			if (sum(i - j, i) == 1930745883) {
				cout << (i - j) << " " << i << endl;
				cout << sum(i - j, i) << endl;
				break;
			}
		}
	}
	cout << "Next " << endl;
	long i_min = q[553];
	long i_max = q[553];
	for (int i = 553; i <= 569; i++) {
		i_min = min(i_min, q[i]);
		i_max = max(i_max, q[i]);
	}
	cout << i_min << " " << i_max << endl;
	return 0;
}