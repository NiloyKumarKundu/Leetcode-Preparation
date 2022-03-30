// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    
    struct Node* reverse(struct Node* head) {
        struct Node* temp = NULL;
        struct Node* cur = head;
        while (head != NULL) {
            cur = head->next;
            head->next = temp;
            temp = head;
            head = cur;
        }
        return temp;
    }
    
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        
        struct Node* dummy = new struct Node(0);
        struct Node* ans = dummy;
        
        int carry = 0;
        
        while (first != NULL || second != NULL || carry) {
            int sum = 0;
            if (first != NULL) {
                sum += first->data;
                first = first->next;
            }
            if (second != NULL) {
                sum += second->data;
                second = second->next;
            }
            sum += carry;
            carry = sum / 10;
            struct Node* node = new struct Node(sum % 10);
            ans->next = node;
            ans = ans->next;
        }
        
        dummy = reverse(dummy->next);
        return dummy;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends