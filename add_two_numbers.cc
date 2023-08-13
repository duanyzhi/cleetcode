#include <iostream>
#include <vector>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  if (nullptr == l1) return l2;
  if (nullptr == l2) return l1;
  ListNode* cur = l1;
  ListNode* cur2 = l2;
  int pre = 0;
  std::stack<ListNode*> stacks;
  while (nullptr != cur || nullptr != cur2) {
     int value =  0;
     if (nullptr == cur) {
       value = cur2->val + pre;
       cur2 = cur2->next;
     } else if (nullptr == cur2) {
       value = cur->val + pre;
       cur = cur->next;
     } else {
       value = cur->val + cur2->val + pre;
       cur = cur->next;
       cur2 = cur2->next;
     }
     int mod = value % 10;
     if (value >= 10) {
       pre = value / 10;
     } else {
       pre = 0;
     }
     stacks.push(new ListNode(mod));
  }
  if (0 != pre) {
     stacks.push(new ListNode(pre));
  }
  ListNode* next_node = nullptr;
  while (!stacks.empty()) {
    ListNode* node = stacks.top();
    node->next = next_node;
    stacks.pop();
    next_node = node;
  }
  return next_node; 
}

void print(ListNode* node) {
  ListNode* cur = node;
  while(nullptr != cur) {
    std::cout << cur->val << " -> ";
    cur = cur->next;
  }
  std::cout << "\n";
}

int main() {
  ListNode a(3);
  ListNode b(4, &a);
  ListNode c(2, &b);

  ListNode a1(4);
  ListNode b1(6, &a1);
  ListNode c1(5, &b1);

  print(&c);
  print(&c1);
  ListNode* out = addTwoNumbers(&c, &c1);
  print(out);
}
