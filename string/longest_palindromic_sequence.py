class Solution:
    def longestPalindrome(self, s: str) -> str:
        #max_left to 0
        max_left = 0
        #max_right to 0
        max_right = 0
        #set left to 0
        left = 0
        #set right to 0
        right = 0
        #set centers
        c1 = -1
        c2 = 0
        #iterate through s
        while c2 < len(s):
            #set center
            if c1==c2:
                c2+=1
            else:
                c1+=1
            left = c1
            right = c2
            #expand outward as long as palindrome
            while left >= 0 and right < len(s) and s[left]==s[right]:
                #if bigger than current max, replace max_indexes
                if (right - left) >= (max_right - max_left):
                    max_left = left
                    max_right = right
                left-=1
                right+=1

        #return string between max_left and max_right
        return s[max_left:max_right+1]

        
