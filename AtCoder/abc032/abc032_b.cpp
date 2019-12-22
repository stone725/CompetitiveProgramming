#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    string str;
    int n;
    set<string> s;
    cin >> str;
    cin >> n;
    for (int i = 0; i + n <= str.size(); i++)
    {
        s.insert(str.substr(i, n));
    }
    cout << s.size() << "\n";
}