#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, c;
	string str;
	cin >> n >> k >> c;
	cin >> str;
	vector<int> l, r;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'x') continue;
		l.push_back(i + 1);
		if (l.size() == k) break;
		i += c;
	}
	for (int j = n - 1; j >= 0; j--) {
		if (str[j] == 'x') continue;
		r.push_back(j + 1);
		if (r.size() == k) break;
		j -= c;
	}
	sort(begin(r), end(r));
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		if (l[i] == r[i]) {
			ans.push_back(l[i]);
		}
	}
	for (auto&& i : ans) {
		cout << i << "\n";
	}
}
