/* Given an array of integers arr and two integers k and threshold, return the number of 
 * sub-arrays of size k with the average greater than or equal to threshold
 */
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::vector;

class Solution{

    public:
        int numOfSubarrays(vector<int>& arr, int k, int threshold){

            // Find the sum of the first k ints
            int sum = 0; // store the sum of the ints

            for(int i = 0; i < k; i++){
                sum += arr.at(i);
            }

            int average = sum / k;
            int counter = 0;

            // add to counter if the average is >= threshold
            if(average >= threshold){
                counter++;
            }

            // for the rest of the array:
            for(int j = k; j < arr.size(); j++){

                // slide the window up by one element
                sum -= arr.at(j - k);
                sum += arr.at(j);

                // calculate the average of these k elements
                average = sum / k;

                // update the counter
                if(average >= threshold){
                    counter++;
                }
            }

            // return counter
            return counter;
        }
};

int main(int argc, char * argv[]){

    vector<int> arr1 = {2, 2, 2, 2, 5, 5, 5, 8};
    int k1 = 3;
    int threshold1 = 4;


    vector<int> arr2 = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int k2 = 3;
    int threshold2 = 5;

    Solution sol;
    int answer1 = sol.numOfSubarrays(arr1, k1, threshold1);
    int answer2 = sol.numOfSubarrays(arr2, k2, threshold2);

    cout << "answer1: " << answer1 << endl << "answer2: " << answer2 << endl;

    return 0;
}
