#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n + n % 2 - !(n % 2) << "\n";
}