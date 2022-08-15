5.Longest Palindromic Substring

// Consider every index as a center, take two pointers, one on the left and one on the right
    // keep checking and expanding these pointers, till the characters on left-right match
    // We need to check above scenarios for both even length and odd length strings, considering every index starting from 1, as the center
    // So for even length string, center = i, left = i-1, right = i (because we have two mid points for even length string)
    // For odd length string, center = i, left = i-1 and right = i+1. 
    


 string longestPalindrome(string s) {
        int n = s.length();
         int start =0; int maxlen = 1;
        for (int i = 1; i<n; i++) {
            int low = i-1;     //for even length
            int high = i;
            while(low >= 0 and high < n and s[low] == s[high]) {
                if ( maxlen < high - low + 1) {
                   
                        maxlen = high-low+1;
                        start = low;
                            
                }
                
                low--;
                high++;
            }
            
            low = i-1;     //for odd length
            high = i+1;
            while(low >= 0 and high < n and s[low] == s[high]) {
                if ( maxlen < high - low + 1) {
                   
                        maxlen = high-low+1;
                        start = low;
          
                }
               
                low--;
                high++;
            }
        }
        return s.substr(start, maxlen);
    }



       