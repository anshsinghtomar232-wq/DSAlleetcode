class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        

        for( int i=0; i<nums.size();i++){
          while(!st.empty()){
           int prev=st.top();
           int curr=nums[i];

           int GCD=gcd(prev,curr);
           if(GCD==1){
            break;
           }else{
             st.pop();
             int lcm=prev/GCD*curr;
             nums[i]=lcm;

           }
          }
            st.push(nums[i]);
        }
        vector<int> result(st.size());
           int i=st.size()-1;
        while(!st.empty()){
            result[i]=st.top();
            st.pop();
            i--;

        }
        return result;
    }
};