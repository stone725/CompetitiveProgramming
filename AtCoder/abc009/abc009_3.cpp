#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    if(k <= 1){
        cout << str << "\n";
        return 0;
    }
    string minstr = str;
    sort(begin(minstr), end(minstr));
    set<int> diff;
    string ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;
            string checkstr = minstr;
            checkstr[j] = 'z' + 1;
            sort(begin(checkstr), end(checkstr));
            for(int k = i + 1; k < n; k++){
                for(int l = 0; l < n; l++){
                    if('z' < checkstr[l]){
                        cnt++;
                        break;
                    }
                    if(checkstr[l] == str[k]){
                        checkstr[l] = 'z' + 1;            
                        sort(begin(checkstr), end(checkstr));
                        break;
                    }
                }
            }
            if(cnt <= k - (str[i] != minstr[j])){
                k -= str[i] != minstr[j];
                ans += minstr[j];
                minstr[j] = 'z' + 1;            
                sort(begin(minstr), end(minstr));
                break;
            }
        }
    }
    cout << ans << "\n";
}