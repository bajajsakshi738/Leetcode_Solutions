class Solution {
private:
    int findMax(vector<int> &arr, int n)
    {
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi = max(arr[i], maxi);
        }
        return maxi;
    }

    int findSmallestDivisor(int mid, int threshold, vector<int> &arr)
    {
        int minValue=0;
        for(int i=0;i<arr.size();i++)
        {
            minValue+= ceil((double)arr[i]/ (double)mid);
        }
        return minValue;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int s=1, e=findMax(nums, n);
        int ans=-1;

        while(s<=e)
        {
            int mid = s+(e-s)/2;

            int smallestNo = findSmallestDivisor(mid, threshold, nums);
            
            //mid can be a possible answer
            if(smallestNo <= threshold)
            {
                ans = mid;
                e=mid-1;
            }
            else //mid does not fit in threshold
                s=mid+1;
        }
        return ans;
    }
};