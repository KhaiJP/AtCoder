#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  int N, K; cin >> N >> K;
  double oneK, twoK, threeK;
  double smaller = (K-1) * 1. / N, bigger = (N-K) * 1. / N, exact = 1. / N;
  oneK   = 6 * smaller * exact * bigger;
  twoK   = 3 * smaller * exact * exact + 3 * bigger * exact * exact;
  threeK = 1 * exact * exact * exact;

  cout << fixed << setprecision(12) << oneK + twoK + threeK << endl;
  return 0;
}