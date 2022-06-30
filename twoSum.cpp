/* 1. Two Sum (C++) (easy)
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 */

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {

	public:

		vector<int> twoSum(vector<int>& nums, int target) {

			vector<int> solution = {0, 0};

			for(int i = 0; i < nums.size(); i++){
                for(int j = i + 1; j < nums.size(); j++){

                    if(nums.at(i) + nums.at(j) == target){
                        return vector<int> {i, j};
                    }
                }
			}

			return solution;
    }
};

int main(int argc, char * argv[]){

    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    vector<int> answer = sol.twoSum(nums, 17);

    cout << " " << answer.at(0) << ", " << answer.at(1) << endl;

    return 0;
}
