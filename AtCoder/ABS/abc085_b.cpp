#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> cnt;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        cnt.insert(d);
    }
    cout << cnt.size() << "\n";
}