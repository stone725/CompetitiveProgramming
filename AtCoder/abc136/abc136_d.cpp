#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    vector<int> ans(n), left, right;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'L')
        {
            left.push_back(i);
        }
        else
        {
            right.push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'L')
        {
            int p = *(lower_bound(begin(right), end(right), i) - 1);
            int s = i - p;
            if (s % 2)
            {
                ans[p + 1]++;
            }
            else
            {
                ans[p]++;
            }
        }
        else
        {
            int p = *upper_bound(begin(left), end(left), i);
            int s = p - i;
            if (s % 2)
            {
                ans[p - 1]++;
            }
            else
            {
                ans[p]++;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[n - 1] << "\n";
}