class Solution:
    #for each section -> units, tens, and a hundreds
    one_tens = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
    ones = ['One', 'Two','Three','Four','Five','Six','Seven','Eight', 'Nine']
    tens = ['', 'Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety']
    hundreths = ['One Hundred', 'Two Hundred', 'Three Hundred', 'Four Hundred', 'Five Hundred',  'Six Hundred', 'Seven Hundred', 'Eight Hundred', 'Nine Hundred']

    def getSectionWord(num):
        word = ''
        u = int(num % 10)
        num/=10
        num = int(num)
        t = int(num % 10)
        num/=10
        num = int(num)
        h = num
        #print((h, t, u))

        if h > 0:
            word += Solution.hundreths[h-1]
            if t > 0 or u > 0:
                word += ' '
        if t > 0 and t != 1:
            word += Solution.tens[t-1]
            if u > 0:
                word += ' '
        if t == 1:
            word += Solution.one_tens[u]
            return word
        if u > 0:
            word += Solution.ones[u-1]
        #print(word)
        return word



    def numberToWords(self, num: int) -> str:
        if num == 0:
            return 'Zero'
        #result
        result = ''

        #sections
        section_name = ['', 'Thousand', 'Million', 'Billion']
        sections = []

        #go through the number and divide it into sections
        while num > 0:
            sections.append(int(num % 1000))
            num/=1000
            num = int(num)
        #print(sections)

        #for each section starting from the last
        i = len(sections) - 1
        while i >= 0:
            #represent the number based on its hundreths, tens and unit digit
            result += Solution.getSectionWord(sections[i])
            #add section name
            if i > 0 and sections[i] > 0:
                result += ' ' + section_name[i]
            j = i-1
            while sections[i] > 0 and j >= 0:
                if sections[j] > 0:
                    result += ' '
                    break
                j-=1
            i-=1

        return result
