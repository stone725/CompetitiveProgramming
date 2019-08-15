#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> check(n);
    for(int i = 0; i < 10; i++){
        cout << "?";
        int num = 1;
        for(int j = 0; j < n; j++){
            if(j / 5 == i){
                cout << " " << num;
                num *= 10;
            }else{
                cout << " " << 0;
            }
        }
        cout << "\n";
        cout.flush();
        int res;
        cin >> res;
        for(int j = i * 5; j / 5 == i; j++){
            int num = res % 10;
            switch(num){
            case 0:
            case 2:
                res -= 10;
            case 8:
                check[j] = false;
                break;
            case 1:
                res -= 10;
            case 9:
                check[j] = true;
                break;
            }
            res /= 10;
        }
    }
    cout << "!";
    for(auto&& i : check){
        if(i){
            cout << " " << 1;
        }else{
            cout << " " << 0;
        }
    }
    cout << "\n";
    cout.flush();
}