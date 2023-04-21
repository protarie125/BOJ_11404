#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;

constexpr auto inf = int{ 987'654'321 };

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	auto adj = vvi(n, vi(n, inf));

	int m;
	cin >> m;
	while (0 < (m--)) {
		int x, y, w;
		cin >> x >> y >> w;

		if (w < adj[x - 1][y - 1]) {
			adj[x - 1][y - 1] = w;
		}
	}

	auto dist = vvi{ adj };
	for (auto k = 0; k < n; ++k) {
		for (auto i = 0; i < n; ++i) {
			for (auto j = 0; j < n; ++j) {
				if (i == j) {
					continue;
				}

				const auto& newDist = dist[i][k] + dist[k][j];
				if (newDist < dist[i][j]) {
					dist[i][j] = newDist;
				}
			}
		}
	}

	for (const auto& v : dist) {
		for (const auto& cost : v) {
			if (inf == cost) {
				cout << 0;
			}
			else {
				cout << cost;
			}
			cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}