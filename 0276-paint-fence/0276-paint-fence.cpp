class Solution {
public:
    int numWays(int n, int k) {
        if(n<=1 || k==0)return n*k;
        int a=k,b=k*(k-1),c=0,d=0;
        for(int i=2;i<n;++i){
            d=(k-1)*(a+b);
            a=b;b=d;
        }
        return a+b;
    }
};