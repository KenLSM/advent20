#include <bits/stdc++.h>

using namespace std;

int main() {
	int counter = 0;

	while (cin) {
		int s, e;
		char c, _;
		string str;

		cin >> s >> e >> c >> _ >> str;
		e = -e;
		if (str.empty()) {
			break;
		}

		cout << s << e << c << str << endl;
		int char_count = 0;
		for (char _c : str) {
			if (_c == c) {
				char_count++;
			}
		}
		cout << char_count << endl;
		// if (char_count >= s && char_count <= e) {
		// 	counter++;
		// }

		if (str[s - 1] == c && str[e - 1] == c) {
			continue;
		}
		if (str[s - 1] == c || str[e - 1] == c) {
			counter++;
			continue;
		}
	}
	cout << counter << endl;

	return 0;
}