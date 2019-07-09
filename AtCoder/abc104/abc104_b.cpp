#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string  str;
    cin >> str;
    if(str[0] != 'A'){
        cout << "WA\n";
        return 0;
    }
    string checkStr(begin(str) + 2, end(str) - 1);
    if(count(begin(checkStr), end(checkStr), 'C') != 1){
        cout << "WA\n";
        return 0;
    }
    int cnt = 0;
    for(int i = 1; i < str.size(); i++){
        cnt += 'A' <= str[i] && str[i] <= 'Z';
    }
    if(cnt == 1){
        cout << "AC\n";
    }else{
        cout << "WA\n";
    }
}