#include <bits/stdc++.h>

using namespace std;
#define N 0
#define E 1
#define S 2
#define W 3

int bearing = E, x = 0, y = 0;
int wp_x = 10, wp_y = 1, x_2 = 0, y_2 = 0;

int main() {
	char c;

	while (cin >> c) {
		int a, t_b;
		cin >> a;
		bool is_f = c == 'F';
		bool is_r = c == 'R' || c == 'L';
		cout << endl;
		cout << "Q:\t" << a << "\t|";
		if (is_r) {
			int count = a / 90;
			cout << "Rot:\t" << count << endl;

			bearing += c == 'R' ? count : -count;
			bearing += 4;
			bearing %= 4;

			// part two
			if (c == 'R') {
				int t_a = count;
				while (t_a--) {
					int wp_t = wp_x;
					wp_x = wp_y * 1;
					wp_y = wp_t * -1;
				}
			} else {
				int t_a = count;
				while (t_a--) {
					int wp_t = wp_x;
					wp_x = wp_y * -1;
					wp_y = wp_t * 1;
				}
			}

			continue;
			cout << "WP:\t" << wp_x << "\t|\t" << wp_y << endl;
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

		// part two
		if (is_f) {
			x_2 += wp_x * a;
			y_2 += wp_y * a;
		} else {
			switch (c) {
			case 'N': wp_y += a; break;
			case 'S': wp_y += -a; break;
			case 'E': wp_x += a; break;
			case 'W': wp_x += -a; break;
			}
		}

		cout << "WP:\t" << wp_x << "\t|\t" << wp_y << endl;
		cout << "Two: " << x_2 << " : " << y_2 << endl;
	}
	cout << endl;
	cout << "One: " << abs(x) + abs(y) << endl;
	cout << "Two: " << abs(x_2) + abs(y_2) << endl;
	return 0;
}