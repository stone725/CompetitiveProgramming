#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(const pair<int, int> &l, const pair<int, int> &r)
{
    return l.second < r.second;
}

int main()
{
    int n;
    cin >> n;
    int ans[2] = {n / 2, n / 2};
    vector<int> input;
    map<int, int> cnt[2];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        input.push_back(num);
        cnt[i % 2][num]++;
    }
    auto cnt0 = max_element(begin(cnt[0]), end(cnt[0]), comp);
    auto cnt1 = max_element(begin(cnt[1]), end(cnt[1]), comp);
    ans[0] = n / 2 - cnt0->second;
    ans[1] = n / 2 - cnt1->second;
    int first = cnt0->first;
    int second = cnt1->first;
    if (first == second)
    {
        cnt[0][first] = 0;
        cnt[1][second] = 0;
        int check0 = n / 2 - (max_element(begin(cnt[0]), end(cnt[0]), comp)->second);
        int check1 = n / 2 - (max_element(begin(cnt[1]), end(cnt[1]), comp)->second);
        cout << min(ans[0] + check1, ans[1] + check0) << "\n";
        return 0;
    }
    cout << ans[0] + ans[1] << "\n";
}