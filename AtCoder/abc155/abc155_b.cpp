#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a % 2)
            continue;
        if (a % 3 && a % 5)
        {
            cout << "DENIED\n";
            return 0;
        }
    }
    cout << "APPROVED\n";
}