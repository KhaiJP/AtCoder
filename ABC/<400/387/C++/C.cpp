#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
using ll = int64_t;
using DP = vector<vector<vector<ll>>>;
#define rep(i, s, t) for(ll i = s; i < t; i++)


bool is_snake(ll x);
ll calc_same_digits(ll x);
ll calc_less_digits(ll x);
ll count_snake_nums(ll x);
tuple<ll, ll> get_input();
ll solve(ll l, ll r);


int main(){
    ll l, r;
    tie(l, r) = get_input();
    cout << solve(l, r) << endl;
    return 0;    
}


ll solve(ll l, ll r){
    ll snake_r = count_snake_nums(r);
    ll snake_l = count_snake_nums(l-1);
    return snake_r - snake_l;
}


tuple<ll, ll> get_input(){
    ll l, r;
    cin >> l >> r;
    return make_tuple(l, r);
}


ll count_snake_nums(ll x){
    ll num_same_digits = calc_same_digits(x);
    ll num_less_digits = calc_less_digits(x);
    return num_same_digits + num_less_digits;
}


ll calc_less_digits(ll x){
    string x_str = to_string(x);
    ll num_digits = x_str.size();
    ll ans = 0;
    ll z = 0;
    // 9, 99, 999, ... というに数に対して蛇数を数える
    // ただし9..9はxより1桁以上小さい
    rep(i, 0, num_digits-1){
        z = z * 10 + 9;
        ans += calc_same_digits(z);
    }

    return ans;
}


ll calc_same_digits(ll x){
    string x_str = to_string(x);
    ll num_digits = x_str.size();
    ll head_digit = x_str[0] - '0';
    // dp[y][d][f] = 先頭の数字がyで、先頭からd番目までの数字を決定した蛇数の数。f=1ならx未満が確定している。
    DP dp(head_digit+1, vector<vector<ll>>(num_digits, vector<ll>(2, 0)));
    
    // dpテーブルの初期化
    rep(i, 1, head_digit) dp[i][0][1] = 1;
    dp[head_digit][0][0] = 1;
    

    rep(d, 0, num_digits-1){
        // 先頭の数字がxの先頭の数字と同じ場合
        // すでにx未満が確定している場合、0..head_digit-1までの数字に遷移できる
        dp[head_digit][d+1][1] += head_digit * dp[head_digit][d][1];

        // x未満が確定していない場合
        ll x_next_d = x_str[d+1] - '0';
        // xのd+1桁目がhead_digitよりも小さい場合は、0..x_next_dまでの数字に遷移できる
        if(x_next_d < head_digit){
            // 0..x_next_d-1に遷移した場合は、x未満が確定する
            dp[head_digit][d+1][1] += x_next_d * dp[head_digit][d][0];
            // x_next_dに遷移した場合は、x未満が確定しない
            dp[head_digit][d+1][0] += dp[head_digit][d][0];
        }else{
            // xのd+1桁目がhead_digit以上の場合は、0..head_digit-1までの数字に遷移でき、x未満が確定する
            dp[head_digit][d+1][1] += head_digit * dp[head_digit][d][0];
        }

        // 先頭の数字がxの先頭の数字よりも小さい場合は、x未満が確定している
        rep(y, 1, head_digit){
            // 0からy-1までの数字に遷移できる
            dp[y][d+1][1] += y * dp[y][d][1];
        }
    }

    ll ans = 0;
    // x未満の蛇数の個数
    rep(y, 1, head_digit+1){
        ans += dp[y][num_digits-1][1];
    }

    // x自身が蛇数である場合も考慮する
    if(is_snake(x)){
      ++ans;
    }
 
    return ans;
}


bool is_snake(ll x){
    // 1桁の場合は蛇数とする
    if(x < 10) return true;
    string x_str = to_string(x);
    ll num_digits = x_str.size();
    ll head_digit = x_str[0] - '0';
    
    rep(i, 1, num_digits){
        char &c = x_str[i];
        ll num_c = c - '0';
        if(head_digit <= num_c) return false;
    }
    return true;
}
