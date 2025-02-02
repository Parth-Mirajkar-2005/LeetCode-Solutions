// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         if (nums.size() < 2) return 0;

//         int max_product = INT_MIN;

//         for(int i = 0 ; i < nums.size() - 1; i++)
//         {
//             for(int j = i+1 ; j < nums.size() ; j++)
//             {
//                 if((nums[i]-1)*(nums[j]-1) > max_product)
//                     max_product = (nums[i]-1)*(nums[j]-1);
//             }
//         }

//         return max_product;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int max, second_max;

        (nums[0] > nums[1]) ? (max = nums[0], second_max = nums[1]) : (max = nums[1], second_max = nums[0]);
        
        for(int i = 2 ; i < nums.size() ; i++)
        {
            (nums[i] > max) ? 
                (second_max = max, max = nums[i]) :
                (nums[i] > second_max ? second_max = nums[i] : 0);
        }

        return (max-1) * (second_max-1);
    }
};
