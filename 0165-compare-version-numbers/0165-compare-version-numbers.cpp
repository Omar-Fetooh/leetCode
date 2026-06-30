class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> nums1;
        vector<int> nums2;
        string portion = "0";
        for (int i = 0; i < version1.size(); i++) {
            if (version1[i] == '.') {
                nums1.push_back(stoi(portion));
                portion = "0";
            } else
                portion += version1[i];
        }
        nums1.push_back(stoi(portion));
        portion = "0";
        for (int i = 0; i < version2.size(); i++) {
            if (version2[i] == '.') {
                nums2.push_back(stoi(portion));
                portion = "0";
            } else
                portion += version2[i];
        }
        nums2.push_back(stoi(portion));
        if (nums1.size() > nums2.size()) {
            int diff = nums1.size() - nums2.size();
            for (int i = 0; i < diff; i++) {
                nums2.push_back(0);
            }
        } else if (nums2.size() > nums1.size()) {
            int diff = nums2.size() - nums1.size();
            for (int i = 0; i < diff; i++) {
                nums1.push_back(0);
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] < nums2[i])
                return -1;
            else if (nums1[i] > nums2[i])
                return 1;
        }
        return 0;
    }
};