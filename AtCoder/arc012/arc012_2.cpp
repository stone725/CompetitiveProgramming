#include <iostream>

using namespace std;

int main()
{
    int n;
    long double va, vb, l;
    cin >> n >> va >> vb >> l;
    for (int i = 0; i < n; i++)
    {
        l /= va;
        l *= vb;
    }
    cout << fixed << l << "\n";
}