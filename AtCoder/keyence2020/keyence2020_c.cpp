#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, k, s;
    cin >> n;
    cin >> k;
    cin >> s;
    int max_s = 1e9;
    
    vector<int> ans;

    for(int i = 0; i < n; i++)
    {
        if(i < k)
        {
            ans.push_back(s);
        }
        else
        {
            if(s < max_s)
            {
                ans.push_back(s + 1);
            }
            else
            {
                ans.push_back(1);
            }
        }
    }

    for(int i = 0; i < n - 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[n - 1] << "\n";
}