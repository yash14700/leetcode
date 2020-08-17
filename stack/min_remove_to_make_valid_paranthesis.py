class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        #edge cases
        #empty string
        if not s:
            return ""

        """
        two goals
        -> figure out which parenthesis to remove
            - close > open
                delete the closing paranthesis
            - open > close
                delete the opening paranthessis
            - wrong ordering
                -
        -> remove them efficiently

        """

        #stack of index's of opening brackets
        opBrace = []
        #ignoren dictionary
        ignore = set()
        #iterate through string
        for i in range(len(s)):
            # if open bracket
            if s[i] == '(':
                #add index to stack
                opBrace.append(i)
            #if closed bracket
            if s[i] == ')':
                #if stack not empty, delte top item
                if opBrace:
                    opBrace.pop()
                #if stack empty
                else:
                    #add close bracket index to ignore set
                    ignore.add(i)
        #loop throgh stack and add any remaining index to ignore dictionary
        for idx in opBrace:
            ignore.add(idx)
        #iterate through string, copy each char not in ignore index pos and return
        result = ""
        for i in range(len(s)):
            if i in ignore:
                continue
            result += s[i]
        return result

        
