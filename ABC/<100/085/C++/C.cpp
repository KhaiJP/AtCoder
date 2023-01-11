#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef int64_t ll;
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
#define foreach(a , v) for(auto a : v)

int main(){
    int N, Y; cin >> N >> Y;
    Y /= 1000;
    vector<int> Bills = {10,5,1};
    vector dp(N+1, vector<int>(Y+1, -1));
    dp[0][0] = 0;
    rep(n,0,N)rep(y,0,Y+1){
        if(dp[n][y] == -1) continue;
        foreach(bill, Bills)if(y+bill <= Y) dp[n+1][y+bill] = 1;
    }
    if(dp[N][Y] != -1){
        int y = Y;
        int n = N;
        map<int, int> answer;
        while(n!=0){
            foreach(bill, Bills)if(y-bill >= 0 && dp[n-1][y-bill] != -1){
                ++answer[bill];
                --n;
                y -= bill;
                break;
            }
        }
        foreach(bill, Bills) cout << answer[bill] << ' ';
        cout << endl;
        return 0;
    }
    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    return 0;
}