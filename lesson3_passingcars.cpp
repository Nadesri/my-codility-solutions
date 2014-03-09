int solution(vector<int> &A) {
    
    // Validate for empty vector
    if (A.size()<=1) {
        return 0;
    }
    
    unsigned int counter  = 0;
    unsigned int passnum  = 0;
    
    for (int i=0; i<A.size(); i++) {
        
        // Validate for correct input
        if (!((A[i]==0)|(A[i]==1))) {
            continue;
        }
        
        if (A[i]==0) {
            counter++;
        } else {
            passnum += counter;
            if (passnum>1000000000) {
                passnum = -1;
                break;
            }
        }
    }
    
    return passnum;
}