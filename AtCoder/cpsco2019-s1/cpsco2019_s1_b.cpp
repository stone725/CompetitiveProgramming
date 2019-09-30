#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;
    sort(begin(str), end(str));
    int cnt = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] != str[0]){
            break;
        }
        cnt++;
    }
    if(str.size() % cnt){
        cout << "No\n";
        return 0;
    }
    for(int i = 0; i < str.size(); i += cnt){
        if(str[i] != str[i + cnt - 1]){
            cout << "No\n";
            return 0;
        }
        if(i + cnt != str.size() && str[i] == str[i + cnt]){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}