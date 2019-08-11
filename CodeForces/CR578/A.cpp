#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    string ans = string(10, '0');
    for(auto&& i : str){
        if(i == 'L'){
            for(int j = 0; j < 10; j++){
                if(ans[j] == '0'){
                    ans[j] = '1';
                    break;
                }
            }
        }else if(i == 'R'){
            for(int j = 9; j >= 0; j--){
                if(ans[j] == '0'){
                    ans[j] = '1';
                    break;
                }
            }
        }else{
            ans[i - '0'] = '0';
        }
    }
    cout << ans << "\n";
}