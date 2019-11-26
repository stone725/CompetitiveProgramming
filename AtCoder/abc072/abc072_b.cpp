#include <iostream>
#include <string>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;

int main(){
    string str;
    cin >> str;
    int n = str.size();
    for(auto i : irange(0, n, 2)){
        cout << str[i];
    }
    cout << "\n";
}