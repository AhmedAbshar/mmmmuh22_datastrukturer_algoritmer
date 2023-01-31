
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Constructor with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

class Storage
{
public:
    Node *head;

    /** Default constructor
     * 
    */
    Storage()
    {
        head = NULL;
    }
/** Create a Node to hold the data, then put it at the head of the list.
 * @param text The data for the new node
*/
void push(int data)
{
    Node * n = new Node(data);
    if (this->head == NULL) {
        this->head = n;
        return;
    }

    n->next = this->head;
    this->head = n;
}

/** Remove the head Node and return its data.
 * 
 * @param [out] The data (only valid if return true)
 * @return True if there is a node to return
*/
bool pop(int &data) {
    if (this->head == NULL) {
        data = 0;
        return false;
    }

    Node * n = this->head;
    this->head = n->next;
    data = n->data;
    return true;
}

/**
 * Return the data from the head Node, without removing it.
 * 
 * @param [out] The data (only valid if return true)
 * @return True if text has been returned successfully (there is a node)
*/
bool peek(int &data) {
    if (this->head == NULL) {
        data = 0;
        return false;
    }

    Node * n = this->head;
    data = n->data;
    return true;
}

/**
 * Return True if the list is empty, otherwise False 
 * 
 * @return True if the storage is empty
*/
bool isEmpty() {
    return (this->head == NULL);
}

/**
 * Swaps the nodes at position i and j.
 * 
 * @return Returns true if successful, otherwise false (e.g. outside range)
*/
bool swap(int i, int j) {
    if (i == j) {
        // Todo: Remove this if-case?
        return true;
    }
    if (this->head == NULL) {
        return false;
    }

    // We are searching for node _before_ the index, in order to be able to swap
    Node * n1 = NULL;
    Node * n2 = NULL;
    int k = 0;
    Node * node_i = this->head;

    while (node_i->next != NULL) {
        k++;
        if (i==k) {
            n1 = node_i;
        }
        if (j==k) {
            n2 = node_i;
        }
        node_i = node_i->next;
    }
            
    if (n1 != NULL && n2!=NULL) {
        Node * temp = n1->next;
        n1->next = n2->next;
        n2->next = temp;
        temp = n1->next->next;
        n1->next->next = n2->next->next;
        n2->next->next = temp;
        return true;
    } else if (i==0 && n2!=NULL) {
        Node * temp = this->head;
        Node * temp2 = n2->next->next;
        this->head = n2->next;
        n2->next = temp;
        this->head->next = temp->next;
        n2->next->next = temp2;
        return true;
    } else if (j==0 && n1!=NULL) {
        Node * temp = this->head;
        Node * temp2 = n1->next->next;
        this->head = n1->next;
        n1->next = temp;
        this->head->next = temp->next;
        n1->next->next = temp2;
        return true;
    }
    
    return false;
}
    
};
int main() {
    Storage *s = new Storage();
    s->push(2);
    int pop;
    s->pop(pop);
    cout << pop << endl;
}
