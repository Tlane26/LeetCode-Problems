/*
Objective: Given a number, find out whether its colorful or not.

Colorful Number: When in a given number, product of every digit of a sub-sequence are different. That number is called Colorful Number. See Example

*/

#include <iostream>
#include <unordered_set>

using namespace std;

int product(string sub){
  int prod = 1;
  for(int i = 0; i < sub.size(); i++){
    prod *= sub[i] - '0';
  }
  return prod;
}

bool colorful(int x){
  string y = to_string(x);
  string sub = "";
  unordered_set<int> set;
  
  for(int i = 0; i < y.size(); i++){
    for(int j = i; j < y.size(); j++){
        sub += y[j];
        if(set.find(product(sub)) != set.end()){
          return false;
        }
        else{
          set.insert(product(sub));
        }
    }
    sub = "";
  }
  return true;
}


int main() {
  int x = 326;

  cout << x << " " << colorful(x) << endl;
  
}

// 3245 -> 1
// 326 -> 0