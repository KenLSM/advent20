#include <bits/stdc++.h>
using namespace std;

int **s_map, **s_copy;
int r = 0;
int c = 0;

void copy() {
	for (int j = 0; j < c; j++) {
		for (int i = 0; i < r; i++) {
			s_copy[i][j] = s_map[i][j];
		}
	}
}

bool _is_empty(int _r, int _c) {
	if (_r < 0) {
		return true;
	}
	if (_c < 0) {
		return true;
	}
	if (_r >= r) {
		return true;
	}
	if (_c >= c) {
		return true;
	}
	return s_copy[_r][_c] != '#';
}
bool _trace(int _r, int _c, int d_x, int d_y) {
	if (_r < 0) {
		return true;
	}
	if (_c < 0) {
		return true;
	}
	if (_r >= r) {
		return true;
	}
	if (_c >= c) {
		return true;
	}
	if (s_copy[_r][_c] != '.') {
		return _is_empty(_r, _c);
	}
	return _trace(_r + d_x, _c + d_y, d_x, d_y);
};

bool is_adj_empty_trace(int _r, int _c) {
	int count = 0;
	_trace(_r + -1, _c + -1, -1, -1) ? count++ : count;
	_trace(_r + 0, _c + -1, 0, -1) ? count++ : count;
	_trace(_r + 1, _c + -1, 1, -1) ? count++ : count;

	_trace(_r + -1, _c + 0, -1, 0) ? count++ : count;
	// _trace(_r + 0, _c + 0) ? count++ : count;
	_trace(_r + 1, _c + 0, 1, 0) ? count++ : count;

	_trace(_r + -1, _c + 1, -1, 1) ? count++ : count;
	_trace(_r + 0, _c + 1, 0, 1) ? count++ : count;
	_trace(_r + 1, _c + 1, 1, 1) ? count++ : count;
	return count == 8;
}

bool is_adj_empty(int _r, int _c) {
	int count = 0;
	_is_empty(_r + -1, _c + -1) ? count++ : count;
	_is_empty(_r + 0, _c + -1) ? count++ : count;
	_is_empty(_r + 1, _c + -1) ? count++ : count;

	_is_empty(_r + -1, _c + 0) ? count++ : count;
	// _is_empty(_r + 0, _c + 0) ? count++ : count;
	_is_empty(_r + 1, _c + 0) ? count++ : count;

	_is_empty(_r + -1, _c + 1) ? count++ : count;
	_is_empty(_r + 0, _c + 1) ? count++ : count;
	_is_empty(_r + 1, _c + 1) ? count++ : count;
	// cout << "E\t" << _r << "\t" << _c << (count >= 8 ? "empty" : "occ") <<
	// endl;
	return count == 8;
}

bool is_adj_occ(int _r, int _c) {
	int count = 0;
	_is_empty(_r + -1, _c + -1) ? count++ : count;
	_is_empty(_r + 0, _c + -1) ? count++ : count;
	_is_empty(_r + 1, _c + -1) ? count++ : count;

	_is_empty(_r + -1, _c + 0) ? count++ : count;
	// _is_empty(_r + 0, _c + 0) ? count++ : count;
	_is_empty(_r + 1, _c + 0) ? count++ : count;

	_is_empty(_r + -1, _c + 1) ? count++ : count;
	_is_empty(_r + 0, _c + 1) ? count++ : count;
	_is_empty(_r + 1, _c + 1) ? count++ : count;

	// cout << "Occ\t" << _r << "\t" << _c << (count <= 5 ? "die" : "no die")
	//      << endl;
	return count <= 4;
}

bool is_adj_occ_trace(int _r, int _c) {
	int count = 0;
	_trace(_r + -1, _c + -1, -1, -1) ? count++ : count;
	_trace(_r + 0, _c + -1, 0, -1) ? count++ : count;
	_trace(_r + 1, _c + -1, 1, -1) ? count++ : count;

	_trace(_r + -1, _c + 0, -1, 0) ? count++ : count;
	// _trace(_r + 0, _c + 0) ? count++ : count;
	_trace(_r + 1, _c + 0, 1, 0) ? count++ : count;

	_trace(_r + -1, _c + 1, -1, 1) ? count++ : count;
	_trace(_r + 0, _c + 1, 0, 1) ? count++ : count;
	_trace(_r + 1, _c + 1, 1, 1) ? count++ : count;

	// cout << "Occ\t" << _r << "\t" << _c << (count <= 5 ? "die" : "no die")
	//      << endl;
	return count <= 3;
}

void evolve() {
	copy();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			// grow
			if (s_copy[i][j] == 'L' && is_adj_empty(i, j)) {
				s_map[i][j] = '#';
				continue;
			}

			// die
			if (s_copy[i][j] == '#' && is_adj_occ(i, j)) {
				s_map[i][j] = 'L';
				continue;
			}
		}
	}
}

void evolve_trace() {
	copy();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			// grow
			if (s_copy[i][j] == 'L' && is_adj_empty_trace(i, j)) {
				s_map[i][j] = '#';
				continue;
			}

			// die
			if (s_copy[i][j] == '#' && is_adj_occ_trace(i, j)) {
				s_map[i][j] = 'L';
				continue;
			}
		}
	}
}

void print() {
	for (int j = 0; j < r; j++) {
		for (int i = 0; i < c; i++) {
			cout << char(s_map[j][i]);
		}
		cout << endl;
	}
	cout << endl;
}

bool no_change() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (s_map[i][j] != s_copy[i][j])
				return false;
		}
	}
	return true;
}

int count_map() {
	int count = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (s_map[i][j] == '#')
				count++;
		}
	}
	return count;
}
int main() {
	s_map = new int *[100];
	s_copy = new int *[100];
	for (int i = 0; i < 100; i++) {
		s_map[i] = new int[100];
		s_copy[i] = new int[100];
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			s_map[i][j] = -1;
			s_copy[i][j] = -1;
		}
	}

	string s;
	int row = 0;
	while (cin >> s) {
		c = s.length();
		for (int i = 0; i < s.length(); i++) {
			s_map[r][i] = s[i];
			s_copy[r][i] = s[i];
		}
		r++;
	}
	// print();
	copy();
	evolve_trace();
	print();
	int it = 0;
	int q = -1;
	while (!no_change() && q--) {
		evolve_trace();
		print();
		it++;
		if (it % 1000 == 0) {
			cout << "it\t" << it << "\t count_map() " << count_map() << endl;
		}
	}

	cout << r << "\t" << c << endl;

	cout << count_map() << endl;
	return 0;
}