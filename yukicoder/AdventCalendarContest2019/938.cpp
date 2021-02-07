#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> cnt;
    vector<string> vs(n);
    for (auto &&i : vs)
    {
        string str;
        cin >> str >> i;
        cnt[str]++;
    }
    for (auto &&i : vs)
    {
        if (cnt[i] == 0)
        {
            cout << i << "\n";
            cnt[i]++;
        }
    }
}