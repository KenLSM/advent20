#include <bits/stdc++.h>

using namespace std;

bool is_tree(vector<string> v, int x, int y) {
	string r = v[y];
	return r[x % r.length()] == '#';
}
int main() {
	string s;
	vector<string> v;
	int counter = 0;
	while (cin >> s) {
		v.push_back(s);
	}
	cout << s.length() << " " << v.size() << endl;

	for (int i = 1; i < v.size(); i++) {
		int x = i * 1;
		if (is_tree(v, x, i)) {
			counter++;
		}
	}
	// case where d=2
	// 	for (int i = 1; i < (v.size() + 1) / 2; i++) {
	// 	int x = i * 1;
	// 	if (is_tree(v, x, i * 2)) {
	// 		counter++;
	// 	}
	// }
	cout << counter << endl;
	return 0;
}

// r1d1: 66
// r3d1: 153
// r5d1: 79
// r7d1: 92
// r1d2: 35