#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string str[2];
    for(auto&& i : str){
        cin >> i;
    }
    map<string, int> cnt;
    for(auto&& i : str){
        int n;
        cin >> n;
        cnt[i] = n;
    }
    string input;
    cin >> input;
    cnt[input]--;
    cout << cnt[str[0]] << " " << cnt[str[1]] << "\n";
}