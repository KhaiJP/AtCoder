#include<iostream>
using namespace std;
typedef pair<int, int> P;

bool isOtherSide_wrt_l1_l2(P l1, P l2, P p1, P p2);
int main(){
  P A; cin >> A.first >> A.second;
  P B; cin >> B.first >> B.second;
  P C; cin >> C.first >> C.second;
  P D; cin >> D.first >> D.second; 
  bool isConvex = isOtherSide_wrt_l1_l2(A,C,B,D) && isOtherSide_wrt_l1_l2(B,D,A,C);
  cout << (isConvex ? "Yes" : "No") << endl;
  return 0;
}

bool isOtherSide_wrt_l1_l2(P l1, P l2, P p1, P p2){
  // line l1_l2
  // (l2.first - l1.first)*(y - l1.second) - (l2.second - l1.second)*(x - l1.first)
  bool sgn_p1 = (l2.first - l1.first)*(p1.second - l1.second) - (l2.second - l1.second)*(p1.first - l1.first) > 0;
  bool sgn_p2 = (l2.first - l1.first)*(p2.second - l1.second) - (l2.second - l1.second)*(p2.first - l1.first) > 0;
  return sgn_p1 != sgn_p2;
}