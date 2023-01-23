#include<iostream>
using namespace std;

int main(){
  int H, W, R, C; cin >> H >> W >> R >> C;
  int answer = 0;
  if(H != 1){
    if(R == 1 || R == H) answer += 1;
    else if(1 < R && R < H) answer += 2;
  }
  if(W != 1){
    if(C == 1 || C == W) answer += 1;
    else if( 1 < C && C < W) answer += 2;
  }
  cout << answer << endl;
  return 0;
}