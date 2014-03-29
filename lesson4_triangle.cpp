// you can also use includes, for example:
#include <algorithm>
using namespace std;

bool isTriangular(long long a, long long b, long long c);

int solution(const vector<int> &A) {
    
    if (A.size()<3) {
        return 0;
    }
    
    vector<int> B = A;
    
    sort(B.begin(),B.end());
    long long a,b,c;
    for (int i=0; i<B.size()-2; i++) {
        a = B[i]; b = B[i+1]; c = B[i+2];
        if (isTriangular(a,b,c)) {
            return 1;
        }
    }
    return 0;
}


bool isTriangular(long long a, long long b, long long c) {
    return ((a+b>c)&&(a+c>b)&&(b+c>a))? true : false;
}