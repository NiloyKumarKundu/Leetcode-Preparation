#include <bits/stdc++.h>
using namespace std;

struct node {
	int val;
	struct node *next;
};

typedef struct node Node;

void insert(Node* &head, int val) {
	if (head == NULL) {
		head = new Node();
		head->val = val;
		head->next = NULL;
	} else {
		Node *temp = new Node();
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		Node *flag = new Node();
		flag->val = val;
		flag->next = NULL;
		temp->next = flag;
	}
}

void display(Node* &head) {
	Node *temp = head;
    while (temp != NULL) {
		cout << temp->val << endl;
		temp = temp->next;
	}
}



int main() {
	Node *head = NULL;
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


	display(head);
}