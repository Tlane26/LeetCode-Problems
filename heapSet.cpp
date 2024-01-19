#include <iostream>
#include <set>

using namespace std;

void add(set<int>&qHeap, int x){
    qHeap.insert(x);
}

void deleteElement(set<int>&qHeap, int x){
    auto it = qHeap.find(x);
    if(it != qHeap.end()){
        qHeap.erase(it);
    }
}

void printMin(const set<int>&qHeap){
    if(!qHeap.empty()){
        cout << *qHeap.begin() << endl;
    }
}

int main() {
    int q, f, x;
    set<int> qHeap;

    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> f;
        switch (f) {
            case 1:
                cin >> x;
                add(qHeap, x);
                break;
            case 2:
                cin >> x;
                deleteElement(qHeap, x);
                break;

            case 3:
                printMin(qHeap);
                break;
        }
    }   
    return 0;
}

/*
5
1 4
1 9
3
2 4
3


5           Q = 5
1 4         insert 4
1 9         insert 9
3           print minimum
2 4         delete 4
3           print minimum
*/