class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // stack<double> st;
        // int n=position.size();
        // double time;
        // vector<pair<int,int>> vp(n);
        // for(int i=0;i<n;i++){
        //     vp[i]={position[i],speed[i]};
        // }
        // sort(vp.begin(),vp.end());
        // for(int i=0;i<n;i++){
        //     time=(double)(target-vp[i].first)/vp[i].second;// can also use static typecasting
        //     while(!st.empty() && st.top()<=time){
        //         st.pop();
        //     }
        //     st.push(time);
        // }
        // return st.size();
        int n = position.size();
        vector<pair<int, int>> pair;
        for (int i = 0; i < n; i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        
        int fleets = 1;
        double prevTime = (double)(target - pair[0].first) / pair[0].second;
        for (int i = 1; i < n; i++) {
            double currTime = (double)(target - pair[i].first) / pair[i].second;
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};