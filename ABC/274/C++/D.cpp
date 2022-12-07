#include<iostream>
#include<vector>
#include<numeric>
#define rep(i,n) for(int i=0; (i)<(n); ++i)
using namespace std;

bool isAchievable(vector<int> v, int t, bool isY);

int main(){
    // int N = 3; int x = -1; int y = 1;
    // vector<int> A_e = {1}; vector<int> A_o{2,3};
    int N, x, y; cin >> N >> x >> y;
    vector<int> A_e(N/2); vector<int> A_o((N+1)/2);
    rep(i,N) (i)%2==0 ? cin>>A_o[i/2] : cin>>A_e[i/2];
    (isAchievable(A_o, x, false) && isAchievable(A_e, y, true)) ? cout<<"Yes" : cout<<"No";
    cout << endl;
    return 0;
}

bool isAchievable(vector<int> v, int t, bool isY){
    int L = accumulate(v.begin(), v.end(), 0);
    int N = v.size();
    vector<vector<bool>> DP(N, vector<bool>(2*L+1, false));
    DP[0][ v[0]+L] = true;
    DP[0][-v[0]+L] = isY;
    for(int r=1; r<N; ++r){
        for(int c=0; c<=2*L; ++c){
            if(0<=c-v[r]   && DP[r-1][c-v[r]]) DP[r][c] = true; 
            if(c+v[r]<=2*L && DP[r-1][c+v[r]]) DP[r][c] = true;
        }
    }
    return -L<=t && t<=L && DP[N-1][t+L];
}