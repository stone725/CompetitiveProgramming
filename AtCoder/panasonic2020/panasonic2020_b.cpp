#include <iostream>

using namespace std;

int main()
{
    long long h, w;
    cin >> h >> w;
    if (h == 1 || w == 1)
    {
        cout << "1\n";
    }
    else
    {
        cout << h * w / 2 + (h * w) % 2 << "\n";
    }
}