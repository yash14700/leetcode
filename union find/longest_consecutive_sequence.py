class Solution(object):
    def __init__(self):
        self.master = dict()

    def find_master(self, num):
        if not  num-1 in self.master and self.master[num]['m'] == num:
            return num
        elif not num-1  in self.master:
            return self.master[num]['m']
        else:
            return self.find_master(num-1)


    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        for num in nums:
            self.master[num] = {'m': num, 'children': set()}

        for num in nums:
            if num-1 in self.master:
                head = self.find_master(num-1)
                self.master[num]['m'] = head
                if not num in self.master[head]['children']:
                    self.master[head]['children'].add(num)

        max = 1
        print(self.master)
        for num in nums:
            if self.master[num]['m'] == num and len(self.master[num]['children']) + 1 > max:
                max = len(self.master[num]['children']) + 1
        return max
