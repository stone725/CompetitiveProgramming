#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    switch (x % 7)
    {
    case 0:
        cout << "thu";
        break;
    case 1:
        cout << "fri";
        break;
    case 2:
        cout << "sat";
        break;
    case 3:
        cout << "sun";
        break;
    case 4:
        cout << "mon";
        break;
    case 5:
        cout << "tue";
        break;
    case 6:
        cout << "wed";
        break;
    }
    cout << "\n";
}