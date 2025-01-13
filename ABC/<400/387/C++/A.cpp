#include<iostream>
#include<tuple>
using namespace std;


tuple<int, int> get_input(){
    int a, b;
    cin >> a >> b;
    return make_tuple(a, b);
}


int main(){
    int a, b;
    tie(a, b) = get_input();
    cout << (a + b) * (a + b) << endl;
    return 0;
}
