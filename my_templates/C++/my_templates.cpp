#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<numeric>
#include<atcoder/all>

#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;
using namespace atcoder;

// // access map elements
// for(auto const& pair : map_instance){
//   // key  : pair.first;
//   // value: pair.secont;
// }

// // sort a vector
// sort(v.begin(), v.end())

// // handling string
// string s = "absdta"; //definition
// // s[1] : 'a'::char
// s[1] = 'A' // "Absdta"
// s.size() // length
// char(65): 'A', char(90): 'Z', char(97): 'a', char(122): 'z'
// s.find('char' or "string") != npos : std::string::npos
// -> true if s contains 'char' or "string"

void primeFactoring(int N, map<int,int>& pfs);
void primeFactoring(int N, map<int,int>& pfs){
  while(N%2 == 0){
    N /= 2;
    pfs[2] += 1;
  }
  int div = 3;
  while(div*div < N){
    while(N%p == 0){
      N /= p;
      pfs[p] += 1;
    }
    div += 2;
  }
  if(N!=1) pfs[N] += 1;
}

bool isPrime(int N);
bool isPrime(int N){
  if(N == 1) return false;
  if(N == 2) return true;
  int div = 3;
  while(div*div <= N){
    if(N%div==0) return false;
    div += 2;
  }
  return true;
}
