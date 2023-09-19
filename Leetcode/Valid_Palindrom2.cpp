LeetCode: 680

class Solution {
public:
    bool isvalid(string s,int i,int e){
        while(i<=e){
            if(s[i]==s[e]){
            i++;
            e--;
        }
        else{
            return false;
        }
            
        }
        return true;
    }
        
     
    bool validPalindrome(string s) {
        int i=0;
        int e=s.length()-1;
        while(i<=e){
            if(s[i]!=s[e]){
                return isvalid(s,i,e-1) || isvalid(s,i+1,e);
            }
            else{
                i++;
                e--;
            }
        }
        return true;
    }
};