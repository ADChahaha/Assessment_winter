
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
        for(int i = nums.size() - 1;i >= 0;i--)
        {
            length[i] = 1;
            Subsequnce[i].push_back(nums[i]);
            //find first bigger element
            for(int j = i + 1;j < nums.size();++j)
            {
                if(nums[j] > nums[i])
                {
                    //add length and all elements of j to i
                    length[i] += length[j];
                    addElement(Subsequnce[i],Subsequnce[j]);
                    break;
                }
            }
        }
        maxLength = length[0];
        longestSubsequence = Subsequnce[0];
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
    vector<int> input = {10, 22, 9, 33, 21, 50, 41, 60, 80};

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