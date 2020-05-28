class Solution {
public:
    unordered_map<char, string> mp = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};
    vector<string> result = {};
    vector<string> letterCombinations(string digits) {
      string lc = "";
      lcRecurrsive(digits, 0, lc);
      return this->result;
    }

    void lcRecurrsive(string & digits, int pos, string & lc) {

      if (digits == "") {
        return;
      }
      //if lc is complete
      if(pos == digits.size()) {
        this->result.push_back(lc);
        return;
      }

      for(char l : mp[digits[pos]]) {
        lc.push_back(l);
        lcRecurrsive(digits, pos+1, lc);
        lc.pop_back();
      }


    }
};
