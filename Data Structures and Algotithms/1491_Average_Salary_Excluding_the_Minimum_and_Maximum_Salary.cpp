//1491. Average Salary Excluding the Minimum and Maximum Salary
//
//You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
//Return the average salary of employees excluding the minimum and maximum salary. 
//Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: salary = [4000,3000,1000,2000]
//Output: 2500.00000
//Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
//Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
//
//Example 2:
//Input: salary = [1000,2000,3000]
//Output: 2000.00000
//Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
//Average salary excluding minimum and maximum salary is (2000) / 1 = 2000

class Solution {
public:
    double average(vector<int>& salary) {
        int min_salary, max_salary;
        if(salary[0] < salary[1])
        {
            min_salary = salary[0];
            max_salary = salary[1];
        }
        else
        {
            min_salary = salary[1];
            max_salary = salary[0];
        }
        
        int total = 0;
        for(int i = 2; i < salary.size(); i++)
        {
            if(salary[i] < min_salary || salary[i] > max_salary)
            {
                if(salary[i] < min_salary)
                {
                    total += min_salary;
                    min_salary = salary[i];
                }
                else
                {
                    total += max_salary;
                    max_salary = salary[i];
                }
            }
            else
            {
                total += salary[i];
            }
        }

        double avg = static_cast<double>(total) /(salary.size() - 2);

        return round(avg * 100000) / 100000;
    }
};
