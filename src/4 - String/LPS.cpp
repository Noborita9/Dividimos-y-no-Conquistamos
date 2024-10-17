#include <bits/stdc++.h>
using namespace std;

vector<int> getLps(string pat){ //geek4geeks implementatio with some changes
  vector<int> lps(pat.length(), 0);
  int len = 0;
  int i = 1;
  lps[0] = 0;
  while(i < pat.length()){
    if(pat[i] == pat[len]){
      len++;
      lps[i] = len;
      i++;
    }
    else //pat[i] != pat[len] 
    {
      lps[i] = 0;
      i++;
    }
  }

  return lps;
}
