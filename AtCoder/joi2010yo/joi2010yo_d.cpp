#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> cards(n);
    for (auto &&i : cards)
    {
        cin >> i;
    }
    sort(begin(cards), end(cards));
    set<string> check;
    do
    {
        string num;
        for (int i = 0; i < k; i++)
        {
            num += cards[i];
        }
        check.insert(num);
    } while (next_permutation(begin(cards), end(cards)));
    cout << check.size() << "\n";
}