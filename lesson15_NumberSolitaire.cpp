#include <algorithm>

int calcMaxScoreAtI(vector<int> &aMaxSoFar, int currSquare, int i);

int solution(vector<int> &A) {
    int n = A.size();
    vector<int> aScoreAt(n);
    for (int i=0; i < n; i++) {
        aScoreAt[i] = calcMaxScoreAtI(aScoreAt, A[i], i);
    }
    return aScoreAt[n-1];
}

int calcMaxScoreAtI(vector<int> &aMaxSoFar, int currSquare, int i) {
    int a = max(i-6, 0);
    int m = aMaxSoFar[a]+currSquare;
    for (int ind=a+1; ind<i; ind++) {
        m = max(m, currSquare + aMaxSoFar[ind]);
    }
    return m;
}
