#include <bits/stdc++.h>

using namespace std;
#define plus -1
#define mul -2
#define o_b -3
#define c_b -4

vector<long> v;

void print() {
	cout << "Arr\t";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void operate(bool match_open) {
	while (v.size() > 1) {
		print();
		long r_opand = v.back();
		v.pop_back();

		int optor = v.back();
		cout << "Optor\t" << optor << endl;

		v.pop_back();
		if (optor == o_b) {
			if (!match_open) {
				v.push_back(o_b);
			}
			v.push_back(r_opand);
			return;
		}
		if (optor == plus) {
			long l_opand = v.back();
			v.pop_back();
			v.push_back(l_opand + r_opand);
			cout << l_opand << " + " << r_opand << endl;
			continue;
		}
		if (optor == mul) {
			long l_opand = v.back();
			v.pop_back();
			v.push_back(l_opand * r_opand);
			cout << l_opand << " + " << r_opand << endl;
			continue;
		}
	}
}

void operate_2(bool match_open, bool skip_mul) {
	while (v.size() > 1) {
		print();
		long r_opand = v.back();
		v.pop_back();

		int optor = v.back();
		cout << "Optor\t" << optor << endl;

		v.pop_back();
		if (optor == o_b) {
			if (!match_open) {
				v.push_back(optor);
			}
			v.push_back(r_opand);
			return;
		}
		if (skip_mul && optor == mul) {
			v.push_back(optor);
			v.push_back(r_opand);
			return;
		}
		if (optor == plus) {
			long l_opand = v.back();
			v.pop_back();
			v.push_back(l_opand + r_opand);
			cout << l_opand << " + " << r_opand << endl;
			continue;
		}
		if (optor == mul) {
			long l_opand = v.back();
			v.pop_back();
			v.push_back(l_opand * r_opand);
			cout << l_opand << " * " << r_opand << endl;
			continue;
		}
	}
}

int main_2() {
	char c;
	vector<long> a;
	while (cin.peek() != EOF) {
		while (cin.peek() != '\n' && cin.peek() != EOF) {
			if (cin.peek() == ' ') {
				cin.ignore(1);
				continue;
			}
			cin >> c;
			cout << "Read:\t" << c << endl;
			switch (c) {
			case '+': v.push_back(plus); break;
			case '*': v.push_back(mul); break;
			case '(': v.push_back(o_b); break;
			case ')':
				operate_2(true, false);
				operate_2(false, true);
				break;

			default: v.push_back(c - '0'); operate_2(false, true);
			}
			cout << "Placed:\t" << v[v.size() - 1] << endl;
		}
		cin.ignore(1);
		// cout << sum << endl;
		cout << "Crunch" << endl;
		operate_2(false, false);
		cout << v[0] << endl;
		a.push_back(v[0]);
		if (v.size() > 1) {
			print();
			break;
		}
		v = vector<long>();
	}

	long sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
	}
	cout << "sum: " << sum << endl;
	return 0;
}

int main_1() {
	char c;
	vector<long> a;
	while (cin.peek() != EOF) {
		while (cin.peek() != '\n' && cin.peek() != EOF) {
			if (cin.peek() == ' ') {
				cin.ignore(1);
				continue;
			}
			cin >> c;
			cout << "Read:\t" << c << endl;
			switch (c) {
			case '+': v.push_back(plus); break;
			case '*': v.push_back(mul); break;
			case '(': v.push_back(o_b); break;
			case ')':
				operate(true);
				operate(false);
				break;

			default: v.push_back(c - '0'); operate(false);
			}
			cout << "Placed:\t" << v[v.size() - 1] << endl;
		}
		cin.ignore(1);
		// cout << sum << endl;
		cout << "Crunch" << endl;
		operate(false);
		cout << v[0] << endl;
		a.push_back(v[0]);
		if (v.size() > 1) {
			print();
			break;
		}
		v = vector<long>();
	}

	long sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
	}
	cout << "sum: " << sum << endl;
	return 0;
}

int main() {
	// main_1();
	main_2();
}