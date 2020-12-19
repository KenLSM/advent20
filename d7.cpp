#include <bits/stdc++.h>
#define psi pair<string, int>
using namespace std;

unordered_map<string, vector<psi>> master_list, reverse_list;

vector<string> valid_list;

void process(string s) {
	stringstream ss;
	ss << s;
	string f1, f2, ign;
	ss >> f1 >> f2 >> ign >> ign;
	// cout << f1 << f2 << endl;

	string pri_color = f1 + f2;
	ss.ignore(1);
	// cout << char(ss.peek()) << endl;
	if (ss.peek() == 'n') {
		// no other bags
		// cout << pri_color << endl;
		return;
	}

	// int first_qty;
	// ss >> first_qty >> f1 >> f2 >> ign;
	// string first_color = f1 + f2;
	vector<psi> b_list;
	while (ss.peek() != EOF) {
		int second_qty;
		ss >> second_qty >> f1 >> f2 >> ign;
		string second_color = f1 + f2;
		b_list.push_back(psi(second_color, second_qty));
		cout << second_color << second_qty << endl;
	}
	master_list[pri_color] = b_list;

	for (int i = 0; i < b_list.size(); i++) {
		psi p = b_list[i];
		if (reverse_list.find(p.first) == reverse_list.end()) {
			reverse_list[p.first] = vector<psi>();
		}
		cout << p.first << "<-" << pri_color << endl;
		reverse_list[p.first].push_back(psi(pri_color, 0));
	}

	// cout << pri_color << " " << first_color << "|" << second_color << endl;
}
int main() {
	string s;
	while (cin.peek() != EOF) {
		getline(cin, s);
		// cout << s << endl;
		process(s);
		// break;
	}
	cout << master_list.size() << endl;

	for (int i = 0; i < master_list.size(); i++) {
		int t = master_list.size();
		while (t--) {
			// find
		}
	}
	queue<string> que;
	unordered_map<string, int> seen;
	que.push("shinygold");
	int counter = 0;
	while (que.empty() == false) {
		string search_term = que.front();
		que.pop();

		auto a = reverse_list.find(search_term);
		if (a == reverse_list.end()) {
			// cout << "ended" << endl;
			continue;
		}

		vector<psi> pp = a->second;

		for (int i = 0; i < pp.size(); i++) {
			cout << pp[i].first << "|";
			que.push(pp[i].first);
			counter++;
			seen[pp[i].first] = 0;
		}
	}
	cout << counter << endl;
	cout << seen.size() << endl;

	return 0;
}