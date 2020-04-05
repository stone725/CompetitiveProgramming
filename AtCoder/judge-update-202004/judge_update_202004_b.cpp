#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, string>> ball(n);
    for (auto &&i : ball)
    {
        cin >> i.first >> i.second;
        if (i.second == "R")
        {
            i.first -= 100000;
        }
    }
    sort(begin(ball), end(ball));
    for (auto &&i : ball)
    {
        if (i.second == "R")
        {
            i.first += 100000;
        }
        cout << i.first << "\n";
    }
}