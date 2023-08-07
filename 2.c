/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /**
 * 思路：l1与l2对应结节点相加，注意进位
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    typedef struct ListNode ListNode;
    ListNode hnode, * tail = &hnode;
    tail->next = NULL;
    int n = 0;
    while (l1 && l2) {
        ListNode* node = calloc(1, sizeof(ListNode));
        node->next = tail->next;
        tail->next = node;
        tail = node;
        node->val = l1->val + l2->val + n;
        if (node->val >= 10) {
            n = node->val / 10;
            node->val %= 10;
        }
        else {
            n = 0;
        }
        l1 = l1->next, l2 = l2->next;
    }
    while (l1 == NULL && l2 != NULL) {
        ListNode* node = calloc(1, sizeof(ListNode));
        node->next = tail->next;
        tail->next = node;
        tail = node;
        node->val = l2->val + n;
        if (node->val >= 10) {
            n = node->val / 10;
            node->val %= 10;
        }
        else {
            n = 0;
        }
        l2 = l2->next;
    }
    while (l2 == NULL && l1 != NULL) {
        ListNode* node = calloc(1, sizeof(ListNode));
        node->next = tail->next;
        tail->next = node;
        tail = node;
        node->val = l1->val + n;
        if (node->val >= 10) {
            n = node->val / 10;
            node->val %= 10;
        }
        else {
            n = 0;
        }
        l1 = l1->next;
    }
    if (l1 == NULL && l2 == NULL) {
        if (n != 0) {
            ListNode* node = calloc(1, sizeof(ListNode));
            node->next = tail->next;
            tail->next = node;
            tail = node;
            node->val = n;
        }
    }
    return hnode.next;
}