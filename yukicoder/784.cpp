#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    string ans = "";
    for(int i = 0; i < str.size(); i++){
        if(i && i % 3 == 0){
            ans = "," + ans;
        }
        ans = str[str.size() - i - 1] + ans; 
    }
    cout << ans << "\n";
}