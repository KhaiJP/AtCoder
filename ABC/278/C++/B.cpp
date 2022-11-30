#include<iostream>
using namespace std;

bool isConfusing(int H, int M){
    int A = H/10;
    int B = H%10;
    int C = M/10;
    int D = M%10;
    return 0<= 10*A+C && 10*A+C <=23 && 0<= 10*B+D && 10*B+D <=59;
}

int nextTime(int* H, int* M){
    *M = *M +1;
    if(*M==60){
        *M = 0;
        *H = (*H==23) ? 0 : *H+1;
    }
    return 0;
}

int main(){
    int H, M;
    cin >> H >> M;
    while(true){
        if(!isConfusing(H, M)){
            nextTime(&H, &M);
        }else{
            cout << H << " " << M;
            return 0;
        }
    }
}

// another way to realise nextTime
// tuple<int, int> nextTime(int H, int M){
//     M++;
//     if(M==0){
//         M = 0;
//         H = (H==23) ? 0 : H+1;
//     }
//     return forward_as_tuple(H, M);
// }
// tie(H, M) = nextTime(H, M);