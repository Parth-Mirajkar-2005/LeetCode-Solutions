//215. Kth Largest Element in an Array
//
//Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//Can you solve it without sorting?
//
//Example 1:
//Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
//
//Example 2:
//Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4

// ------------------------------- Solution 1: Using Max heap -------------------------------------

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> buffer;

        for(int i = 0; i < nums.size(); i++)
        {
            if(buffer.size() < k)
                buffer.push(nums[i]);
            else if(buffer.top() < nums[i])
            {
                buffer.pop();
                buffer.push(nums[i]);
            }
        }

        return buffer.top();
    }
};

// ----------------------------------- Solution 2: Using Min heap ---------------------------------

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Build a max-heap from the entire array.
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        // Remove the largest element k-1 times.
        for (int i = 0; i < k - 1; i++) {
            maxHeap.pop();
        }
        
        // The top of the heap is now the kth largest element.
        return maxHeap.top();
    }
};
