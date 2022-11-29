#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool allEqual(vector<int> const &v){
    if(v.size()==0){
        return false;
    }
    return equal(v.begin()+1, v.end(), v.begin());
}

int main(){
    // input
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    // container of the powers of j(=2 or 3) of A[k] = a_k
    vector<int> A2(N);
    vector<int> A3(N);
    for(int i=0; i<N; i++){
        while(A[i]%2 == 0){
            A[i] = A[i]/2;
            A2[i]++;
        }
        while(A[i]%3 == 0){
            A[i] = A[i]/3;
            A3[i]++;
        }
    }
    // output if A contains two or more values
    if(!allEqual(A)){
        cout << -1;
        return 0;
    }
    
    int min2 = *min_element(A2.begin(), A2.end());
    int min3 = *min_element(A3.begin(), A3.end());
    transform(A2.begin(), A2.end(), A2.begin(), [=](int a){
        return a - min2;
    });
    transform(A3.begin(), A3.end(), A3.begin(), [=](int a){
        return a - min3;
    });
    int n2 = accumulate(A2.begin(), A2.end(), 0);
    int n3 = accumulate(A3.begin(), A3.end(), 0);
    cout << n2+n3;
    return 0;
}