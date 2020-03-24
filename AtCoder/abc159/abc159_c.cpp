#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long double l;
    cin >> l;
    cout << fixed << setprecision(12) << l * l * l / 27 << "\n";
}