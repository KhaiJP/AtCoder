// this script highly refers to https://www.youtube.com/watch?v=60CJDyHJ11Q
#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0; i<(n); ++i)

using namespace std;

int main(){
    // std input
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<int>> A(H, vector<int>(W));
    rep(row, H)rep(col, W) cin >> A[row][col];

    vector<vector<int>> ans(H-h+1, vector<int>(W-w+1));
    
    /*
    grow: indicates row number of A
    lrow: indicates row number of the black rectangle
    gcol: indicates col number of A
    lcol: indicates col number of the black rectangle */
    rep(grow, H-h+1){
        // counter[num]: number of num in the grid
        vector<int> counter(N+1, 0);
        // number of numbers appeared in the whole grid except black area
        int num_kinds = 0;
        /* ----------------------------------------------*/
        auto add_to_counter = [&](int row, int col, int change=1){
            int x = A[row][col];
            if(counter[x] == 0) num_kinds++;
            counter[x] += change;
            if(counter[x] == 0) num_kinds--;
        };
        auto del_from_counter = [&](int i, int j){ add_to_counter(i, j, -1);};
        /* ----------------------------------------------*/
        // counts the number of num in the whole grid
        rep(row, H)rep(col, W) add_to_counter(row, col);
        // discounts, from the whole grid, the number of num in the black grid that stays at the left-most
        rep(lrow, h)rep(lcol, w-1) del_from_counter(grow+lrow, lcol);
        rep(gcol, W-w+1){
            rep(row, h) del_from_counter(grow+row, w-1+gcol);
            ans[grow][gcol] = num_kinds;
            rep(row, h) add_to_counter(grow+row, gcol);
        }
    }
    rep(row, ans.size()){
        rep(col, ans[row].size()) cout << ans[row][col] << " ";
        cout << "\n";
    }
    return 0;
}