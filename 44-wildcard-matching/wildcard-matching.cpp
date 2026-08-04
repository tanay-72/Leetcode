class Solution {
public:
    int dp[2001][2001];
    bool solve(string&a , string&b , int ptr1 , int ptr2){
        // base case
        if(ptr1 == a.size()){
            while(ptr2 != b.size()){
                if(b[ptr2] == '*') ptr2++;
                else break;
            }
            return ptr2 == b.size();
        }
        if(ptr2 == b.size()){
            while(ptr1 != a.size()){
                if(a[ptr1] =='*') ptr1++;
                else break;
            }
            return ptr1 == a.size();
        }
        if(dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];
        if(a[ptr1] != '?' && a[ptr1] != '*'  && b[ptr2] != '?' && b[ptr2] != '*'){
            if(a[ptr1] != b[ptr2]) return dp[ptr1][ptr2] = false;
            return dp[ptr1][ptr2] = solve(a , b ,ptr1 + 1 , ptr2 + 1);
        }
        
        if (a[ptr1] == '?' && b[ptr2] != '*')
            return dp[ptr1][ptr2] = solve(a,b,ptr1+1,ptr2+1);

        if (b[ptr2] == '?' && a[ptr1] != '*')
            return dp[ptr1][ptr2] = solve(a,b,ptr1+1,ptr2+1);
        if(a[ptr1] == '*') {
            return dp[ptr1][ptr2] = solve(a , b , ptr1 , ptr2+1) || solve(a , b , ptr1 + 1 , ptr2 + 1) || solve(a , b , ptr1 + 1 , ptr2); 
        }
        if(b[ptr2] == '*') {
            return dp[ptr1][ptr2] =solve(a , b , ptr1+1 , ptr2) || solve(a , b , ptr1 + 1 , ptr2 + 1) || solve(a , b , ptr1 , ptr2 + 1);
        }
        return dp[ptr1][ptr2] = false;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(s , p , 0 , 0);
    }
};