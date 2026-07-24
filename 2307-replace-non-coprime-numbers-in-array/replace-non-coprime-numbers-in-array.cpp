class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
     vector<int> result;
     for( int &num:nums){
         while(!result.empty()){
             int prev =result.back();
             int curr= num;

             int GCD=gcd(curr,prev);
             if(GCD==1){
                break;
             }else{
                result.pop_back();
                int lcm=prev/GCD*curr;
                num=lcm;
             }
            
              
         }
         result.push_back(num);

     }   
     return result;
    }
};