#include <iostream>
using namespace std;

int main(){
    string s ;
    cin >> s;
    int l = s.size();
    for (int i = l-1; 0 <= i ; i--){
        if (s[i] == 'a'){
            cout << i+1 ;
            return 0;
        }
    }
    cout << -1;
    return 0;
}