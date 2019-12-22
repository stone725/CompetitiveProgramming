#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << 1 << string(n - 1, '0') << 7 << "\n";
}