#include <iostream>
#include <string>

using namespace std;

bool check(string str){
    if(str.size() < 7){
        return false;
    }
    auto p = str.find("okyo");
    return p == string::npos ? false : str.find("ech", p) != string::npos;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(check(str)){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}