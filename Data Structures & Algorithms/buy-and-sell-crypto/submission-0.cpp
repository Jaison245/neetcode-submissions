class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int min_price = prices[0];

        for(int price : prices){
            if(min_price > price){
                min_price = price;
            }else{
                profit = max(profit, price - min_price);
            }
        }
        return profit;
             
    }
};
