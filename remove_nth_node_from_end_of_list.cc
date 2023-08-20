#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (nullptr == head) return head;
  std::stack<ListNode*> all_node;
  ListNode* curr = head;
  while (nullptr != curr) {
    all_node.push(curr);
    curr = curr->next;
  }
  int index = 1;
  ListNode* output = nullptr;
  while (!all_node.empty()) {
    if (index == n) {
      std::cout << "hit " << all_node.top()->val << "\n";
      all_node.pop();
      ++index;
      continue;
    }
    ListNode* node = all_node.top();
    std::cout << "pop value " << node->val;
    node->next = output;
    output = node;
    std::cout << "output val" << output->val << "\n";
    all_node.pop();
    ++index;
  }
  return output;
}

void print(ListNode* head) {
  ListNode* curr = head;
  while (nullptr != curr) {
    std::cout << curr->val << " -> ";
    curr  = curr->next;
  }
  std::cout << "\n";
}

int main() {
  // ListNode n5(5);
  // ListNode n4(4, &n5);
  // ListNode n3(3, &n4);
  // ListNode n2(2, &n3);
  ListNode n2(2);
  ListNode n1(1, &n2);
  print(&n1);
  ListNode* out = removeNthFromEnd(&n1, 1);
  print(out);
}
