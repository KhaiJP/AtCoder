#include<iostream>
#include<deque>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    if(K>=N){
        for(int _=0; _<N; _++){
            cout << 0 << " ";
        }
        return 0;
    }
    deque<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int _=0; _<K; _++){
        A.pop_front();
        A.push_back(0);
    }
    for(int i=0; i<N; i++){
        cout << A[i] << " ";
    }
    return 0;
}