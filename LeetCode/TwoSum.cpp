class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        multimap<int, int> m;
        multimap<int, int>::iterator leftIter,rightIter;
        
        for (int i = 0; i < nums.size(); i++)
            m.insert(make_pair(nums[i], i));
        leftIter = m.begin();
        rightIter = --m.end();

        while (1)
        {
            if (leftIter->first + rightIter->first > target)
                rightIter--;
            else if (leftIter->first + rightIter->first < target)
                leftIter++;
            else
            {
                answer.push_back(leftIter->second);
                answer.push_back(rightIter->second);
                break;
            }
        }
        return answer;
      
    }
};