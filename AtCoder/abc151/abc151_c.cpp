#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> wacnt(n);
    set<int> s;
    int ac = 0, wa = 0;
    for (int i = 0; i < m; i++)
    {
        int p;
        string str;
        cin >> p >> str;
        if (s.count(p))
        {
            continue;
        }
        if (str == "AC")
        {
            s.insert(p);
            ac++;
            wa += wacnt[p - 1];
        }
        else
        {
            wacnt[p - 1]++;
        }
    }
    cout << ac << " " << wa << "\n";
}