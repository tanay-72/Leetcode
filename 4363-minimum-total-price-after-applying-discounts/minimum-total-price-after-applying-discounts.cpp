class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        priority_queue<int> pq ;
        for(int i = 0 ; i < discounts.size() ; i++) pq.push(discounts[i]);
        sort(prices.begin() , prices.end());
        double ans = 0 ;
        for(int i = prices.size()-1 ; i >= 0 ; i--){
            if(pq.empty()){
                ans += prices[i]; 
                continue;
            }
            int d = pq.top();
            pq.pop();
            ans += (prices[i] * (100-d)/100.0);
        }
        return ans;
    }
};