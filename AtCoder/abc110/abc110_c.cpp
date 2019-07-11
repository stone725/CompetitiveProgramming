#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    string s, t;
    cin >> s;
    cin >> t;
    vector<vector<int>> a, b;
    map<char, int> m;
    for(int i = 0; i < s.size(); i++){
        if(m.count(s[i])){
            a[m[s[i]]].push_back(i);
        }else{
            m[s[i]] = a.size();
            a.push_back(vector<int>(1, i));
        }
    }
    m.clear();
    for(int i = 0; i < t.size(); i++){
        if(m.count(t[i])){
            b[m[t[i]]].push_back(i);
        }else{
            m[t[i]] = b.size();
            b.push_back(vector<int>(1, i));
        }
    }
    if(a == b){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}