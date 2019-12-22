#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<char, char> change;
    for (int i = 0; i < n; i++)
    {
        char from, to;
        cin >> from >> to;
        change[from] = to;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        if (change.count(c))
        {
            cout << change[c];
        }
        else
        {
            cout << c;
        }
    }
    cout << "\n";
}