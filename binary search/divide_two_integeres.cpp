class Solution {
public:
  //edge cases: dividend = 0,
    int divide(int dividend, int divisor) {
      double abs_dividend = abs((double)dividend);
      double abs_divisor = abs((double)divisor);
      double quotient = 1;
      double q_inc = 1;
      double temp = abs_divisor;
      double temp_inc = abs_divisor;
      double result;
      bool ispositive = ((dividend > 0 && divisor > 0) || ((dividend < 0 && divisor < 0)))?true:false;
      if(abs_dividend < abs_divisor) {
        return 0;
      }
      if (abs_divisor == 1) {
        if(ispositive) {
          result = abs_dividend;
          return (result < -2147483648 || result > 2147483647)?2147483647:(int)result;
        }
        result =  (0 - abs_dividend);
        return (result < -2147483648 || result > 2147483647)?2147483647:(int)result;
      }
      while(true) {
        //if decrementing is less than dividend but incrementing is more, return
        if(temp <= abs_dividend && (temp - abs_divisor) < abs_dividend && (temp + abs_divisor) > abs_dividend) {
          if(ispositive) {
            result = quotient;
            return (result < -2147483648 || result > 2147483647)?2147483647:(int)result;
          }
          result = (0 - quotient);
          return (result < -2147483648 || result > 2147483647)?2147483647:(int)result;
        }
        //if temp is less
        if (temp < abs_dividend) {
          //if last increment was negative, reset
          if(q_inc < 0) {
            q_inc = 1;
            temp_inc = abs_divisor;
          }
          temp+=temp_inc;
          quotient+=q_inc;
          temp_inc+=temp_inc;
          q_inc+=q_inc;
        }
        //if temp is more
        if(temp > abs_dividend) {
          //if last increment was positive, reset
          if(q_inc > 0) {
            q_inc = -1;
            temp_inc = 0 - abs_divisor;
          }
          temp+=temp_inc;
          quotient+=q_inc;
          temp_inc+=temp_inc;
          q_inc+=q_inc;
        }
      }
      return 0;
    }
};
