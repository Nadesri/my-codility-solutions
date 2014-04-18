// you can also use includes, for example:
// #include <algorithm>
int solution(const vector<int> &A) {
    
    if (A.size()==0) {
        return -1;
    }
    
    vector<long long> rsum(A.size());
    vector<long long> lsum(A.size());
    
    rsum[0] = A[0];
    lsum[A.size()-1] = A[A.size()-1];
    // Generate left and right cum sums
    for (int i=1; i<A.size(); i++) {
        rsum[i] = rsum[i-1]+A[i];
        lsum[A.size()-1-i] = lsum[A.size()-i]+A[A.size()-1-i];
    }
    
    long long rcompare, lcompare;
    //vector<bool> eindex;
    for (int i=0; i<A.size(); i++) {
        if (i==0) {
            rcompare = 0;
        } else {
            rcompare = rsum[i-1];
        }
        if (i==(A.size()-1)) {
            lcompare = 0;
        } else {
            lcompare = lsum[i+1];
        }
        
        if (rcompare==lcompare) {
            return i;
        }
    }
    
    // Nothing matched so return -1.
    return -1;
}
