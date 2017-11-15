// Test private inheritance and polymophism.
#include <iostream>
using namespace std;

class A
{
public:
    A();
    virtual ~A();
    virtual void foo();
    int a1;
protected:
    int a2;
private:
    int a3;
};

class B : protected A
{
public:
    B();
    virtual ~B();
    virtual void foo();
    int b1;
protected:
    int b2;
private:
    int b3;
};

class C : private A
{
public:
    C();
    virtual ~C();
    virtual void foo();
    int c1;
protected:
    int c2;
private:
    int c3;
};

class D : public B
{
public:
    D();
    virtual ~D();
    virtual void foo();
    int d1;
protected:
    int d2;
private:
    int d3;
};

class E : public C
{
public:
    E();
    virtual ~E();
    virtual void foo();
    int e1;
protected:
    int e2;
private:
    int e3;
};

A::A() : a1(0), a2(1), a3(2)
{
    // cout << "ctor A" << endl;
}

A::~A()
{
    // cout << "dtor A" << endl;
}

void A::foo()
{
    cout << "foo A:"
         << " a1=" << a1
         << " a2=" << a2
         << " a3=" << a3
         << endl;
}

B::B() : b1(3), b2(4), b3(5)
{
    // cout << "ctor B" << endl;
}

B::~B()
{
    // cout << "dtor B" << endl;
}

void B::foo()
{
    cout << "foo B:"
         << " a1=" << a1
         << " a2=" << a2
//       << " a3=" << a3   // error: 'int A::a3' is private within this context
         << " b1=" << b1
         << " b2=" << b2
         << " b3=" << b3
         << endl;
}

C::C() : A(), c1(6), c2(7), c3(8)
{
    // cout << "ctor C" << endl;
}

C::~C()
{
    // cout << "dtor C" << endl;
}

void C::foo()
{
    cout << "foo C:"
         << " a1=" << a1
         << " a2=" << a2
//       << " a3=" << a3 // error: 'int A::a3' is private within this context
         << " c1=" << c1
         << " c2=" << c2
         << " c3=" << c3
         << endl;
}

D::D() : B(), d1(9), d2(10), d3(11)
{
    // cout << "ctor D" << endl;
}

D::~D()
{
    // cout << "dtor D" << endl;
}

void D::foo()
{
    cout << "foo D:"
         << " a1=" << a1
         << " a2=" << a2
         // << " a3=" << a3 // error: 'int A::a3' is private within this context
         << " b1=" << b1
         << " b2=" << b2
         // << " b3=" << b3 // error: 'int B::b3' is private within this context
         << " d1=" << d1
         << " d2=" << d2
         << " d3=" << d3
         << endl;
}

E::E() : C(), e1(12), e2(13), e3(14)
{
    // cout << "ctor E" << endl;
}

E::~E()
{
    // cout << "dtor E" << endl;
}

void E::foo()
{
    cout << "foo E:"
//       << " a1=" << a1 // error: 'int A::a1' is inaccessible
//       << " a2=" << a2 // error: 'int A::a2' is protected
//       << " a3=" << a3 // error: 'int A::a3' is private
         << " c1=" << c1
         << " c2=" << c2
//       << " c3=" << c3 // error: 'int C::c3' is private
         << " e1=" << e1
         << " e2=" << e2
         << " e3=" << e3
         << endl;
}

int main()
{
    A a;
    B b;
    C c;
    D d;
    E e;
    A* pa;
    B* pb;
    C* pc;

    pa = &a;
    pa->foo();

    // pa = &b; // error: ‘A’ is an inaccessible base of ‘B’
    // pa->foo();

    // pa = &c; // error: ‘A’ is an inaccessible base of ‘C’
    // pa->foo();

    // pa = &d; // error: ‘A’ is an inaccessible base of ‘D’
    // pa->foo();

    cout << "a.a1=" << a.a1
        // << a.a2 << a.a3 // inaccessible within this context
         << endl;

    // cout << b.a1 << endl; // inaccessible within this context
    cout << "d.b1=" << d.b1 << endl;

//  cout << e.a1 << endl;       // inaccessible
    cout << "e.c1=" << e.c1
//       << "e.c2=" << e.c2     // protected
         << endl;
    cout << "e.e1=" << e.e1 << endl;

    pb = &d;
    pb->foo();

    pc = &e;
    pc->foo();

    return 0;
}
