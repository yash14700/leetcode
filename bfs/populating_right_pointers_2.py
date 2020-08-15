"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':

        #edge cases
        if not root:
            return root

        # intialize deque
        q = deque()
        # add root to queue followed by a null
        q.append(root)
        q.append(None)
        # in a loop
        while(len(q) != 1):
            # pop first element
            n = q.popleft()
            # if element:
            if n:
                # point to node in queue
                n.next = q[0]
                #add any children to queue
                if n.left:
                    q.append(n.left)
                if n.right:
                    q.append(n.right)
            # if null:
            else:
                # add a null to the queue
                q.append(None)
        return root
                
