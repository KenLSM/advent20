#include <bits/stdc++.h>
using namespace std;
#define pss std::pair<std::string, int>
bool *seen, *old_seen, *seen_jmp;
int size;
void cpy_seen() {
	for (int i = 0; i < size; i++) {
		old_seen[i] = seen[i];
	}
}

void rst_seen() {
	for (int i = 0; i < size; i++) {
		seen[i] = old_seen[i];
	}
}

bool emulate(std::vector<pss> v) {
	int acc = 0, pc = 0, c = 0;
	cout << size << endl;
	while (pc < size) {
		cout << "pc: " << pc << " size " << size << endl;

		if (pc < 0) {
			return true;
		}
		c++;
		if (!(c % 100)) {
			std::cout << c << std::endl;
		}
		if (seen[pc]) {
			return false;
		}

		pss p = v[pc];
		// std::cout << "pc: " << pc << std::endl;
		seen[pc] = true;
		if (p.first == "nop") {
			pc++;
			// std::cout << "nop" << pc << std::endl;
			continue;
		}
		if (p.first == "acc") {
			pc++;
			acc += p.second;
			// std::cout << "acc" << pc << std::endl;
			continue;
		}
		if (p.first == "jmp") {
			pc += p.second;
			// std::cout << "jump " << p.second << std::endl;
			continue;
		}
	}
	std::cout << "fin acc: " << acc << std::endl;
	return true;
}

int main() {
	std::vector<pss> v;

	std::cout << "size " << size << std::endl;
	while (std::cin) {
		std::string s;
		int i;
		std::cin >> s >> i;
		if (s.empty()) {
			break;
		}
		v.push_back(pss(s, i));

		cout << "s " << s << i << endl;
	}
	size = v.size();

	seen = new bool[size];
	old_seen = new bool[size];

	for (int i = 0; i < size; i++) {
		seen[i] = false;
	}
	cpy_seen();

	for (int i = 0; i < size; i++) {
		if (v[i].first != "jmp") {
			continue;
		}
		std::cout << "jmp -> nop " << i << std::endl;
		rst_seen();
		std::string t = v[i].first;
		std::cout << "jmp -> nop " << v[i].first << v[i].second << std::endl;
		v[i].first = "nop";
		std::cout << "jmp -> nop " << v[i].first << v[i].second << std::endl;
		if (emulate(v)) {
			std::cout << "yes" << i << std::endl;
			break;
		} else {
			std::cout << "fail" << i << std::endl;
		}

		std::cout << "jmp -> nop " << v[i].first << v[i].second << std::endl;

		v[i].first = t;

		std::cout << "jmp -> nop " << v[i].first << v[i].second << std::endl;
	}

	// for (int i = 0; i > size; i++) {
	// 	if (v[i].first != "nop") {
	// 		continue;
	// 	}

	// 	rst_seen();

	// 	std::string t = v[i].first;

	// 	std::cout << "nop -> jmp" << v[i].first << v[i].second << std::endl;
	// 	v[i].first = "jmp";
	// 	std::cout << "nop -> jmp" << v[i].first << v[i].second << std::endl;
	// 	if (emulate(v)) {
	// 		std::cout << "yes" << i << std::endl;
	// 		break;
	// 	} else {
	// 		std::cout << "fail" << i << std::endl;
	// 	}
	// 	std::cout << "nop -> jmp" << v[i].first << v[i].second << std::endl;
	// 	v[i].first = t;
	// 	std::cout << "nop -> jmp" << v[i].first << v[i].second << std::endl;
	// }

	return 0;
}