#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++){
        if(i % 2 && str[i] != ' '){
            cout << "No\n";
            return 0;
        }
        if(i % 2 == 0 && (str[i] < 'a' || 'z' < str[i])){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}