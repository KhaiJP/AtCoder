#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

int a[100010];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> a[i];

   ll answer = 0;
   ll l = 0, r = 0;
   while(l < N){
    while(r+1 < N && a[r] < a[r+1]) ++r;
    answer += (r - l + 1) * (r - l + 2) / 2;
    l = r+1;
    r = l;
   }

   cout << answer << endl;
   return 0;
}