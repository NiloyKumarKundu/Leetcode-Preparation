// Time Complexity: O(N)
// Space Complexity: O(1)
// From: www.codingninjas.com

/****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/


LinkedListNode<int>* moveToFront(LinkedListNode<int> *head) {

    /*
     Don't write main().
     Don't read input, it is passed as function argument.
     Write your code here.
    */
    
    if (head->next == NULL) {
        return head;
    }
    
    LinkedListNode<int>* cur = head;
    LinkedListNode<int>* prev = NULL; 
    
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }
    
    prev->next = NULL;
    cur->next = head;
    head = cur;
    
    return head;

}
