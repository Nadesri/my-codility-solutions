int largesum(int K, int rsum, vector<int> &A);

int solution(int K, int M, vector<int> &A) {
  int result = 0;
    
  int A_max = 0;
  int A_sum = 0;
  for (int i=0; i<A.size(); i++) {
    A_sum += A[i];
    if (A_max<A[i]) {
      A_max = A[i];
    }
  }
  int a1 = A_max;
  int a2 = A_sum;
        
  result = a1;
  while (a2-a1>=0) {
    int mid = (a1+a2)/2;
    int lsum = largesum(K,mid,A);
    if (lsum==mid) {
      result = mid;
      a2 = mid-1;
    } else {
      a1 = mid+1; 
    }
  }
    
  return result;
}

// Compute the true large sum, given the "requested large sum"
int largesum(int K, int rsum, vector<int> &A) {
  int sumsofar = 0;
  int nblocks = 1;
    
  for (int i=0; i<A.size(); i++) {
        
    if (sumsofar+A[i] < rsum) {
      sumsofar+=A[i];
    } else if (sumsofar+A[i] == rsum) {
      sumsofar=0;
      nblocks++;
    } else {
      sumsofar = A[i];
      nblocks++;
    }
        
    if (nblocks==K) {
      i++;
      while (i<A.size()) {
	sumsofar+=A[i++];
      }
      break;
    }
  }
    
  return (sumsofar>rsum)? sumsofar : rsum;
}
