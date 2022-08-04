/*
 *  Fourteen Patterns #2
 *
 *
    Detailed Problem:

    You are given an integer array height of length n. There are n vertical lines drawn such that the two 
    endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the 
    most water. Return the maximum amount of water a container can store.

    Two Pointers Pseudocode:
        1. Start at the beginning and end of the array
        2. While the two pointers don't intersect
            a. Find the minimum height
            b. Find the width
            c. Find the area
            d. If the area is larger than the current max, update it
            e. Increment or decrement the pointer that has the smaller height

    Note: the reason why we do not need to sort this array is because we are already starting with the 
    maximum width, therefore, we increment/decrement the pointers to find higher heights, since that will
    be the only variable able to increase our area, and that is what we search for. "The height can go up
    but the width will always go down."

    Only need to calculate heights that we larger than previous, otherwise we are calculating a new height
    that is both smaller in width and height, which is pointless.
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::vector;

class Solution {

    public:
        int maxArea(vector<int>& array){

            // Start at the beginning and end of the array
            int index1 = 0;
            int index2 = array.size() - 1;
            int minHeight = 0;
            int width = 0;
            int area = 0;
            int max = 0;
            // While the two pointers don't intersect
            while(index2 > index1){
                // Find the minimum height
                minHeight = (array.at(index1) < array.at(index2)) ? array.at(index1) : array.at(index2);
                // Find the width
                width = index2 - index1;
                // Find the area
                area = width * minHeight;
                // If the area is larger than the current max, update it
                if(area > max){
                    max = area;
                    cout << "index1: " << index1 << endl << "index2: " << index2 << endl << "area: " << max << endl;
                }
                // Increment or decrement the pointer that has the smaller height
                if(array.at(index1) > array.at(index2)){
                    // if left intex is greater
                    index2--;
                } else {
                    // if right intex is greater
                    index1++;
                }
            }

            return max;
        }

};

int main(int argc, char * argv[]){

    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution Saul;
    int ans = Saul.maxArea(heights);

    return 0;
}
