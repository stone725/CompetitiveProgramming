#include <iostream>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    cout << (h - 1) * w + h * (w - 1) << "\n";
}