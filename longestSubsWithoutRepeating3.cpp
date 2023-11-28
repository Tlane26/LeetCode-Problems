#include <iostream>
#include <set>

using namespace std;

/*
Given a string s, find the length of the longest 
substring
 without repeating characters.
*/
int main() {

  string s = "pwwkew";

  set<int> charSet;
  //set<int>::iterator it;
  int res = 0;
  int leftPt = 0; // leftPointer

  for(int i = 0; i < s.size(); i++){
    // mientras exista en el substring el char repetido eliminar de 
    // izquierda a derecha todos los demas char
    // hasta eliminar el repetido
    while(charSet.find(s[i]) != charSet.end()){
      charSet.erase(s[leftPt]);
      leftPt++;
    }
    // agregar el nuevo char
    charSet.insert(s[i]);
    res = max(res, i - leftPt + 1);
  }
  /*
  for (it=charSet.begin(); it!=charSet.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  */
  cout << res;

}