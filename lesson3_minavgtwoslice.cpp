int solution(vector<int> &A) {
    vector<double> B(A.size()-1); // 2 slice avg
    vector<double> C(A.size()-2);
    
    double min = 100000;
    
    for (int i=0; i<(A.size()-1); i++) {
        B[i] = ((double)A[i]+(double)A[i+1])/2; // 2 slice avg
        if (i<(A.size()-2)) {
            C[i] = ((double)A[i]+(double)A[i+1]+(double)A[i+2])/3; // 3 slice avg
        }
    }
    
    int min_ind = 0;
    int slicesize = 0;
    for (int i=0; i<B.size(); i++) {
        if (min>B[i]) {
            min     = B[i];
            min_ind = i;
            slicesize = 2;
        }
        
        if (i<C.size()) {
            if (min>C[i]) {
                min    = C[i];
                min_ind = i;
                slicesize = 3;
            }
        }
    }
    return min_ind;
}