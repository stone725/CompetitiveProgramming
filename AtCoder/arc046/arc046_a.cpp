#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << string(n / 9 + !!(n % 9), (n - 1) % 9 + 1 + '0') << "\n";
}