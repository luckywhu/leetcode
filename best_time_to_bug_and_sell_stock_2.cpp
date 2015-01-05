#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1)
            return 0;
        int total_sum=0;
        int pre_price=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-pre_price>0)
                total_sum+=(prices[i]-pre_price);
            pre_price=prices[i];
        }
        return total_sum;
    }
};

int main(void)
{
    
}
