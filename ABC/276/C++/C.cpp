#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

// function<vector<int>(vector<int>)>mapping

// int make_prev(vector<int>, int)
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
    // int N;
    // cin >> N;
    // vector<int> P(N);
    // for(int i=0; i<N; i++){
    //     cin >> P[i];
    // }
    int N = 10;
    vector<int> P = {9, 8, 6, 5, 10, 3, 1, 2, 4, 7};
    vector<int> arr(0);
    arr.push_back(P[N-1]);
    P.pop_back();
    while(true){
        int tmp = P.back();
        P.pop_back();
        if(tmp > arr.back()){
            // for(int i=0; i<arr.size(); i++){
            //     cout << arr[i] << "\n";
            // }
            int index = find_index(arr, tmp);
            arr.insert(arr.begin(), tmp);
            swap(arr[0], arr[index+1]);
            break;
        }else{
            arr.push_back(tmp);
        }
        
    }
    for(int i=0; i<P.size(); i++){
        cout << P[i] << " ";
    }
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    return  0;
    // }
    // int index = find_index(arr, 3);
    // arr.insert(arr.begin(), 3);
    // int l = arr.size();
    // for(int i=0; i<l; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    // swap(arr[0], arr[index+1]);
    // for(int i=0; i<l; i++){
    //     cout << arr[i] << " ";
    // }
    // return 0;
}

// 10
// 9 8 6 5 10 3 1 2 4 7

// 9 8 6 5 10 2 7 4 3 1

