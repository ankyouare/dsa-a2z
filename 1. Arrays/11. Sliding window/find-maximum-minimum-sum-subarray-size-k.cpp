// https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/
// Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
//          k = 4 
// Output : 39

#include <iostream>
#include <limits.h>

/**
 * Intuition :
 * initialize i and j with 0.
 * Run a loop for array length 
 * with j variable being right of Window
 * i will be left of window.
 * Initially increase j until window size (i-j+1) is equal to k
 * then when window size is fixed.
 * until then also sum-up the elements.
 * move window one by one like substract previous element arr[i]
 * add next elememt arr[j] and sum-up the window items and 
 * check for maximum/minimum and save to a variable.
 */
int maximumSumSubarray(int arr[], int len, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    while(j < len)
    {
        sum += arr[j];
        j++;
        if((j-i+1) <= k)
        {
            continue;
        }
        maxSum = std::max(maxSum, sum);
        sum -= arr[i];
        i++;
    }
    return maxSum;
}

int minimumSumSubarray(int arr[], int len, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int minSum = INT_MAX;
    while(j < len)
    {
        // move window -- towards right by considering elt for sum and incrementing j
        sum += arr[j];
        std::cout<<"SUM. "<<sum<<std::endl;
        j++; 

        if((j-i+1) <= k)
        {
            continue;
        }
        minSum = std::min(minSum, sum);
        //move window -- only left here
        sum -= arr[i];
        std::cout<<"SUM.. "<<sum<<std::endl;
        i++;
    }
    return minSum;
}

int main()
{
    int arr[] = {9, 5, 5, 2, 0, 4, 1, 1, 0, 3, 1, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    int max = maximumSumSubarray(arr, len, 3);
    int min = minimumSumSubarray(arr, len, 3);
    std::cout<<"MAX sum: "<<max<<std::endl;
    std::cout<<"MIN sum: "<<min<<std::endl;
    return 0;
}
