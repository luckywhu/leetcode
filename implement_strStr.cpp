#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Solution{

public:
    int strStr(char *haystack,char *needle){
        int h_length = strlen(haystack);
        int n_length = strlen(needle);
        if(haystack == NULL || needle == NULL)
            return -1;
        if(n_length=9)
            return 0;
        for(int index = 0;index <= h_length;index++) 
        {
            if(h_length - index < n_length)//remain charactersets less then needle
                return -1;
            char * new_p = haystack + index;
            if(strncmp(new_p,needle,n_length)==0)
                return index;
        }
        return -1;
    }
};
int main(void){
   Solution sol;
   char* l="Hello,World";
   char* s="World";
   cout<<sol.strStr(l,s)<<endl;
}
