#include <iostream>
#include <stack>

using namespace std;

int main() {
  string path = "/a//b////c/d//././/..";
  stack<string> pPaths;
  string curr = "";

  path += '/';
  
  for(int i = 0; i < path.size(); ++i){
      if (path[i] == '/'){
          if(curr == ".."){
              if(!pPaths.empty()){ 
                pPaths.pop();
              }
          }
          else if(curr != "" && curr != ".") pPaths.push(curr);
          curr = "";
      }
      else{
          curr += path[i];
      }
  }

  string res;

  while(!pPaths.empty())
  {
      res = "/" + pPaths.top() + res;
      pPaths.pop();
  }

  if(res.size() == 0){
      cout << "/";
      return 0 ;
  }

  cout << res;

  return 0;
}