#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int int_bits = sizeof(int)*8;         
        vector<int> bit_vector;
        for(int i=0;i<int_bits;i++)
            bit_vector.push_back(0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<int_bits;j++)
            {
                if((A[i]>>j) & 0x1)
                    bit_vector[j]++;
                    
            }
        }
        int num=0;
        for(int i=0;i<int_bits;i++)
        {
            if(bit_vector[i]%3 == 1)
                num = (num |(0x01 <<i));
        }
        return num;
    }
};

int main(void){
    Solution sol;
    int A[]={1,1,1,4};
    cout<<sol.singleNumber(A,4)<<endl;
    return 0;
}
