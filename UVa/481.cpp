#include <bits/stdc++.h>
using namespace std;

// Binary search (note boundaries in the caller)
// A[] is ceilIndex in the caller
int GetCeilIndex(vector<int> A, int T[], int l, int r, int key) {
   int m;
 
   while( r - l > 1 ) {
      m = l + (r - l)/2;
      if( A[T[m]] >= key )
         r = m;
      else
         l = m;
   }
 
   return r;
}
 
int LongestIncreasingSubsequence(vector<int> A, int size) {
   // Add boundary case, when array size is zero
   // Depend on smart pointers
 
   int *tailIndices = new int[size];
   int *prevIndices = new int[size];
   int len;
 
   memset(tailIndices, 0, sizeof(tailIndices[0])*size);
   memset(prevIndices, 0xFF, sizeof(prevIndices[0])*size);
 
   tailIndices[0] = 0;
   prevIndices[0] = -1;
   len = 1; // it will always point to empty location
   for( int i = 1; i < size; i++ ) {
      if( A[i] < A[tailIndices[0]] ) {
         // new smallest value
         tailIndices[0] = i;
      } else if( A[i] > A[tailIndices[len-1]] ) {
         // A[i] wants to extend largest subsequence
         prevIndices[i] = tailIndices[len-1];
         tailIndices[len++] = i;
      } else {
         // A[i] wants to be a potential condidate of future subsequence
         // It will replace ceil value in tailIndices
        int pos = GetCeilIndex(A, tailIndices, -1, len-1, A[i]);
 
        prevIndices[i] = tailIndices[pos-1];
        tailIndices[pos] = i;
      }
   }
   cout << "LIS of given input" << endl;
   for( int i = tailIndices[len-1]; i >= 0; i = prevIndices[i] )
      cout << A[i] << "   ";
   cout << endl;
 
   delete[] tailIndices;
   delete[] prevIndices;
 
   return len;
}

int main() {
	int n;
	vector<int> V;

	while(cin >> n)
		V.push_back(n);
	
	LongestIncreasingSubsequence(V, V.size());

	return 0;
}