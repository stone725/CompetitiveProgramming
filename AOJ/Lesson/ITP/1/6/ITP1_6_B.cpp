#include <iostream>
#include <map>
#include <set>
#

using namespace std;

int main()
{
    int n;
    char c[] = {'S', 'H', 'C', 'D'};
    cin >> n;
    map<char, set<int>> m;
    for (auto &&i : c)
    {
        for (int j = 1; j <= 13; j++)
        {
            m[i].insert(j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        char mark;
        do
        {
            cin >> mark;
        } while (mark < 'A' || 'Z' < mark);
        int num;
        cin >> num;
        m[mark].erase(num);
    }
    for (auto &&i : c)
    {
        for (auto &&j : m[i])
        {
            cout << i << " " << j << "\n";
        }
    }
}