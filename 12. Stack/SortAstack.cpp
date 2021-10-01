void SortedStack :: sort()
{
    priority_queue<int,vector<int>,greater<int>> q;
  while(!s.empty())
  {
      q.push(s.top());
      s.pop();
  }
  
  while(!q.empty())
  {
      s.push(q.top());
      q.pop();
  }
}