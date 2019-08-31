#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(const string l, const string r){
    return string(rbegin(l), rend(l)) < string(rbegin(r), rend(r));
}

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(auto&& i : s){
        cin >> i;
    }
    sort(begin(s), end(s), comp);
    for(auto&& i : s){
        cout << i << "\n";
    }
}