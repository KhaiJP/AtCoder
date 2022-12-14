#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    int T, A, B;
    map<int, set<int>> D;
    for(int _=0; _<Q; _++){
        cin >> T >> A >> B;
        if(T==1){
            if(D.count(A)==1) D[A].insert(B);
            else D[A] = {B};
        }else if(T==2){
            if(D.count(A)==1 && D[A].count(B)==1) D[A].erase(B);
        }else if(T==3){
            if(D.count(A)==1 && D.count(B)==1 && D[A].count(B)==1 && D[B].count(A)==1){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }
    return 0;
}