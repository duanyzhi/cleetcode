#include <iostream>
#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* l) {
  ListNode* cur = l;
  while (nullptr != cur) {
    std::cout << cur->val << " -> ";
    cur = cur->next;
  }
  std::cout << "\n";
}

ListNode* update(ListNode* cur, ListNode* val) {
  if (nullptr == cur) {
    return val;
  }
  cur->next = val;
  cur = val;
  return cur;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (nullptr == list1) return list2;  
  if (nullptr == list2) return list1;  
  ListNode* l1 = list1;
  ListNode* l2 = list2;
  ListNode* head = nullptr;
  if (l1->val < l2->val) {
    head = l1;
    l1 = l1->next;
  } else {
    head = l2;
    l2 = l2->next;
  }
  ListNode* out = head;
  while (nullptr != l1 || nullptr != l2) {
    if (nullptr == l1) {
       out = update(out, l2);
       l2 = l2->next;
       continue;
    }
    if (nullptr == l2) {
      out = update(out, l1);
      l1 = l1->next;
      continue;
    }
    if (l1->val < l2->val) {
      out = update(out, l1);
      l1 = l1->next;
    } else {
      out = update(out, l2);
      l2 = l2->next;
    }
  }
  return head;
}

int main() {
  ListNode n11(4);
  ListNode n12(2, &n11);
  ListNode n13(1, &n12);

  ListNode n21(4);
  ListNode n22(3, &n21);
  ListNode n23(1, &n22);
  print(&n13);
  print(&n23);

  ListNode* out = mergeTwoLists(&n13, &n23);
  print(out);
}
