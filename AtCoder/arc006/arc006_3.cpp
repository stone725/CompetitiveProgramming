#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> groups;
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        if (lower_bound(begin(groups), end(groups), w) != end(groups))
        {
            *lower_bound(begin(groups), end(groups), w) = w;
        }
        else
        {
            groups.push_back(w);
        }
        sort(begin(groups), end(groups));
    }
    cout << groups.size() << "\n";
}