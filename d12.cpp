#include <bits/stdc++.h>

using namespace std;
#define N 0
#define E 1
#define S 2
#define W 3

int bearing = E, x = 0, y = 0;

int main() {
	char c;

	while (cin >> c) {
		int a, t_b;
		cin >> a;
		bool is_f = c == 'F';
		bool is_r = c == 'R' || c == 'L';
		cout << "Q:\t" << a << "\t|";
		if (is_r) {
			int count = a / 90;
			cout << "Rot:\t" << count << endl;

			bearing += c == 'R' ? count : -count;
			bearing += 4;
			bearing %= 4;
			continue;
		}
		if (!is_f) {
			t_b = bearing;
			switch (c) {
			case 'N': bearing = N; break;
			case 'S': bearing = S; break;
			case 'E': bearing = E; break;
			case 'W': bearing = W; break;
			}
			cout << "F:\t";
		} else {
			cout << "NF:\t";
		}
		switch (bearing) {
		case N: y += a; break;
		case S: y += -a; break;
		case E: x += a; break;
		case W: x += -a; break;
		}

		cout << bearing << endl;
		cout << x << " : " << y << " : " << bearing << endl;
		if (!is_f) {
			bearing = t_b;
		}
	}
	cout << abs(x) + abs(y) << endl;
	return 0;
}