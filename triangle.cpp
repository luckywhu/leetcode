#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution1 {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int tri_rows=triangle.size();
        int g_min=0;
        vector<vector<int> > ms;
        for(int i=0;i<tri_rows;i++)
        {
            vector<int> row_vector;
            for(int j=0;j<=i;j++)
            {
                row_vector.push_back(INT_MAX);
            }
            ms.push_back(row_vector);
        }
        return rescu(0,0,triangle,ms);
    }
    int rescu(int row,int col,vector<vector<int> > &triangle,vector<vector<int> > &ms){
        int tri_rows=triangle.size();
        if(row==tri_rows-1)
        {
            ms[row][col]=triangle[row][col];
            return ms[row][col];
        }
        if(ms[row][col] < INT_MAX)
            return ms[row][col];
        int a=INT_MAX,b=INT_MAX;
        a=triangle[row][col]+rescu(row+1,col,triangle,ms);
        b=triangle[row][col]+rescu(row+1,col+1,triangle,ms);
        ms[row][col]=a<b?a:b;
        return ms[row][col];
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int tri_rows=triangle.size();
        int g_min=0;
        vector<int> ms;
        for(int i=0;i<tri_rows;i++)
            ms.push_back(INT_MAX);
//        vector<vector<int> > ms;
//        for(int i=0;i<tri_rows;i++)
//        {
//            vector<int> row_vector;
//            for(int j=0;j<=i;j++)
//            {
//                row_vector.push_back(INT_MAX);
//            }
//            ms.push_back(row_vector);
//        }
        for(int i=tri_rows-1;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(i==tri_rows-1)
                {
                    ms[j]=triangle[i][j];
                    continue;
                }
                int a,b;
                a = triangle[i][j]+ms[j];
                b = triangle[i][j]+ms[j+1];
                ms[j] = a<b?a:b;
            }
        }
        return ms[0];
    }
};

int main(void){
    Solution1 sol;
    vector<vector<int> > tri;
    vector<int> a;
    a.push_back(-10);
    tri.push_back(a);
    cout<<sol.minimumTotal(tri)<<endl;
}
