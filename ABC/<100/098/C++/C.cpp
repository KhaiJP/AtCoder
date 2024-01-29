#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int num_east[300010], N, answer = 10000000;

int main(){
  cin >> N;
  rep(i, 0, N){
    char c; cin >> c;
    num_east[i+1] = num_east[i] + (c == 'E');
  }

  rep(i, 1, N+1){
    // number of guys on the left side, who face west
    int num_west_left  = (i-1) - num_east[i-1];
    // number of guys on the right side, who face east
    int num_east_right = num_east[N] - num_east[i];
    answer = min(answer, num_west_left + num_east_right);
  }

  cout << answer << endl;
  return 0;
}