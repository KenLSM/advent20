#include <bits/stdc++.h>

#define psi pair<vector<string> *, int>

using namespace std;

int solve(psi p) {
	unordered_map<char, int> m;
	auto v = *p.first;
	for (int j = 0; j < v.size(); j++) {
		string s = v[j];
		for (int i = 0; i < s.length(); i++) {
			if (m.find(s[i]) == m.end()) {
				m[s[i]] = 0;
			}
			m[s[i]] += 1;
		}
	}

	int ans = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
		if (iter->second == p.second) {
			ans++;
		}
	}
	return ans;
}

int main() {
	string s;
	vector<string> *str_v = new vector<string>();
	int num = 0;
	vector<psi> v_s;
	while (cin.peek() != EOF) {
		if (cin.peek() == '\n') {
			cin.get();
			if (cin.peek() == '\n') {
				cin.get();
				// cout << "|" << endl;
				v_s.push_back(psi(str_v, num));
				str_v = new vector<string>();
				num = 0;
			}
		}
		cin >> s;
		str_v->push_back(s);
		// cout << s << endl;
		num++;
	}
	v_s.push_back(psi(str_v, num));
	int count = 0;
	for (int i = 0; i < v_s.size(); i++) {
		cout << v_s[i].first->size() << endl;
		count += solve(v_s[i]);
	}
	cout << count << endl;
	return 0;
}
