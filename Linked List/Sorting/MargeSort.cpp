// Time Complexity: O(NlogN)

#include <bits/stdc++.h>
using namespace std;

struct node {
	int val;
	struct node *next;
};

typedef struct node ListNode;

void insert(ListNode* &head, int val) {
	if (head == NULL) {
		head = new ListNode();
		head->val = val;
		head->next = NULL;
	} else {
		ListNode *temp = new ListNode();
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		ListNode *flag = new ListNode();
		flag->val = val;
		flag->next = NULL;
		temp->next = flag;
	}
}

void display(ListNode* &head) {
	ListNode *temp = head;
    while (temp != NULL) {
		cout << temp->val << endl;
		temp = temp->next;
	}
}


ListNode* middleNode(ListNode* head) {
	ListNode *slow = head, *fast = head->next;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode *mid = slow->next;
	slow->next = NULL;
	return mid;
}

ListNode* merge(ListNode* l1, ListNode* l2) {
	ListNode *dummyNode = new ListNode();
	ListNode *current = dummyNode;
	while (l1 != NULL && l2 != NULL) {
		if (l1->val <= l2->val) {
			current->next = l1;
			l1 = l1->next;
		} else {
			current->next = l2;
			l2 = l2->next;
		}
		current = current->next;
	}
	current->next = l1 != NULL ? l1 : l2;
	return dummyNode->next;
}

ListNode* mergeSort(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *mid = middleNode(head);
	ListNode *left = mergeSort(head);
	ListNode *right = mergeSort(mid);

	return merge(left, right);
}

int main() {
	ListNode *head = NULL;
	insert(head, 50);
	insert(head, 60);
	insert(head, 70);
	insert(head, 90);
	insert(head, 10);
	insert(head, 20);
	insert(head, 50);
	insert(head, 80);
	insert(head, 30);

	display(head);
	cout << endl;
	cout << endl;

	ListNode *sortedList = mergeSort(head);

	display(sortedList);
}