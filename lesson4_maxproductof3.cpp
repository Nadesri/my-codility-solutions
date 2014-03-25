// you can also use includes, for example:
// #include <algorithm>

int solution(vector<int> &A) {
    int max1 = -1000; int min1 = 1000;
    int max2 = max1;  int min2 = min1;
    int max3 = max2;  int min3 = min2;
    // Treat ints like a "sorted queue" of size 3. If all maxes are filled, 
    // update and then pop max3. Same story with mins.
    
    // update step: if current>max1, push it and continue. 
    //              if current>max2, push it and continue.
    //              if current>max3, push it and continue.
    //              else, continue.
    int current;
    for (int i=0; i<A.size(); i++) {
        current = A[i];
        // push to max1 if high enough.
        if (current>=max1) {
            // push everything.
            max3 = max2;
            max2 = max1;
            max1 = current;
        }
        else if (current>=max2) {
            // push max2 and max3
            max3 = max2;
            max2 = current;
        }
        else if (current>=max3) {
            // push max3
            max3 = current;
        }
        
        // push to min1 if high enough.
        if (current<=min1) {
            // push everything.
            min3 = min2;
            min2 = min1;
            min1 = current;
        }
        else if (current<=min2) {
            // push min2 and min3
            min3 = min2;
            min2 = current;
        }
        else if (current<=min3) {
            // push min3
            min3 = current;
        }
//        cout << "Iteration " << i+1 << ": " << endl;
//        cout << max1 << ", " << max2 << ", " << max3 << endl;
    }
    
    return ((max1*max2*max3)>(min1*min2*max1))? (max1*max2*max3):(min1*min2*max1);
}