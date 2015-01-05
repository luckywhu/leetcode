#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
        public:
                int minDistance(string word1, string word2){
                        int s1_len=word1.length();        
                        int s2_len=word2.length();
                        vector<vector<int> > c; 
                        for(int i=0;i<=s1_len;i++)
                        {
                                vector<int> row;
                                for(int j=0;j<=s2_len;j++)
                                {
                                        row.push_back(-1); 
                                }
                                c.push_back(row);
                        }
                        return rescursionEditDistance(word1,word2,c);
                }
                int rescursionEditDistance(string s1,string s2,vector<vector<int> > &c)
                {
                        int s1_len=s1.length();        
                        int s2_len=s2.length();
                        if(c[s1_len][s2_len] >= 0 )
                            return c[s1_len][s2_len];
                        if(s1_len == 0 )
                        {
                                return s2_len;
                        }
                        if(s2_len == 0)
                        {
                                return s1_len;
                        }
                        string new_s1=s1.substr(1,string::npos);
                        string new_s2=s2.substr(1,string::npos);
                        if(s1[0]==s2[0])
                        {
                                int edit_dis= rescursionEditDistance(new_s1,new_s2,c); 
                                c[new_s1.length()][new_s2.length()]=edit_dis;
                                return edit_dis;
                        }
                        else{
                                int g_dis;
                                int delete_dis = rescursionEditDistance(new_s1,s2,c);
                                c[new_s1.length()][s2.length()]=delete_dis;
                                int insert_dis = rescursionEditDistance(s1,new_s2,c);
                                c[s1.length()][new_s2.length()]=insert_dis;
                                int replace_dis = rescursionEditDistance(new_s1,new_s2,c);
                                c[new_s1.length()][new_s2.length()]=replace_dis;

                                g_dis = (delete_dis < insert_dis) ? delete_dis:insert_dis;
                                g_dis = (g_dis < replace_dis)?g_dis:replace_dis;
                                g_dis += 1;//add step
                                return g_dis;
                        }

                }
};

int main(void){
    Solution sol;
    cout<<sol.minDistance("sea","ate")<<endl;
}
