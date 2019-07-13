#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<int> p[10];
vector<char> input;

bool check(int num) {
	string str = to_string(num);
	for (auto&& i : p[str[0] - '0']) {
		if (i + str.size() > n) {
			break;
		}
		bool check = true;
		for (int j = 0; j < str.size(); j++) {
			if (input[i + j] != str[j]) {
				check = false;
				break;
			}
		}
		if (check) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	input.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		p[input[i] - '0'].push_back(i);
	}
	for (int i = 0; i < 10000000; i++) {
		if (check(i)) {
			cout << i << "\n";
			return 0;
		}
	}
}