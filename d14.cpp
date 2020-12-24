#include <bits/stdc++.h>

using namespace std;

unordered_map<long, long> mm;

bitset<36> set_mask, clear_mask;

void update_mask(string s) {
	cout << "Mask:\t" << s << endl;
	set_mask = bitset<36>(0);
	clear_mask = bitset<36>(-1);
	for (int i = 0; i < 36; i++) {
		if (s[i] == 'X')
			continue;
		if (s[i] == '0') {
			clear_mask[35 - i] = 0;
			continue;
		}
		if (s[i] == '1') {
			set_mask[35 - i] = 1;
			continue;
		}
	}

	cout << "\t" << set_mask << endl;
	cout << "\t" << clear_mask << endl;
}

void set_val(long key, long value) {
	cout << "Mem:\t" << key << "\tV:\t" << value << endl;
	long ll = (value | set_mask.to_ulong()) & clear_mask.to_ullong();
	cout << "\t" << ll << endl;

	mm[key] = ll;
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