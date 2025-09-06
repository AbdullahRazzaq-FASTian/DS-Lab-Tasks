#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
};

class LL
{
public:
    Node *head;
    Node *tail;
    int size;
    Node *cycleStart; // Storing start of cycle will ease me traversing in CLL and i can avoid using frequency array to avoid infinite loop

    LL(Node *head) : head(head), tail(nullptr), size(0), cycleStart(nullptr)
    {
        // Here i have used visited aray once cuz i want to initialize the cycleStart variable. Also assuming the nodes to be distinct for the sake of simplicity
        int visited[1000] = {0};
        Node *cur = head;
        while (cur)
        {
            if (visited[cur->val] != 0)
            {
                cycleStart = cur;
                break;
            }
            visited[cur->val]++;
            size++;
            tail = cur;
            cur = cur->next;
        }
    }
    void print()
    {
        Node *cur = head;
        bool cycleHit = false;
        while (cur)
        {
            if (cur == cycleStart)
            {
                if (cycleHit)
                { // when visiting cycleStart again then thats the point of repititon stop there to avoid infinte revisiting
                    cout << "(back to " << cycleStart->val << ")" << endl;
                    return;
                }
                cycleHit = true;
            }
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    ~LL()
    {
        Node *cur = head;
        bool cycleHit = false;
        // breaking cycle before deleting whole list
        while (cur)
        {
            if (cur == cycleStart)
            {
                if (cycleHit)
                    break;
                cycleHit = true;
            }
            Node *temp = cur->next;
            delete cur;
            cur = temp;
        }
        head = tail = nullptr;
    }
    void addNode(size_t k, int val)
    {
        if (k > size)
            return;
        Node *newNode = new Node(val);
        if (k == 0)
        {
            if (size == 0)
            {
                head = tail = newNode;
            }
            else if (head == cycleStart)
            {
                newNode->next = head;
                tail->next = cycleStart = head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }
        else if (k == size)
        {
            if (tail->next)
            {
                newNode->next = tail->next;
                tail = tail->next = newNode;
            }
            else
            {
                tail = tail->next = newNode;
            }
        }
        else
        {
            Node *cur = head;
            for (size_t i = 1; i < k; i++)
                cur = cur->next;
            newNode->next = cur->next;
            cur->next = newNode;
        }
        size++;
    }
    void deleteNode(int val)
    {
        if (!head)
            return;
        else if (head->val == val)
        {
            if (head == tail)
            {
                delete head;
                head = tail = cycleStart = nullptr;
            }
            else
            {
                Node *temp = head;
                head = head->next;
                if (cycleStart == temp)
                    tail->next = cycleStart = head;
                delete temp;
            }
        }
        else
        {
            Node *cur = head;
            bool cycleHit = false;
            while (cur->next)
            {
                if(cur->next == cycleStart && !cycleHit)
                    cycleHit = true;
                else if(cur->next == cycleStart && cycleHit)
                    break;

                if (cur->next->val == val)
                {
                    Node *temp = cur->next;
                    cur->next = temp->next;

                    if (temp == tail)
                        tail = cur;
                    else if (temp == cycleStart)
                        tail->next = cycleStart = cur->next; // Assigning successor as new cycleStart
                    delete temp;
                    return;
                }
                cur = cur->next;
            }
        }
        size--;
    }
};

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // 1->2->3->4->5->3

    LL list(head);
    cout << "\n Original List\n";
    list.print();

    size_t pos = 3;

    list.addNode(0, 0);     // Insert at begining
    list.addNode(pos, 7);     // Insert at position
    list.addNode(6, 6);     // Insert at end

    cout << "\n Adding new elements\n";
    list.print();
    
    cout << "\n Deleting an elements\n";
    list.deleteNode(3);
    list.print();
    nl;
    return 0;
}
