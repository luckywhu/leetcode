#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution1 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int> > flag_array;
        for(int i=0;i<=s1.length();i++)
        {
            vector<int> row;
            for(int j=0;j<=s2.length();j++)
            {
                row.push_back(-2);
            }
            flag_array.push_back(row);
        }
        return RescursionIsInterleave(s1,s2,s3,flag_array);
    }
    bool RescursionIsInterleave(string s1, string s2, string s3,vector<vector<int> > &flag_array) {
        int s1_len = s1.length();
        int s2_len = s2.length();
        int s3_len = s3.length();
        if(flag_array[s1_len][s2_len] == s3_len)
            return true;
        else if(flag_array[s1_len][s2_len] == -1)
            return false;

        if(s1.length()==0)
        {
            if(s2.compare(s3)==0)
                return true;
            else
                return false;
        }
        if(s2.length()==0)
        {
            if(s1.compare(s3)==0)
                return true;
            else
                return false;
        }
        if(s3.length()==0)
        {
            if(s1.length()==0 && s2.length()==0)
                return true;
            else
                return false;
        }
        int flag = RescursionIsInterleave(s1.substr(1,string::npos),s2,s3.substr(1,string::npos),flag_array);
        if(flag)
            flag_array[s1_len-1>0?(s1_len-1):0][s2_len]=s3_len-1>0?(s3_len-1):0;
        else
            flag_array[s1_len-1>0?(s1_len-1):0][s2_len]=-1;
        
        if(s3[0] == s1[0] and flag)
        {
            return true;
        }

        flag = RescursionIsInterleave(s1,s2.substr(1,string::npos),s3.substr(1,string::npos),flag_array);
        if(flag)
            flag_array[s1_len][s2_len-1>0?(s2_len-1):0]=s3_len-1>0?(s3_len-1):0;
        else
            flag_array[s1_len][s2_len-1>0?(s2_len-1):0]=-1;

        if(s3[0] == s2[0] and flag)
        {
            return true;
        }
        return false;
        
    }
};
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()==0)
        {
            if(s2.compare(s3)==0)
                return true;
            else
                return false;
        }
        if(s2.length()==0)
        {
            if(s1.compare(s3)==0)
                return true;
            else
                return false;
        }
        if(s3.length()==0)
        {
            if(s1.length()==0 && s2.length()==0)
                return true;
            else
                return false;
        }
        if(s3[0] == s1[0] and isInterleave(s1.substr(1,string::npos),s2,s3.substr(1,string::npos)))
            return true;
        else if(s3[0] == s2[0] and isInterleave(s1,s2.substr(1,string::npos),s3.substr(1,string::npos)))
            return true;
        else
            return false;
    }
    
};

int main(void){
    string  s1("aabcc");
    string  s2("dbbca");
    string  s3("aadbbcbcac");
    string  s4("aadbbbaccc");
    Solution1 sol;
    cout<<sol.isInterleave(s1,s2,s3)<<endl;
    cout<<sol.isInterleave(s1,s2,s4)<<endl;
}
    
