#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int LIMIT = 30000000;
int main() {
	pair<int, int> *arr = new pii[LIMIT + 1];

	for (int i = 0; i < LIMIT; i++) {
		arr[i] = pii(-1, -1);
	}

	vector<int> init = {9, 3, 1, 0, 8, 4};
	for (int i = 0; i < init.size(); i++) {
		arr[init[i]] = pii(i + 1, -1);
	}

	int last = init[init.size() - 1];
	for (int i = init.size() + 1; i <= LIMIT; i++) {
		pii pp = arr[last];
		// never
		if (pp.first == -1) {
			pp.first = i;
			last = 0;
		} else if (pp.second == -1) {
			// first time
			pp.second = pp.first;
			last = 0;
		} else {
			last = pp.first - pp.second;
		}
		// spoken before
		if (i % 100000 == 0) {
			cout << "T: " << i << "N: " << last << endl;
		}
		arr[last].second = arr[last].first;
		arr[last].first = i;
	}
	cout << last << endl;
	return 0;
}