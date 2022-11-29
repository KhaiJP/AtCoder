#include<iostream>
#include<vector>
using namespace std;
int find_index(vector<int> arr, int n){
    int psuedo_max = 0;
    int index = 0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i]<n && arr[i]>psuedo_max){
            psuedo_max = arr[i];
            index = i;
        }
    }
    return index;
}

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i=0; i<N; i++){
        cin >> P[i];
    }
    vector<int> arr(0);
  
    arr.push_back(P[N-1]);
    P.pop_back();
    while(true){
        int tmp = P.back();
        P.pop_back();
        if(tmp > arr.back()){
            int index = find_index(arr, tmp);
            arr.insert(arr.begin(), tmp);
            swap(arr[0], arr[index+1]);
            break;
        }else{
            arr.push_back(tmp);
        }
    }
    // output
    for(int i=0; i<P.size(); i++){
        cout << P[i] << " ";
    }for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    return  0;
}