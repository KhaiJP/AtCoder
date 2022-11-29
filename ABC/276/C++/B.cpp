// this script is 99% copy from AsindE's submit num 36862751 for study
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int _ = 0; _ < m; _++){
        int A, B;
        cin >> A >> B;
        g[A-1].push_back(B-1);
        g[B-1].push_back(A-1);
    }
    for (int j = 0; j < n; j++){
        sort(g[j].begin(), g[j].end());
        cout << g[j].size();
        for (auto v : g[j]){
            cout << " " << v+1;
        }
        cout << "\n";
    }
    return 0;
}