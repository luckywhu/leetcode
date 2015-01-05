#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.size() == 0)
            return 0;
        vector<int> gc;        
        for(int i=0;i<gas.size();i++)
            gc.push_back(gas[i]-cost[i]);
        for(int j=0;j<gc.size();)
        {
            if(gc[j]<0)
            {
                j++;
                continue; 
            }
            int tsum=0;
            int k=j;
            for(;k<j+gc.size();k++)
            {
                tsum+=gc[k%gc.size()];
                if(tsum<0)
                    break;
            }
            if(k==(j+gc.size()))
                return j;
            if(k<gc.size())
                j=k+1;
            else
                j++;
        }
        return -1;
    }
};

int main(void)
{
    Solution sol;
    vector<int> gas;
    gas.push_back(4);
    vector<int> cost;
    cost.push_back(5);
    cout<<sol.canCompleteCircuit(gas,cost)<<endl;
}
