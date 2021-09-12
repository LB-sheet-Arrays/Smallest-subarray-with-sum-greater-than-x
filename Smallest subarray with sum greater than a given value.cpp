/*
Brute force approach:

A simple solution is to use two nested loops. The outer loop picks a starting element, the inner loop considers all 
elements (on right side of current start) as ending element. Whenever sum of elements between current start and end becomes 
more than the given number, update the result if current length is smaller than the smallest length so far.

Time Complexity: O(n^2).

Efficient Solution: This problem can be solved in O(n) time using sliding window 
*/

#include<bits/stdc++.h>

using namespace std;

int smallestSubWithSum(int arr[], int n, int x)
{
	//use sliding window technique:
	int curr_sum=0,min_len=INT_MAX;
	
	int window_start=0;
	int window_end=0;
	
	 while(window_end<n)
	 {
	 	//keep adding elements to window till sum is <= x
	 	while (curr_sum <= x && window_end < n)
	 	{
	 		curr_sum += arr[window_end];
	 		window_end++;
		}
		
		// If current sum becomes greater than x.
        while (curr_sum > x && window_start < n) 
		{
            // Update minimum length if needed
            if (window_end - window_start < min_len)
            {
            	min_len = window_end - window_start;
			}
 
            // remove starting elements
            curr_sum -= arr[window_start];
            window_start++;
        }
    }
    
return min_len;
	 	
}

int main()
{
	int arr[] = { 1, 4, 45, 6, 10, 19 };
    int x = 51;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    //corner case
    int sum=0;
    for(int i=0;i<n;i++)
    {
    	sum=sum+arr[i];
	}
	if(sum<=x)
	{
		cout << "Subarray is Not possible"<<endl;
	}
	else if(sum>x)
	{
		int res = smallestSubWithSum(arr, n, x);
    	cout <<"\nLength of smallest subarray is => "<< res << endl;
	}

	
	return 0;
}
