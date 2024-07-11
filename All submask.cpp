  int m;
  cin>>m;
  for (int s=m; ; s=(s-1)&m) {
    bitset<10> b(s);
    cout<<b<<endl;
  if (s==0)  break;
  }