/*
75. Sort Colors


Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]




Solution:

To solve this we are going to be using the two pointer method

We will have two pointers left and right
we will also need a swap function to swap elements 

we can use a temp pointer variable to swap the functions


We keep going until i is greater than high

left will swap if it comes across 0's , right will swap if it comes across 2's

however since we are going from left to right, upon finding a 2,
we will decrement high but we wont increment i, since i can be any of the three
values

*/

#include <iostream>
#include <vector>



class Solution {
public:
	void sortColors(std::vector<int>& nums);


private:
	void swapFunction(int* i, int* x);
};



void Solution::swapFunction(int* i, int* x) {
	//Create an int variable
	int temp;

	//Swap i and x
	temp = *i;
	*i = *x;
	*x = temp;
}


void Solution::sortColors(std::vector<int>& nums) {
	//Create our variables, left and right
	int left = 0;
	int right = nums.size() - 1;

	//We are also going to need a temp variable in our swap method

	//We want to create a for loop to iterate through nums
	for (int i = 0; i < right; i++) {

		
		//During each iteration we want to check if the number is 0,1,2
		//we can create an if statement to account for these scenarios

		if (nums[i] == 0) {

			//Use the swap function to swap i and left
			swapFunction(&nums[i], &nums[left]);
			//Then increment left and i to continue iteration
			left++;

			//This essentially increments i, since we are iterating through i, this will be i++
			//If we do i++ here instead of continue, then we will actually miss an element
			//It will iterate twice instead of once
			continue;
		}

		//If i == 1, then we do not advance left since we are looking only for 0
		//However we do advance i, this means that our 1's will stay in the middle
		//After the full iteration
		if (nums[i] == 1) {
			continue;
		}

		//If i == 2, then we want to swap i with high, decrement high and check for I again
		//If we exit this if statement i will increment before checking so we want to
		//check within this if statement 
		//We use a while loop to continuously scan to see the value of i whenver it is 2
		while (nums[i] == 2 && i < right) {
			swapFunction(&nums[i], &nums[right]);
			right--;

			//After using the swap function when i was 2, check it again to see its new value
			//We only break out of this while loop if i != 2
			if (nums[i] == 0) {
				swapFunction(&nums[i], &nums[left]);
				//Then increment left and i to continue iteration
				left++;
				continue;
			}
			else if (nums[i] == 1) {
				continue;
			}

		}
	}

}


int main() {

	Solution solution;

	std::vector<int> array1 = { 2,0,2,1,1,0 };
	std::vector<int> array2 = { 2,0,1 };
	
	solution.sortColors(array1);

	/*for (int x : result) {
		std::cout << x << ' ';
	}*/


	//Time o(n^2)
	//Space o(1)

	return 0;
}