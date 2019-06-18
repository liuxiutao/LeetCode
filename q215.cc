#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& a, int start, int end)
    {
        int pivot = a[start];
        int left = start, right = end;
        while(left < right)
        {
            while(left < right && a[right] < pivot)
                right--;
            a[left] = a[right];

            while(left < right && a[left] >= pivot)
                left ++;
            a[right] = a[left];
        } 
        a[left] = pivot;
        return left;
    }

int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int s = 0, e = len - 1;
        int m = partition(nums, s, e);
        while(m != k - 1)
        {
            if(m > k - 1)
                e = m - 1;
            else
                s = m + 1;
            m = partition(nums, s, e);
        }
        return nums[m];
    }
    
int main(int argc, char const *argv[])
{
    vector<int> a = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(a, 4) << endl;
    return 0;
}
