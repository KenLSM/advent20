#include <bits/stdc++.h>

using namespace std;

int main() {
	int i;
	vector<int> v;
	while (cin >> i) {
		v.push_back(i);
	}
	cout << v.size() << endl;
	for (int j = 0; j < v.size(); j++) {
		for (int l = 0; l < v.size(); l++) {
			for (int m = 0; m < v.size(); m++) {
				if (v[j] + v[l] + v[m] == 2020) {
					cout << v[j] * v[l] * v[m] << endl;
				}
				/* code */
			}
		}
	}

	return 0;
}