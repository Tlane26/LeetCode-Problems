#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct queue{
    stack<T> oldestOnTop;
    stack<T> newestOnTop;

  // add value
  void enqueue(T x){
    newestOnTop.push(x);
  }

  void shift(){
    if(oldestOnTop.empty()){
      while(!newestOnTop.empty()){
        oldestOnTop.push(newestOnTop.top());
        newestOnTop.pop();
      }
    }
  }

  // delete top value and return it
  T dequeue(){
    shift();
    T top = oldestOnTop.top();
    oldestOnTop.pop();

    return top;
  }

  // print top value
  void printTop(){
    shift();
    cout << oldestOnTop.top() << endl;
  }
};


int main() {
  int q, t, x;
  cin >> q;

  queue<int> myQueue;

  for(int i = 0; i < q; i++){
      cin >> t;

      if(t == 1){
          cin >> x;
          myQueue.enqueue(x); 
      }
      else if(t == 2){
          myQueue.dequeue();
      }
      else{
          myQueue.printTop();
      }
  }
}

/*
1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.

10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2
*/