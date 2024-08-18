#include <iostream>
using namespace std;

struct queue
{
    char value;
    struct queue *next;
};
struct queue *f = NULL;
struct queue *r = NULL;

int is_empty1()
{
    if (f == r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct queue *enqueue(struct queue *head)
{
    char value;
    if (head == NULL)
    {
        struct queue *newnode;
        newnode = (struct queue *)malloc(sizeof(struct queue));
        newnode->next = NULL;
        cout << "\nEnter value";
        cin >> value;
        newnode->value = value;
        r = newnode;
        return newnode;
    }

    struct queue *newnode;
    newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->next = NULL;
    cout << "\nEnter value";
    cin >> value;
    newnode->value = value;
    r->next = newnode;
    r = newnode;
    return head;
}
struct queue *dequeue(struct queue *head)
{
    if (f == r)
    {
        cout << "\nthe queue is empty";
        return NULL;
    }
    else
    {
        struct queue *temp;
        temp = head;
        f = head;
        head = head->next;

        return head;
    }
}
void display(struct queue *head)
{
    struct queue *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->value;
        cout << "  ";
        ptr = ptr->next;
    }
}
int main()
{
    struct queue *head;
    head = NULL;
    int ch = 7;

    cout << "\n1)enqueue  2)dequeue  3) empty 4)display";

    do
    {
        cout << "\nEnter choice  : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            head = enqueue(head);
            break;
        }
        case 2:
        {
            head = dequeue(head);
            break;
        }
        case 3:
        {
            int ans;
            ans = is_empty1();
            if (ans)
            {
                cout << "\nQueue is empty";
            }
            else
            {
                cout << "\nQueue is not empty";
            }
            break;
        }
        case 4:
        {
            display(head);
            break;
        }
        default:
        {
            cout << "\nwrong choice";
            break;
        }
        }
    } while (ch < 5);

    return 0;
}