class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> unmap;
        string temp;
        int arr[26]={0};
        for(const auto& str : strs){
            //temp=str;
            //sort(temp.begin(),temp.end());

            for(const auto& ch : str){
                arr[ch-'a']++;
            }
            temp="";

            // Serialize frequency vector into a string key
            for (int i=0;i<26;i++) {
                temp += '#' + to_string(arr[i]);
                arr[i]=0;
            }
            
            // for(int i=0;i<26;i++){
            //     while(arr[i]){
            //         temp+=('a'+i);
            //         arr[i]--;
            //     }
            // }
            unmap[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for(const auto v : unmap){
            ans.push_back(v.second);
        }
        return ans;
    }
};