#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main() {
	int i;
	v.push_back(0);
	while (cin >> i) {
		v.push_back(i);
	}

	sort(v.begin(), v.end());
	v.push_back(v[v.size() - 1] + 3);
	int one = 0, two = 0, three = 0;
	for (int j = 0; j < v.size(); j++) {
		if ((v[j] - v[j + 1]) == -1) {
			one++;
		}
		if ((v[j] - v[j + 1]) == -2) {
			two++;
		}
		if ((v[j] - v[j + 1]) == -3) {
			three++;
		}
	}

	cout << one << " " << two << " " << three << endl;

	int run_count = 0;
	int three_runs = 0, two_runs = 0, four_runs = 0;
	for (int j = 0; j < v.size(); j++) {
		// find_runs
		if ((v[j] - v[j + 1]) == -1) {
			run_count++;
			continue;
		}

		if (run_count == 2) {
			two_runs++;
		}
		if (run_count == 3) {
			three_runs++;
		}
		if (run_count == 4) {
			four_runs++;
		}
		run_count = 0;
	}

	cout << two_runs << " " << three_runs << " " << four_runs << endl;
	long ans = pow(2, two_runs) * pow(4, three_runs) * pow(7, four_runs);
	cout << ans << endl;
	return 0;
}

/*
(0), 1, 4, 5, 6, 7, 10, 11, 12, 15, 16, 19, (22)
inter group =
4,5,6,7 | 5,6 = 4 [(), 5, 6, (5, 6)]
10,11,12 | 11 = 2 [(), 11]

2^3?


(0), 1, 2, 3, 4, 7, 8, 9, 10, 11, 14, 17, 18, 19, 20, 23, 24, 25, 28, 31,
32, 33, 34, 35, 38, 39, 42, 45, 46, 47, 48, 49, (52)

inter group =
0,1,2,3,4 | 1,2,3 = 7 | 7
7,8,9,10,11 | 8,9,10 = 7 | 7
17,18,19,20 | 18,19 = 4 | 4
23,24,25 | 24 = 2 | 2
31,32,33,34,35 | 32,33,34 = 7 | 7
45,46,47,48,49 | 46,47,48 = 7 | 7

7*4 + 2*1 * 4*1
*/