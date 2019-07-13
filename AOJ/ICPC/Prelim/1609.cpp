#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int cnt[26];
	vector<char> vote;
	while (cin >> n && n) {
		vote.resize(n);
		for (auto&& i : vote) {
			cin >> i;
		}
		for (int i = 0; i < 26; i++) {
			cnt[i] = 0;
		}
		bool br = true;
		char firstP = 'A', secondP = 'B';
		for (int i = 1; i <= n; i++) {
			cnt[vote[i - 1] - 'A']++;
			if (firstP != vote[i - 1] && cnt[firstP - 'A'] < cnt[vote[i - 1] - 'A']) {
				secondP = firstP;
				firstP = vote[i - 1];
			} else if (firstP != vote[i - 1] && cnt[secondP - 'A'] < cnt[vote[i - 1] - 'A']) {
				secondP = vote[i - 1];
			}
			if (cnt[firstP - 'A'] > cnt[secondP - 'A'] + n - i) {
				cout << firstP << " " << i << "\n";
				br = false;
				break;
			}
		}
		if (br) {
			cout << "TIE\n";
		}
	}
}