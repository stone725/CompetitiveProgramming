#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    cout << (1 << n) / (1 << k) << "\n";
}