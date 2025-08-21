#include "../core.hpp"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m-1;
        int n2 = n-1;
        int i = m + n - 1;

        while(n1 >= 0 && n2 >= 0){
            if (nums1[n1] > nums2[n2]){
                nums1[i] = nums1[n1];
                n1--;
            }else{
                nums1[i] = nums2[n2];
                n2--;
            }
            i--;
        }

        if (n1 >= 0){
            for (int j = n1 ; j >= 0 ; j--){
                nums1[i] = nums1[n1];
                n1--;
                i--;
            }
        }else{
            for (int j = n2 ; j >= 0 ; j--){
                nums1[i] = nums2[n2];
                n2--;
                i--;
            }
        }
    }
};