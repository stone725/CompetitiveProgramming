#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        cnt += str[i] != str[i - 1];
    }
    cout << cnt << "\n";
}