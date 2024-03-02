
#include <iostream>
#include <vector>
using namespace std;

class LongestIncreasingSubsequence 
{
public:
    static pair<int, vector<int>> findLongestIncreasingSubsequence(const vector<int>& nums) 
    {
        // TODO: 添加你的代码，实现你的功能
        int maxLength = 0;
        vector<int> longestSubsequence;
        vector<int> length(nums.size());
        vector<vector<int>> Subsequnce(nums.size());
        int index,max;
        for(int i = nums.size() - 1;i >= 0;i--)
        {
            max = 0;
            index = 0;
            length[i] = 1;
            Subsequnce[i].push_back(nums[i]);
            //find bigger and longest 
            for(int j = i + 1;j < nums.size();++j)
            {
                if(nums[i] < nums[j] && max < length[j])
                {
                    max = length[j];
                    index = j;
                }
            }
            if(index != 0)
            {
                length[i] += length[index];
                addElement(Subsequnce[i],Subsequnce[index]);
            }
            if(maxLength < length[i])
            {
                maxLength = length[i];
                longestSubsequence = Subsequnce[i];
            }
        }

        return { maxLength, longestSubsequence };
    }
private:
    static void addElement(vector<int>& i,vector<int>& j);
};
void LongestIncreasingSubsequence::addElement(vector<int>& i,vector<int>& j)
{
    for(auto it = j.begin(),itend = j.end();it != itend;++it)
    {
        i.push_back(*it);
    }
}
int main() {
    vector<int> input = {0,100,1,2,3,4};

    auto result = LongestIncreasingSubsequence::findLongestIncreasingSubsequence(input);
    cout << "Longest Increasing Subsequence: ";
    for (int num : result.second) 
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Length of Longest Increasing Subsequence: " << result.first << endl;

    return 0;
}