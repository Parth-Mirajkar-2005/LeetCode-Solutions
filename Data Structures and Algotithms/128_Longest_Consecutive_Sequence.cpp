//128. Longest Consecutive Sequence
//
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//
//You must write an algorithm that runs in O(n) time.
// 
//Example 1:
//Input: nums = [100,4,200,1,3,2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//
//Example 2:
//Input: nums = [0,3,7,2,5,8,4,6,0,1]
//Output: 9
//
//Example 3:
//Input: nums = [1,0,1,2]
//Output: 3

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());

        int max_length = 1;
        int current_length = 1;
        int buffer = minHeap.top();
        minHeap.pop();

        do
        {
            int temp = minHeap.top();
            minHeap.pop();
            
            if(temp == buffer)    continue;
            else if(abs(buffer - temp) == 1)    current_length++;
            else
            {
                max_length = max(max_length, current_length);
                current_length = 1;
            }

            buffer = temp;
        }while(!minHeap.empty());

        return max(max_length, current_length);
    }
};
