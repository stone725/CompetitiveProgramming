#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int n;
string str;

int main()
{
    cin >> n;
    cin >> str;
    set<string> first, second, third;
    for (int i = 0; i < n; i++)
    {
        for (auto &&j : second)
        {
            third.insert(j + str[i]);
        }
        for (auto &&j : first)
        {
            second.insert(j + str[i]);
        }
        first.insert(string(1, str[i]));
    }
    cout << third.size() << "\n";
}