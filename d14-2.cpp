#include <bits/stdc++.h>

using namespace std;

unordered_map<long, long> mm;

string mask;

void update_mask(string s) {
	cout << "Mask:\t" << s << endl;
	mask = s;
}
vector<long> fork_bomb(vector<long> vv, long key, long cur_bs, int idx) {
	if (idx > 35) {
		// cout << "End" << endl;
		vv.push_back(cur_bs);
		return vv;
	}

	// cout << "Idx:\t " << idx << endl;

	bitset<36> t = bitset<36>(cur_bs);
	if (mask[idx] != 'X') {
		// cout << "Linear" << endl;
		t[35 - idx] = mask[idx] == '0' ? bitset<36>(key)[35 - idx] : 1;
		cur_bs = t.to_ulong();
		return fork_bomb(vv, key, cur_bs, idx + 1);
	}
	// cout << "Fork" << endl;
	t[35 - idx] = 0;
	cur_bs = t.to_ulong();
	vv = fork_bomb(vv, key, cur_bs, idx + 1);

	t[35 - idx] = 1;
	cur_bs = t.to_ulong();
	return fork_bomb(vv, key, cur_bs, idx + 1);
}

void set_val(long key, long value) {
	cout << "Mem:\t" << key << "\tV:\t" << value << endl;
	vector<long> vv;
	vv = fork_bomb(vv, key, 0, 0);
	cout << "VV " << vv.size() << endl;
	for (auto l : vv) {
		mm[l] = value;
		cout << "Float:\t" << l << "\tV:\t" << value << endl;
	}
	// long ll = (value | set_mask.to_ulong()) & clear_mask.to_ullong();
	// cout << "\t" << ll << endl;

	// mm[key] = ll;
}

int main() {
	int q = -1;
	while (cin.peek() != EOF && q--) {
		string s;
		cin >> s;
		if (s == "mask") {
			cin >> s >> s;
			update_mask(s);
			continue;
		}
		if (s[1] == 'e') {
			long l = stol(s.substr(4, s.length() - 5));

			cin >> s >> s;
			set_val(l, stol(s));
		}
	}
	long long sum = 0;
	for (auto i = mm.begin(); i != mm.end(); i++) {
		sum += i->second;
	}
	cout << sum << endl;
	return 0;
}