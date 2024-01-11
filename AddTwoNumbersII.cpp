#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr){}
  ListNode(int x) : val(x), next(nullptr){}
  ListNode(int x, ListNode* next) : val(x), next(next){}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* temp;

    while (head) {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* r1 = reverseList(l1);
  ListNode* r2 = reverseList(l2);

  int totalSum = 0;
  int carry = 0;
  ListNode* ans = new ListNode();
  while (r1 || r2) {
      if (r1) {
          totalSum += r1->val;
          r1 = r1->next;
      }
      if (r2) {
          totalSum += r2->val;
          r2 = r2->next;
      }

      ans->val = totalSum % 10;
      carry = totalSum / 10;
      ListNode* head = new ListNode(carry);
      head->next = ans;
      ans = head;
      totalSum = carry;
  }
  return carry == 0 ? ans->next : ans;
  
}

void printLinkedList(const ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
  // Crear nodos para la primera lista [2, 4, 3]
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(4);
  ListNode* node3 = new ListNode(3);
  node1->next = node2;
  node2->next = node3;

  // Crear nodos para la segunda lista [5, 6, 4]
  ListNode* node4 = new ListNode(5);
  ListNode* node5 = new ListNode(6);
  ListNode* node6 = new ListNode(4);
  node4->next = node5;
  node5->next = node6;

  ListNode* result = addTwoNumbers(node1, node4);

  cout << "Resultado: ";
  printLinkedList(result);


  return 0;
}