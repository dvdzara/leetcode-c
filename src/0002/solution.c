// Copyright [2024] Davide Zarantonello

#include "src/0002/solution.h"

#include <stdlib.h>

#define NODE_MAX_VALUE 10

struct ListNode* add_two_numbers(struct ListNode* ln1, struct ListNode* ln2) {
  struct ListNode* root_node = calloc(1, sizeof(struct ListNode));
  struct ListNode* node = root_node;

  while (ln1 != NULL || ln2 != NULL) {
    node = node->next != NULL ? node->next : root_node;

    if (ln1 != NULL) {
      node->val += ln1->val;
      ln1 = ln1->next;
    }
    if (ln2 != NULL) {
      node->val += ln2->val;
      ln2 = ln2->next;
    }

    node->next = calloc(1, sizeof(struct ListNode));
    node->next->val = node->val / NODE_MAX_VALUE;
    node->next->next = NULL;
    node->val %= NODE_MAX_VALUE;
  }

  if (node->next->val == 0) {
    free(node->next);
    node->next = NULL;
  }

  return root_node;
}
