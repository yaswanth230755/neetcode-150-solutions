class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // int n=temperatures.size();
        // vector<int> ans(n,0);
        // stack<int> st;
        // st.push(n-1);
        // for(int i=n-2;i>=0;i--){
        //     while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
        //         st.pop();
        //     }
        //     if(!st.empty()){
        //         ans[i]=st.top()-i;
        //     }
        //     st.push(i);
        // }
        // return ans;


        int n=temperatures.size(),index;
        vector<int> ans(n,0);
        for(int i=n-2;i>=0;i--){
            index=i+1;
            while(ans[index]!=0 && temperatures[index]<=temperatures[i]){
                index+=ans[index];
            }
            if(temperatures[index]>temperatures[i]){
                ans[i]=index-i;
            }
        }
        return ans;
    }
};