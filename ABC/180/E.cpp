#include<iostream>
#include<vector>
#define rep(i,s,n) for(int i=s; i<(n); ++i)
#define INF 1e9
using namespace std;

int main(){
    int N; cin >> N;
    vector<vector<int>> XYZ(N, vector<int>(3, 0));
    rep(i,0,N)rep(j,0,3) cin >> XYZ[i][j];

    int maxS = (1<<N);
    vector<vector<int>> DP(N, vector<int>(maxS, INF));
    DP[0][0] = 0;
    rep(h,1,maxS)rep(cs,0,N)if(h&(1<<cs)){
        rep(ps,0,N){
            int d = abs(XYZ[cs][0]-XYZ[ps][0]) + abs(XYZ[cs][1]-XYZ[ps][1]) + max(0, XYZ[cs][2]-XYZ[ps][2]);
            DP[cs][h] = min(DP[cs][h], DP[ps][h-(1<<cs)]+d);
        }
    }
    cout << DP[0][maxS-1] << endl;
    return 0;
}
