#include <bits/stdc++.h>

using namespace std;
auto ecl_re = regex("(amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth)");
auto hcl_re = regex("#([a-f]|[0-9]){6}");
auto hgt_re =
  regex("(((1([5-8][0-9]))|(190|191|192|193))cm)|(((59)|(6[0-9])|7[0-6])in)");

bool solve(string sts) {
	cout << "\n\nstart" << endl;
	string byr = "\0", iyr = "\0", eyr = "\0", hgt = "\0", hcl = "\0",
	       ecl = "\0", pid = "\0", cid = "\0";
	stringstream ss;
	ss << sts;
	string s;
	while (ss >> s) {
		cout << "read " << s << "|" << endl;
		if (s.substr(0, 4) == "byr:") {
			byr = s.substr(4);
			int i = stoi(byr);
			if (i > 2002 || i < 1920) {
				return false;
			}
		}
		if (s.substr(0, 4) == "iyr:") {
			iyr = s.substr(4);
			int i = stoi(iyr);
			if (i > 2020 || i < 2010) {
				return false;
			}
		}
		if (s.substr(0, 4) == "eyr:") {
			eyr = s.substr(4);
			int i = stoi(eyr);
			if (i > 2030 || i < 2020) {
				return false;
			}
		}
		if (s.substr(0, 4) == "hgt:") {
			hgt = s.substr(4);
			cout << hgt << " " << regex_match(hgt, hgt_re) << endl;
			if (!regex_match(hgt, hgt_re))
				return false;
		}
		if (s.substr(0, 4) == "hcl:") {
			hcl = s.substr(4);
			cout << hcl << " " << regex_match(hcl, hcl_re) << endl;
			if (!regex_match(hcl, hcl_re))
				return false;
		}
		if (s.substr(0, 4) == "ecl:") {
			ecl = s.substr(4);
			cout << ecl << " " << regex_match(ecl, ecl_re) << endl;
			if (!regex_match(ecl, ecl_re))
				return false;
		}
		if (s.substr(0, 4) == "pid:") {
			pid = s.substr(4);
			if (pid.length() != 9) {
				return false;
			}
			stoi(pid); // ensure no crash
		}
		if (s.substr(0, 4) == "cid:") {
			cid = s.substr(4);
		}
	}
end:
	return byr != "\0" && iyr != "\0" && eyr != "\0" && hgt != "\0"
	       && ecl != "\0" && hcl != "\0" && pid != "\0";
}

int main() {
	int counter = 0;
	string ss;

	while (cin.peek() != EOF) {
		string s;
		getline(std::cin, s);
		ss += '|' + s;
	}
	vector<string> v;
	int idx = 0;
	while (idx < ss.length()) {
		string s = ss.substr(idx, ss.find("||", idx) - idx);
		cout << "find: " << idx << endl;
		cout << s << endl;
		v.push_back(s);
		idx += s.length() + 2;
		cout << "A" << endl;
	}

	for (int i = 0; i < v.size(); i++) {
		string s = v[i];
		replace(s.begin(), s.end(), '|', ' ');
		cout << s << endl;
		if (solve(s)) {
			counter++;
		}
	}
	cout << counter << endl;
	// cout << ss << endl;
	return 0;
	while (cin.peek() != EOF) {
		// if (solve()) {
		counter++;
		// }
		if (cin.peek() == '\n') {
			cout << "NL" << endl;
		}
		// string s;
		// cin >> s;
	}
	cout << counter << endl;
	return 0;
}