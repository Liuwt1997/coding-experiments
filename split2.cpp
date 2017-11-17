#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool space(char c){
  return isspace(c);
}

bool not_space(char c){
  return !isspace(c);
}

vector<string> split(const string& str){
  vector<string> ret;
  typedef string::const_iterator iter;
  iter i = str.begin();
  while(i != str.end()){
    i=find_if(i, str.end(), not_space);
    iter j=find_if(i, str.end(), space);
    if(i!=str.end())
      ret.push_back(string(i, j));
    i=j;
  }
  return ret;
}

int main()
{
  string s;
  while (getline(cin, s)){
    vector<string> v = split(s);
    for(vector<string>::size_type i=0; i!=v.size(); i++)
      cout<<v[i]<<endl;
  }
  return 0;
}
