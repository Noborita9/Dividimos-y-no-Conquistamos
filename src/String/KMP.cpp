vec<int> kmp(string pat, string sec){ //geeks4geeks implementation with some changes
  int m = pat.length();
  int n = sec.length();
  cout << m << " " << n << endl; 

  vec<int> lps = getLps(pat);
  vec<int> res;

  int i = 0;
  int j = 0;

  while((n - i) >= (m - j)){
    if(pat[j] == sec[i]){
      i++;
      j++;
    }
    if(j == m){
      res.push_back(i - j);
      j = lps[j - 1];
    }
    else{
      if(i < n && pat[j] != sec[i]){
        if(j != 0) j = lps[ j - 1 ];
        else i = i + 1;
      }
    }
  }

  return res;
}