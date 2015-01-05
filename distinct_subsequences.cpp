#include <iostream>
#include <vector>
#include <string>


using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
        public:
                int numDistinct(string S, string T) {
                        int s_len = S.length();          
                        int t_len = T.length();
                        vector<vector<int> > c;
                        for(int i=0;i<=s_len;i++){
                                vector<int> row;
                                for(int j=0;j<=t_len;j++){
                                        row.push_back(-1);
                                }
                                c.push_back(row);
                        }
                        for(int j=0;j<=t_len;j++)
                            c[0][j]=0;
                        for(int i=0;i<=s_len;i++)
                            c[i][0]=1;
                        for(int i=0;i<=s_len;i++){
                                for(int j=0;j<=t_len;j++){
                                    if(i==0 || j==0)
                                        continue;
                                    if(S[i-1] == T[j-1])
                                    {
                                        c[i][j]=c[i-1][j-1]+c[i-1][j];
                                    }else
                                        c[i][j]=c[i-1][j];
                                }
                        }
                        return c[s_len][t_len]; 
                        //return rescursionNumDistinct(S,0,T,0,c);
                }
                int rescursionNumDistinct(string &s,int s_len,string &t,int t_len,vector<vector<int> > &c)
                {
                        if(c[s_len][t_len] >=0)
                                return c[s_len][t_len];
                        if(t_len == t.length())
                            return 1;
                        if(s_len == s.length())
                            return 0;
                        if(s[s_len]==t[t_len])
                        {
                                int case1=rescursionNumDistinct(s,s_len+1,t,t_len+1,c);
                                c[s_len+1][t_len+1]=case1;
                                int case2=rescursionNumDistinct(s,s_len+1,t,t_len,c);
                                c[s_len+1][t_len]=case2;
                                return case1+case2;
                        }else{
                                int case2=rescursionNumDistinct(s,s_len+1,t,t_len,c);
                                c[s_len+1][t_len]=case2;
                                return case2;
                        }
                }
                
};


int main(void){
        Solution sol;
        cout<<sol.numDistinct("","")<<endl;

}
