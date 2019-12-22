#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int ans[2] = {};
    cin >> str;
    for (int i = 0; i + 3 <= str.size(); i++)
    {
        ans[0] += str.substr(i, 3) == "JOI";
        ans[1] += str.substr(i, 3) == "IOI";
    }
    for (auto &&i : ans)
    {
        cout << i << "\n";
    }
}