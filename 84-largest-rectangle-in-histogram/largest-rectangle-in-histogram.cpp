class Solution {
public:
    void leftSmall(vector<int>& heights, vector<int> &left){
        stack<int> st;
        int i=1;
        st.push(0);
        while(i<heights.size()){
            if(heights[i]<heights[st.top()] && !st.empty()){
                st.pop();
            }
            if(!st.empty())
                left[i]=st.top()+1;
            st.push(i);
            i++;
        }
    }
    void rightSmall(vector<int> &heights, vector<int> &right){
        stack<int> st;
        int n= heights.size();
        int i=n-2;
        st.push(n-1);
        while(i>=0){
            if(heights[i]<heights[st.top()] && !st.empty()){
                st.pop();
            }
            if(!st.empty())
                right[i]=st.top()-1;
            st.push(i);
            i--;
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
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
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;

    }
};