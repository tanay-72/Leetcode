class Solution {
public:
    double pow(double x , long long n){
        double ans = 1 ;
        while(n > 0){
            if(n & 1) ans *= x ;
            x*=x ;
            n >>= 1 ;
        }
        return ans ;
    }
    double myPow(double x, int n) {
        if(x == 0) return 0 ; 
        long long N = n;
if (N < 0) {
    x = 1 / x;
    N = -N;
}
        if(n < 0) return pow(x , N);
        return pow(x , n);
    }
};