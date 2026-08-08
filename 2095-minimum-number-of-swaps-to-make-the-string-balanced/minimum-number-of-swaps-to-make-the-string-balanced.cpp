class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        int count=0;
        for(char &ch:s){
            if(ch=='['){
                count++;
            }else if(ch==']' && count>0){
                count--;
            }
           
        }
        return (count+1)/2;
    }
};