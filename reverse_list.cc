#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// nullptr -> a -> b -> c -> nullptr
// 1. pre = nullptr, cur = a, next = b
// nullptr <- a <- b
// a.next = pre; b.next = a;

ListNode* reverse(ListNode* pre,ListNode* cur){
    if(cur == NULL) return pre;
    ListNode* temp = cur->next;
    cur->next = pre;
    return reverse(cur,temp);
}

ListNode* reverse_list(ListNode* head) {
  ListNode* pre = nullptr;
  ListNode* cur = head;
  if (nullptr == head) return head;
  ListNode* next = head->next;
  while (nullptr != cur) {
    std::cout << "cur node" << cur->val << "\n";
    cur->next = pre;

    pre = cur;
    cur = next; // search next node 
    if (nullptr != cur) next = cur->next;
  }
  return pre;
}

void print(ListNode* head) {
  ListNode* cur = head;
  while (nullptr != cur) {
    std::cout << cur->val << "->";
    cur = cur->next;
  }
}
 
int main() {
  ListNode n5(5);
  ListNode n4(4, &n5);
  ListNode n3(3, &n4);
  ListNode n2(2, &n3);
  ListNode n1(1, &n2);

  print(&n1);
  ListNode* reverse_node = reverse_list(&n1);
  print(reverse_node);

  std::cout << "methods2:\n";
  ListNode* rev_node = reverse(nullptr, reverse_node);
  print(rev_node);
}
