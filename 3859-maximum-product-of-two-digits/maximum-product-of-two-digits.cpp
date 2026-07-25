class Solution {
public:
    int maxProduct(int n) {
        int m1 = INT_MIN ;
        int m2 = INT_MIN ;
        int cnt = 0 ;
        while(n){
            int d = n % 10 ;
            if(m1 == d){
                cnt++;
            }
            else{
                if(d > m1){
                    m2 = m1 ;
                    m1 = d ;
                    cnt = 1 ;
                }
                else if(d > m2){
                    m2 = d;
                }
            }
            n /= 10;
        }
        if(cnt > 1) return m1 * m1 ; 
        return m1 * m2 ;
    }
};