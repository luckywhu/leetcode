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
        int sum=-1;
        int min=prices[0];
        for(int i=0;i<prices.size();i++)
        {
              int new_sum=prices[i]-min;
              if(new_sum > sum)
              {
                    sum=new_sum;
                    continue;
              } 
              if(prices[i]<min)
                    min=prices[i];
        }
        return sum;
    }
};

int main(void)
{
    
}
