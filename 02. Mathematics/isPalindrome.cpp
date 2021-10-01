
// to checkout if the given integer number is palindrome or not 
// number might be -ve 

bool isPalindrome(int x) {
  long result = 0;

  if (x < 0)
    return false;

  long original = (long) x;

  while (x != 0) {
    result = result * 10 + x % 10;
    x = x / 10;
  }

  if (original == result)
    return true;
  else
    return false;
}
