// The API is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;  // Prevent overflow

            if (isBadVersion(mid)) {
                right = mid;      // First bad version is at mid or before
            } else {
                left = mid + 1;   // First bad version is after mid
            }
        }

        return left;
    }
};