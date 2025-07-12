class Solution {
public:
    vector<int> partitionLabels(string s) {
        int arr[26] = {0}, n = s.length();
        vector<int> ans;

        // Step 1: Store the last index of each character
        for (int i = 0; i < n; i++) {
            arr[s[i] - 'a'] = i;
        }

        // Step 2: Greedily partition using the farthest last index
        int curr = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            curr = max(curr, arr[s[i] - 'a']);
            if (curr == i) {
                ans.push_back(i + 1 - sum); // Partition size
                sum = i + 1; // Update the start of next partition
            }
        }

        return ans;
    }
};
