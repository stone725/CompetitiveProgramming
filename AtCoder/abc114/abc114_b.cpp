#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;
    int ans = 753;
    for(int i = 0; i + 3 <= str.size(); i++){
        ans = min(ans, abs(753 - stoi(str.substr(i, 3))));
    }
    cout << ans << "\n";
}