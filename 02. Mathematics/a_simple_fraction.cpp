class Solution {
   public String fractionToDecimal(long numerator, long denominator) {
       
       if (numerator == 0) {
           return "0";
       }
       
       long n = Math.abs(numerator);
       long d = Math.abs(denominator);
       
       StringBuilder res = new StringBuilder(numerator < 0 ^ denominator < 0 ? "-" : "");
       res.append(n / d);
       
       if (n % d == 0) {
           return res.toString();
       }
       
       n %= d;
       res.append(".");
       HashMap<Long, Integer> remainders = new HashMap<>();
       remainders.put(n, res.length());
       
       while (n != 0) {
           n *= 10;
           res.append(n / d);
           n %= d;
           if (remainders.containsKey(n)) {
               int index = remainders.get(n);
               res.insert(index, "(");
               res.append(")");
               break;
           } else {
               remainders.put(n, res.length());
           }
       }
       
       return res.toString();
   }
}
