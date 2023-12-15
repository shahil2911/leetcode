class Solution {
public:
    void leftSmall(vector<int>& heights, vector<int> &leftsmall){
        int n = heights.size();
        stack < int > st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty())
                leftsmall[i] = 0;
            else
                leftsmall[i] = st.top() + 1;
            st.push(i);
        } 
    }
    void rightSmall(vector<int> &heights, vector<int> &rightsmall){
        stack<int> st;
        int n= heights.size();
        for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
    }}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n),  right(n);
        leftSmall(heights,left);
        rightSmall(heights,right);
        int i=0,ans=0;
        while(i<heights.size()){
            ans=max(ans,(right[i]-left[i]+1)*heights[i]);
            i++;
        }
        return ans;

    }
};