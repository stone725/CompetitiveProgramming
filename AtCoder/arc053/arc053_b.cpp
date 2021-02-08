#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int cnt[26] = {};
    for(auto&& i : str){
        cnt[i - 'a']++;
    }
    int odd = 0, even = 0;
    for(auto&& i : cnt){
        odd += i % 2;
        even += i / 2;
    }
    if(odd == 0){
        cout << str.size() << "\n";
    }
    else{
        cout << 1 + (even / odd) * 2 << "\n";
    }
}