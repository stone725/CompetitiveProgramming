#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n %= 30;
    string str = "123456";
    for (int i = 0; i < n; i++)
    {
        swap(str[i % 5], str[i % 5 + 1]);
    }
    cout << str << "\n";
}