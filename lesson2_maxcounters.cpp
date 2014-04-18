// you can also use includes, for example:
#include <algorithm>

vector<int> solution(int N, vector<int> &A) {
    vector<int> B(N); // size 1XN
    int maxstore=0; // stored whenever we hit a max_counter
    int maxcache=0; // keeps track of max so far
    
    // iterate through A to find max_store
    for (int i=0; i<A.size(); i++) {
        if (A[i]!=(N+1)) {
            B[A[i]-1] = max(B[A[i]-1]+1,maxstore+1); 
            // update maxcache
            maxcache = max(B[A[i]-1],maxcache);
        } else {
            // update maxstore
            maxstore = maxcache;
        }
    }
    
    for (int i=0; i<N; i++) {
        B[i] = max(maxstore, B[i]);
    }
    
    return B;
}