#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int maxnum = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(~maxnum){
            maxnum = max(maxnum, a);
        }
        s -= a;
        if(s < 0){
            if(!~maxnum){
                cout << "NO\n";
                return 0;
            }
            s += maxnum;
            maxnum = -1;
        }
    }
    cout << "YES\n";
}