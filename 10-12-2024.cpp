//2981. Find Longest Special Substring That Occurs Thrice I
//10/12/2024
//By paulo_ar
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int maximumLength (string s){
  int ans = -1;
  vector <int> siz;
  bool v [51];
  for(int i=0; i<=50; i++)v[i]=0;
  char c = 'a';
  int parcial = 0;
  s+="2";
  for(int j=0; j<s.length(); j++){
      if(v[j] || s[j]=='2')continue;
      c=s[j];
      parcial=0;
      for(int i=0; i<s.length(); i++){
         if(s[i]!=c){
             if(parcial>0)siz.push_back(parcial);
                parcial = 0;
             }
             else if(s[i]==c){             
                parcial++;
                v[i]=1;
             }
        }
      for(int i=50; i>0; i--){
          int sum =0;
          for(int k=0; k<siz.size(); k++){    
               if(siz[k]>=i)sum+=(siz[k]-i)+1;
          }
          if(sum>=3) ans = max(ans,i);    
      }
      siz.resize(0);
  }
return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<< maximumLength(s);
    return 0;
}
