#ifndef DSAInterview_H
#define DSAInterview_H

#include <vector>
#include <unordered_map>
using namespace std;

class DSAInterview
{
public:
    vector<int> TwoSum(vector<int>& nums, int target) {
		/*
            Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

            You may assume that each input would have exactly one solution, and you may not use the same element twice.

            You can return the answer in any order.
        */
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) == m.end())
            {
                m[target - nums[i]] = i;
            }
            else
            {
                return { m[nums[i]],i };
            }
        }
        return {-1,-1};
    }
    int MaxAreaContainer(vector<int>& heights)
    {
    /*
        Given n non-negative integers a1, a2, ..., an , 
        where each represents a point at coordinate (i, ai). 
        n vertical lines are drawn such that the two endpoints
        of the line i is at (i, ai) and (i, 0). 
        
        Find two lines, which, together with the x-axis forms 
        a container, such that the container contains the most
        water.
        */

        int n = heights.size();
        int area = 0;
        int lptr = 0, rptr = n - 1;

        while (lptr < rptr)
        {
                area = max(area, (rptr - lptr) * (min(heights[lptr], heights[rptr])));
                if (heights[lptr] < heights[rptr])
                {
                    lptr++;
                }
                else if (heights[rptr] < heights[lptr])
                {
                    rptr--;
                }
                else
                {
                    lptr++;
                    rptr--;
                }
        }
        return area;

    }
    int TrapRainwater(vector<int>& height)
    {
    /*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
    
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
    
    */

        int l = 0, r = height.size() - 1, l_max = 0, r_max = 0, value_bucket = 0;

        while (l < r) {
            r_max = max(r_max, height[r]);
            value_bucket += r_max - height[r];

            l_max = max(l_max, height[l]);
            value_bucket += l_max - height[l];

            if (height[l] <= height[r]) l++;
            else r--;
        }
        return value_bucket;
    }


};

#endif