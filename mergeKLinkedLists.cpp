#include <vector>
#include <algorithm>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

using namespace std;

ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> nodes;
    ListNode* head = new ListNode(0);
    ListNode* point = head;

    for (auto l : lists) {
        while (l != nullptr) {
            nodes.push_back(l->val);
            l = l->next;
        }
    }

    sort(nodes.begin(), nodes.end());

    for (int x : nodes) {
        point->next = new ListNode(x);
        point = point->next;
    }

    return head->next;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
  // Crear nodos para la primera lista [1,4,5]
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(4);
  ListNode* node3 = new ListNode(5);
  node1->next = node2;
  node2->next = node3;

  // Crear nodos para la segunda lista [1,3,4]
  ListNode* node4 = new ListNode(1);
  ListNode* node5 = new ListNode(3);
  ListNode* node6 = new ListNode(4);
  node4->next = node5;
  node5->next = node6;

  // Crear nodos para la tercera lista [2,6]
  ListNode* node7 = new ListNode(2);
  ListNode* node8 = new ListNode(6);
  node7->next = node8;

  // Crear el vector de punteros a nodos
  vector<ListNode*> lists = {node1, node4, node7};

  ListNode* mergedList = mergeKLists(lists);

  cout << "Merged List: ";
  printLinkedList(mergedList);
  
  return 0;
}
