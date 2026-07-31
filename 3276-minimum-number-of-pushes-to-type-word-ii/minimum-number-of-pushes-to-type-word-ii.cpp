class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i = 0 ; i < word.size() ; i++){
            freq[word[i] - 'a']++ ;
        }
        sort(freq.begin() , freq.end());
        int ans =0 ;
        for(int i = 25; i >= 18 ;i--){
            ans += freq[i];
        }
        for(int i = 17 ; i >= 10 ; i-- ){
            ans += 2 * freq[i];
        }
        for(int i = 9 ; i >= 2 ; i--){
            ans+= 3* freq[i];
        }
        for(int i = 1 ; i>= 0 ;i--){
            ans += 4 * freq[i];
        }
        return ans ;
    }   
};