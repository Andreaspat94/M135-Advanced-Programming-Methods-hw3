#include <iostream>

using namespace std;

struct B {
public:
    int dum_b = 30;

    virtual void foo_B() {
        cout << "B.foo()" << endl;
    };
};

struct C {
public:
    int dum_c = 6;

    virtual void foo_C() {
        cout << "C.foo()" << endl;
    };
};

struct A : public B, C {
public:
    int dum_a = 14;
    int dum_a2 = 15;

    virtual void foo_A() {
        cout << "A.foo()" << endl;
    };
};

int main() {
    A *a = new A();
    cout << "Size of A in system " << sizeof(*a) << " bytes" << endl;
    cout << "Size of a pointer in system " << sizeof(a) << " bytes" << endl;
    cout << "Size of an integer in system " << sizeof(a->dum_a) << " bytes" << endl;

    int *ip = (int *) a;

    cout << "Printing '*(ip-1)' A's typeinfo pointer: " << *(ip - 1) << " and address: " << (ip - 1) << endl;
    cout << "Printing '*ip' (v-table pointer): " << *ip << " and address: " << ip << endl;
    cout << "Printing '*(ip+1)' value: " << *(ip + 1) << " and address: " << (ip + 1) << endl;
    cout << "Printing '*(ip+2)' value: " << *(ip + 2) << " and address: " << (ip + 2) << endl;
    cout << "Printing '*(ip+3)' value: " << *(ip + 3) << " and address: " << (ip + 3) << endl;
    cout << "Printing '*(ip+4)' (v-table pointer): " << *(ip + 4) << " and address: " << (ip + 4) << endl;
    cout << "Printing '*(ip+5)' value: " << *(ip + 5) << " and address: " << (ip + 5) << endl;
    cout << "Printing '*(ip+6)' value: " << *(ip + 6) << " and address: " << (ip + 6) << endl;
    cout << "Printing '*(ip+7)' value: " << *(ip + 7) << " and address: " << (ip + 7) << endl;
    cout << "Printing '*(ip+8)' value: " << *(ip + 8) << " and address: " << (ip + 8) << endl;
    cout << "---------------------------------" << endl;

    // address of c is equal with address ip+4 as expected
    C *c = a;
    int *c_ip = (int *) c;
    cout << "Printing '*(c_ip)' value: " << *(c_ip) << " and address: " << (c_ip) << endl;

    // try to invoke methods through the first v-table with pointers.
    //typedef void *fooptr(void *);
    //fooptr *ptr = (fooptr *) a;
    //(*ptr)(a);
}
