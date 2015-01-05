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
        int pre_sum=0;
        int pre_min = prices[0];
        vector<int> pre_max_sum;
        pre_max_sum.push_back(0);
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-pre_min>pre_sum)
                pre_sum=prices[i]-pre_min;
            if(prices[i]<pre_min)
                pre_min=prices[i];
            pre_max_sum.push_back(pre_sum);
        }
        int post_sum=0;
        int post_max=prices[prices.size()-1];
        vector<int> post_max_sum;
        post_max_sum.push_back(0);
        for(int i=prices.size()-2;i>=0;i--)
        {
            if(post_max-prices[i]>post_sum)
                post_sum=post_max-prices[i];
            if(prices[i]>post_max)
                post_max=prices[i];
            post_max_sum.push_back(post_sum);
        }
        vector<int>::iterator ite=pre_max_sum.begin();
        while(ite!=pre_max_sum.end())
        {
            cout<<*ite;
            ite++;
        }
        cout<<endl;
        vector<int>::iterator post_ite=post_max_sum.begin();
        while(post_ite!=post_max_sum.end())
        {
            cout<<*post_ite;
            post_ite++;
        }
        cout<<endl;
        int sum=0;
        for(int i=0;i<prices.size();i++)
        {
            int tmp=0;
            tmp+=pre_max_sum[i];
            tmp+=((i==prices.size()-1)?0:post_max_sum[prices.size()-2-i]);
            if(tmp>sum)
                sum=tmp;
        }
        return sum;
    }
};

int main(void)
{
    Solution sol;
    vector<int> t;
    t.push_back(1);
    t.push_back(2);
    cout<<sol.maxProfit(t)<<endl;
}
