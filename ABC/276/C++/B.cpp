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

6 6
3 6
1 3
5 6
2 5
1 2
1 6

3 2 3 6
2 1 5
2 1 6
0
2 2 6
3 1 3 5


3 2 3 6
2 1 5
2 1 6
0
2 2 6
3 1 3 5

3 2 3 6
2 1 5
2 1 6
0
2 2 6
3 1 3 5

