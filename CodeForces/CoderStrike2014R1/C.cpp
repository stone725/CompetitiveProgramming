#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<set<char>> vec;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (!i)
        {
            vec.resize(str.size());
        }
        for (int j = 0; j < str.size(); j++)
        {
            vec[j].insert(str[j]);
        }
    }
    string ans;
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[j].size() == 1)
        {
            if (vec[j].count('?'))
            {
                ans += "a";
            }
            else
            {
                ans += *vec[j].begin();
            }
        }
        else
        {
            if (vec[j].size() == 2 && vec[j].count('?'))
            {
                ans += *vec[j].rbegin();
            }
            else
            {
                ans += '?';
            }
        }
    }
    cout << ans << "\n";
}