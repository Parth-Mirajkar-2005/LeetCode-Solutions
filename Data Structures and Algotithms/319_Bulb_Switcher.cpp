//319. Bulb Switcher
//
//There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.
//On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, 
//you only toggle the last bulb.
//Return the number of bulbs that are on after n rounds.
//
//Example 1:
//Input: n = 3
//Output: 1
//Explanation: At first, the three bulbs are [off, off, off].
//After the first round, the three bulbs are [on, on, on].
//After the second round, the three bulbs are [on, off, on].
//After the third round, the three bulbs are [on, off, off]. 
//So you should return 1 because there is only one bulb is on.
//
//Example 2:
//Input: n = 0
//Output: 0
//
//Example 3:
//Input: n = 1
//Output: 1

// class Solution {
// public:
//     int bulbSwitch(int n) {
//         if(n <= 1)
//             return n;
        
//         vector<int> bulbs(n,0);
        
//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = i-1; j < n; j += i)
//                 (bulbs[j] == 0) ? (bulbs[j] = 1) : (bulbs[j] = 0);
//         }

//         int count = 0;
//         for(int i = 0 ; i < n ; i++)
//         {
//             if(bulbs[i] == 1)
//                 count++;
//         }

//         return count;
//     }
// };

// ########### The above code fails due to the time limit exceeded ###############

// class Solution {
// public:
//     int bulbSwitch(int n) {
//         if(n <= 1)
//             return n;
        
//         vector<int> bulbs(n,1);         //Allready creating the lighted bulbs;
        
//         for(int i = 2; i <= n; i++)
//         {
//             for(int j = i-1; j < n; j += i)
//                 (bulbs[j] == 0) ? (bulbs[j] = 1) : (bulbs[j] = 0);
//         }

//         int count = 0;
//         for(int i = 0 ; i < n ; i++)
//         {
//             if(bulbs[i] == 1)
//                 count++;
//         }

//         return count;
//     }
// };

// ########### The above code fails due to the time limit exceeded ###############

// class Solution {
// public:
//     int bulbSwitch(int n) {
//         if(n <= 1)
//             return n;
        
//         vector<int> bulbs(n,1);         //Allready creating the lighted bulbs;
        
//         for(int i = 2; i <= n/2; i++)
//         {
//             for(int j = i-1; j <= n; j += i)
//                 (bulbs[j] == 0) ? (bulbs[j] = 1) : (bulbs[j] = 0);
//         }

//         int count = 0;
//         for(int i = 0 ; i < n ; i++)
//         {
//             if(bulbs[i] == 1)
//                 count++;
//             if(i >= n/2) 
//             {
//                 (bulbs[i] == 1) ? count-- : count++;
//             }
//         }

//         return count;
//     }
// };

// ################# The above code is thrwing an unexpected error #####################

class Solution {
public:
    int bulbSwitch(int n) {
        int count = 0;
        int i = 1;

        while(i*i <= n)
        {
            count++;
            i++;
        }

        return count;
    }
};
