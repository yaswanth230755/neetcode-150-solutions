class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // can solve using bucket sort int arr[1001]; in O(n+1000*groupSize)
        // can also use unordered_map
        
        
        
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) freq[card]++;

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int start = it->first;
            int count = it->second;
            if (count > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    int card = start + i;
                    if (freq[card] < count) return false;
                    freq[card] -= count;
                }
            }
        }
        return true;




        // if (hand.size() % groupSize != 0) return false;
        // unordered_map<int, int> count;
        // for (int num : hand) count[num]++;
        // for (int num : hand) {
        //     int start = num;
        //     while (count[start - 1] > 0) start--;
        //     while (start <= num) {
        //         while (count[start] > 0) {
        //             for (int i = start; i < start + groupSize; i++) {
        //                 if (count[i] == 0) return false;
        //                 count[i]--;
        //             }
        //         }
        //         start++;
        //     }
        // }
        // return true;
    }
};
