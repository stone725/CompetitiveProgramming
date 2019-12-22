#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string str, mostfind = "", mostlong = "";
    map<string, int> many;
    while (cin >> str)
    {
        if (many[mostfind] < ++many[str])
        {
            mostfind = str;
        }
        if (mostlong.size() < many.size())
        {
            mostlong = str;
        }
    }
    cout << mostfind << " " << mostlong << "\n";
}