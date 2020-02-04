#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &a, int n)
{

    cout << a[0];
    for (int j = 1; j < n; j++)
    {
        cout << " " << a[j];
    }
    cout << "\n";
    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        cout << a[0];
        for (int j = 1; j < n; j++)
        {
            cout << " " << a[j];
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    insertionSort(a, n);
}