#include <iostream>
using namespace std;

struct D {
public:
    int dum_d = 900;
    virtual void foo_D() {
        cout << "D.foo()" << endl;
    }
};


struct B : public D {
public:
    int dum_b = 30;

    virtual void foo_B() {
        cout << "B.foo()" << endl;
    };
};

struct C : public D {
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
    cout << "Printing '*(ip+9)' value: " << *(ip + 9) << " and address: " << (ip + 9) << endl;
	cout << "----------------------" << endl;
	
    // find out where a,b,c,d are pointers
    C *c = a;
    int *c_ip = (int *) c;
    cout << "Printing '*(c_ip)' value: " << *(c_ip) << " and address: " << (c_ip) << endl;

    B *b = a;
    int *b_ip = (int *) b;
    cout << "Printing '*(b_ip)' value: " << *(b_ip) << " and address: " << (b_ip) << endl;

    D *d = b;
    int *d_ip = (int *) b;
    cout << "Printing '*(d_ip)' value: " << *(d_ip) << " and address: " << (d_ip) << endl;

    D *d2 = c;
    int *d2_ip = (int *) d2;
    cout << "Printing '*(d2_ip)' value: " << *(d2_ip) << " and address: " << (d2_ip) << endl;
    return 0;
}
