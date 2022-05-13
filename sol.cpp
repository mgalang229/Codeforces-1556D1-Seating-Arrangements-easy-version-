#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(m);
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		vector<int> new_a = a;
		sort(new_a.begin(), new_a.end());
		vector<bool> visited(m, false);
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] == new_a[j] && !visited[j]) {
					if (j + 1 < m) {
						if (visited[j + 1] || a[i] != new_a[j + 1]) {
							visited[j] = true;
							break;
						}
					} else {
						visited[j] = true;
					}
				} else if (visited[j]) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
