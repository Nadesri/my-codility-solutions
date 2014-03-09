#include <iostream>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    vector< vector<int> > mysum(4, vector<int>(S.size()+1));
    
    // Allocate a "prefix sum", where each unique nucleotide has its own bin.
    for (int i=0; i<S.size(); i++) {
        if (S[i]=='A') {
            mysum[0][i+1]++;
        } else if (S[i]=='C') {
            mysum[1][i+1]++;
        } else if (S[i]=='G') {
            mysum[2][i+1]++;
        } else if (S[i]=='T') {
            mysum[3][i+1]++;
        }
        
        // Sum up previous elements in mysum (prefix-sum)
        for (int j=0; j<4; j++) {
            mysum[j][i+1] += mysum[j][i];
        }
    }
    
    vector<int> result(P.size());
    vector<int> tempsum(4);
    
    // Run through the list of queries
    for (int i=0; i<P.size(); i++) {
        
        //For a given query, find the number of occurrences for each nucleotide.
        for (int j=0; j<4; j++) {
            tempsum[j] = mysum[j][Q[i]+1]-mysum[j][P[i]];
            
            // Since we ordered the bin in sequential order, stop if we find an
            // existing nucleotide (as it is the smallest detected nucleotide)
            if (tempsum[j]>0) {
                result[i] = j+1;
                
                // Reset tempsum
                tempsum.assign(4, 0);
                
                // get out of inner loop
                break;
            }
        }
        
    }
    
    return result;
}