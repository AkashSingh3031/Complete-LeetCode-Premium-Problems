/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        if(n<=1) return n;
        int candidate = 0;
        for(int i=1; i<n; i++){

            if ( !knows(i,candidate) ){
                candidate = i;
            }
        }
        for(int j=0; j<n; j++){
            if(j== candidate) continue;
            if( !knows(j,candidate) || knows(candidate,j) ){
                  //if j does not know candidate, or candidate knows j, return -1;
                return -1;
            }
        }
        return candidate;

    }
};