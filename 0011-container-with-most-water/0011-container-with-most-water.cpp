class Solution {
public:
   int maxArea(vector<int>& height) {
    int area = 0,maxi=0;
    int n = height.size();
    int l = 0, r = n - 1;
    while (l<r)
    {
         area = min(height[l], height[r]) * (r - l);
         maxi = max(maxi, area);
         if (height[l] < height[r]) {
             ++l;
         }
         else --r;
    }
    return maxi;
}
};