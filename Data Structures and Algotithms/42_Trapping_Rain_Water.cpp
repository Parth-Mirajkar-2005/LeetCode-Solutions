//42. Trapping Rain Water
//Given n non-negative integers representing an elevation map where the width of each bar is 1, 
//compute how much water it can trap after raining.
//
//Example 1:
//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
//Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
//In this case, 6 units of rain water (blue section) are being trapped.
//
//Example 2:
//Input: height = [4,2,0,3,2,5]
//Output: 9

class Solution {
public:
    int trap(vector<int>& height) {
        int traped_water = 0;
        int n = height.size();
        int* left_max_height = new int[n];
        int* right_max_height = new int[n];

        left_max_height[0] = height[0];
        right_max_height[n-1] = height[n-1];

        for(int i = 1; i < n; i++)
            left_max_height[i] = max(left_max_height[i-1], height[i]);
        
        for(int j = n-2; j >= 0; j--)
            right_max_height[j] = max(height[j], right_max_height[j+1]);

        for(int k = 1; k < n-1; k++)
            traped_water += min(left_max_height[k], right_max_height[k]) - height[k];

        delete[] left_max_height;
        delete[] right_max_height;

        return traped_water;
    }
};
