#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int ans = 0;
        for(int i = 0; i + 5 <= str.size(); i++){
            if(str.substr(i, 5) == "tokyo" || str.substr(i, 5) == "kyoto"){
                ans++;
                i += 4;
            }
        }
        cout << ans << "\n";
    }
}