#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

// nullptr -> a -> b -> c -> nullptr
// 1. pre = nullptr, cur = a, next = b
// nullptr <- a <- b
// pre = a, cur = b, next = 
ListNode* reverse_list(ListNode* head) {
}

int main() {

}
