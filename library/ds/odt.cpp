#include <iostream>
#include <iterator>
#include <map>

int main() {
	int N, Q;
	std::cin >> N >> Q;

	std::map<int, int> odt;
	odt[0] = odt[N+1] = 0;
	auto cur = odt.find(0);

	for (int i = 1; i <= N; i++) {
		int x;
		std::cin >> x;
		if (cur->second != x) {
			odt[i] = x;
			cur = odt.find(i);
		}
	}

	auto Cut = [&](int i) -> int {
		if (!odt.count(i)) {
			odt[i] = std::prev(odt.upper_bound(i))->second;
		}
		return 0;
	};

	auto Union = [&](int i) -> int {
		if (odt.count(i)) {
			auto it = odt.find(i);
			if (it->second == std::prev(it)->second) {
				odt.erase(it);
			}
		}
		return 0;
	};

	while (Q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int x, l, r;
			std::cin >> x >> l >> r;
			Cut(l), Cut(r+1);
			odt.erase(odt.find(l), odt.find(r+1));
			odt[l] = x;
		} else {
			int i;
			std::cin >> i;
			Cut(i), Cut(i+1);
			auto it = odt.find(i);
			int x = it->second;
			std::cout << x << '\n';
		}
	}
}
