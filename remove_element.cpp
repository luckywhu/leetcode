#include <iostream>

class Solution{
public:
    int removeElement(int A[],int n,int elem){
        int count=0;
        int i=0,j=n-1;  
        if(n==0)
            return 0;
        while(i<j)
        {
            while(j>i)
                if(A[j]==elem)
                    j--;
                else
                    break;
            while(i<j)
                if(A[i] != elem)
                    i++;
                else
                    break;
            if(i<j)
            {
                A[i]=A[j];
                A[j]=elem;
            }
        }
        if(A[i]==elem)
            return j;
        else
            return j+1;
    }
};
int main(void){
    Solution sol;
    int A[]={1,2,3,3,2,1,4,3};
    std::cout<<sol.removeElement(A,8,2)<<std::endl;
}
