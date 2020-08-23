#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct DoublyLinkedList {
    Node *start;
    Node *end;
    int length;

    DoublyLinkedList() {
        start = nullptr;
        end = nullptr;
        length = 0;
    }

    Node *createNode(int x) {
        Node *node = new Node();
        node->data = x;
        node->next = nullptr;
        node->prev = nullptr;
        return node;
    }

    void insertStart(Node *node) {
        if (length == 0) {
            start = node;
            end = node;
        }
        else {
            node->next = start;
            start->prev = node;
            start = node;
        }
        length++;
    }

    void insertEnd(Node *node) {
        if (length == 0) {
            start = node;
            end = node;
        }
        else {
            end->next = node;
            node->prev = end;
            end = node;
        }
        length++;
    }

    void insert(Node *node, int k) {
        if (k <= length) {
            if (k == 0) {
                insertStart(node);
            }
            else if (k == length) {
                insertEnd(node);
            }
            else {
                Node *temp = start;
                for (int i = 1; i <= k - 1; i++) {
                    temp = temp->next;
                }
                node->next = temp->next;
                node->prev = temp;
                temp->next = node;
                node->next->prev = node;
                length++;
            }
        } else {
            cout << "Index out of range!" << endl;
        }
    }

    void removeStart() {
        if (length <= 1) {
            start = nullptr;
            end = nullptr;
        } else {
            Node *temp = start;
            start = start->next;
            start->prev = nullptr;
            delete temp;
        }
        length--;
    }

    void removeEnd() {
        if (length <= 1) {
            removeStart();
        } else {
            Node *temp = end;
            end = end->prev;
            end->next = nullptr;
            delete temp;
            length--;
        }
    }

    void remove(int k) {
        if (k <= length - 1) {
            if (k == 0) {
                removeStart();
            } else if (k == length - 1) {
                removeEnd();
            } else {
                Node *temp = start;
                for (int i = 1; i <= k - 1; i++) {
                    temp = temp->next;
                }
                Node *temp2 = temp->next;
                temp->next = temp->next->next;
                temp->next->prev = temp;
                delete temp2;
                length--;
            }
        } else {
            cout << "Index out of range!" << endl;
        }
    }

    Node *getNode(int k) {
        if (k <= length - 1) {
            Node *temp = start;
            for (int i = 1; i <= k; i++) {
                temp = temp->next;
            }
            return temp;
        }
        else {
            cout << "Index out of range!" << endl;
        }
    }

    void showAll() {
        Node* temp = start;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    DoublyLinkedList dll;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dll.insertEnd(dll.createNode(x));
    }
    
    dll.showAll();
}