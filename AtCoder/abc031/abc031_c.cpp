#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> in(n);
	for (auto &&i : in)
	{
		cin >> i;
	}
	int ans = -50 * n;
	for (int i = 0; i < n; i++)
	{
		int score = -51 * n, p = i;
		for (int j = 0; j < i; j++)
		{
			int info = 0;
			for (int k = j + 1; k <= i; k += 2)
			{
				info += in[k];
			}
			if (score < info)
			{
				p = j;
				score = info;
			}
		}
		for (int j = i + 1; j < n; j++)
		{
			int info = 0;
			for (int k = i + 1; k <= j; k += 2)
			{
				info += in[k];
			}
			if (score < info)
			{
				p = j;
				score = info;
			}
		}
		ans = max(ans, accumulate(begin(in) + min(i, p), begin(in) + max(i, p) + 1, 0) - score);
	}
	cout << ans << "\n";
}