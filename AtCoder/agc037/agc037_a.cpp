#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    vector<string> cnt(1, string(1, str[0]));
    for(int i = 1; i < str.size(); i++){
        for(int j = 1; i + j <= str.size(); j++){
            if(cnt.back() != str.substr(i, j)){
                cnt.push_back(str.substr(i, j));
                i += j - 1;
                break;
            }
        }
    }
    cout << cnt.size() << "\n";
}