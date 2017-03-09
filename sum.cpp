#include <iostream>
using namespace std;
int n,num;
class A {
    public:
        A() { mData = -1; mNext = NULL; }
        ~A() {}
        int data() { return mData; }
        void setData(int data) { mData = data; }
        A* next() { return mNext; }
        void setNext(A* next) { mNext = next; }
    private:
        int mData;
        A* mNext;
};

class B{
    public:
        B() { mHead = NULL; }

        ~B() {}

        A* head() { return mHead; }

        void create(int data) {
            A* tmp = new A();
            tmp->setData(data);
            if ( mHead == NULL )
                    mHead = tmp;
            else {
                A* ptr = mHead;
                while ( ptr->next() != NULL ) {
                        ptr = ptr->next();
                }
                ptr->setNext(tmp);
            }
        }

        void zero(int data) {
            A* tmp = new A();
            tmp->setData(data);
            tmp->setNext(mHead);
            mHead = tmp;
        }

        void show() {
            A* ptr = mHead;
            while ( ptr != NULL ) {
                cout << ptr->data();
                ptr = ptr->next();
            }
            cout<< endl;
        }

        int length() {
            A* ptr = mHead;
            int count = 0;
            while ( ptr != NULL ) {
                count++;
                ptr = ptr->next();
            }
            return count;
        }

    private:
        A* mHead;
};

int addnum(A* node1, A* node2, B* l3) {
    if ( node1 == NULL ) return 0;
    int carry = addnum(node1->next(), node2->next(), l3);
    int val = carry + node1->data() + node2->data();
    int carry1 = val / 10;
    int nodeval = val % 10;

    l3->zero(nodeval);

    return carry1;
}

void add(B* l1, B* l2, B* l3) {
    int length1 = l1->length();
    int length2 = l2->length();
    int diff = length1 - length2;
    if ( length1 > length2 ) {
        while ( diff > 0 ) {
            l2->zero(0);
            diff--;
        }
    }
    else if ( length2 > length1 ) {
        while ( diff > 0 ) {
            l1->zero(0);
            diff--;
        }
    }

   

    int carry = addnum(l1->head(), l2->head(), l3);
    if ( carry ) {
       l3->zero(carry);
    }
}

int main() {
    B* l1 = new B();
    cout<<"enter size of numbers:";
    cin>>n;
    cout<<"enter 1st num\n";
    for(int i=0;i<n;i++)
    {cin>>num; 
    l1->create(num);
}
    
    B* l2 = new B();
    cout<<"enter 2d num\n";
    for(int i=0;i<n;i++)
    {cin>>num;
    l2->create(num);
}

    cout << "numbers\n" << endl;
    l1->show();
    l2->show();

    B* l3 = new B();
    add(l1, l2, l3);

    cout << "Summed up list\n" << endl;
    l3->show();

    delete l1;
    delete l2;
}
