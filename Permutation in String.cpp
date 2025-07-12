class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // can use unordered_map
        int n1=s1.length(),n2=s2.length();
        if(n1>n2){
            return false;
        }
        vector<int> arr(26,0);
        for(const auto& ch : s1){
            arr[ch-'a']++;
        }
        int j,k=0;
        for(int i=0;i<n1-1;i++){
            arr[s2[i]-'a']--;
        }
        for(int i=n1-1;i<n2;i++){
            arr[s2[i]-'a']--;
            for(j=0;j<26;j++){
                if(arr[j]){
                    break;
                }
            }
            if(j==26){
                return true;
            }
            arr[s2[k]-'a']++;
            k++;
        }
        return false;



        // int n1 = s1.length(), n2 = s2.length();
        // if (n1 > n2) return false;
        // vector<int> count(26, 0);
        // for (char c : s1) count[c - 'a']++;
        // int left = 0;
        // for (int right = 0; right < n2; right++) {
        //     count[s2[right] - 'a']--;
        //     if (right - left + 1 > n1) {
        //         count[s2[left] - 'a']++;
        //         left++;
        //     }
        //     if (right - left + 1 == n1 && all_of(count.begin(), count.end(), [](int v) { return v == 0; }))
        //         return true;
        // }

        // return false;
    }
};