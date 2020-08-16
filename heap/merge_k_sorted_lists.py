from heapq import *

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if len(lists) == 0:
            return None
        #create empty return
        pq = []
        tail = None
        head = None
        ctr = 0
        #add k items to queue
        for n in lists:
            if n:
                heappush(pq, (n.val, ctr, n))
                ctr+=1
        #while queue is not empty
        while len(pq) != 0:
            #pick the smallest item from the queue and add the next item from that list
            val, c, n = heappop(pq)
            if n.next:
                heappush(pq, (n.next.val, ctr, n.next))
                ctr = ctr + 1
            #turn the item into a new node and add it the return list
            node = ListNode(val)
            if head:
                tail.next = node
                tail = node
            else:
                head = node
                tail = node

        #return the return list
        return head
        
