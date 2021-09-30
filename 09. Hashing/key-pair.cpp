bool hasArrayTwoCandidates(int nums[], int n, int x) {
  unordered_map < int, int > mp;

  int sz = n;
  for (int i = 0; i < sz; i++) {
    int rem = x - nums[i];

    if (mp.find(rem) != mp.end()) {
      return true;
    } else {
      mp[nums[i]] = i;
    }
  }
  return false;
}
