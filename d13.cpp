#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int q;
vector<pii> v;
int main() {
	cin >> q;
	int min_r = q;
	int min_i;
	int nn = 0;
	while (cin.peek() != EOF) {
		if (cin.peek() != 'x') {
			int i;
			cin >> i;
			cin.ignore(1);
			cout << "i:\t" << i << endl;

			int quo = q / i;
			int r = (quo + 1) * i - q;
			cout << "Quo:\t" << (quo * i) << "\tR:\t" << r << endl;
			min_r = min(min_r, r);
			if (min_r == r) {
				min_i = i;
			}
			int t = i - nn;
			while (t < 0) {
				t += i;
			}
			v.push_back(pii(i, t));

		} else {
			cin.ignore(2);
		}
		nn++;
	}
	cout << min_r * min_i << endl;

	// sort(v.begin(), v.end());
	// reverse(v.begin(), v.end());
	long guess = v[0].second + v[0].first, index = 0, prev_prod = v[0].first;
	while (index < v.size() - 1) {
		long exp_q = v[index + 1].first;
		long exp_r = v[index + 1].second;
		cout << "guess:\t" << guess << "\texp_q\t" << exp_q << "\texp_r\t"
		     << exp_r << "\tprev_prod\t" << prev_prod << "\tr\t"
		     << (guess % exp_q) << endl;

		// if (guess > 500) {
		// 	break;
		// }
		if ((guess % exp_q) == exp_r) {
			cout << "ind" << endl;
			prev_prod *= v[index + 1].first;
			index++;

			cout << guess << endl;
		} else {
			guess += prev_prod;
		}
	}
	cout << "Fin:\t" << guess << endl;
	return 0;
}