class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mp;

        int n = nums2.size();

        // Traverse nums2 from right to left
        for(int i = n-1; i >= 0; i--){

            // Pop smaller or equal elements
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            // Store NGE
            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]] = st.top();
            }

            // Push current element
            st.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};