#include "HDio.hpp"

void defineTemplates() {
    int i;
    long l;
    float f;
    double d;
    char c;
    const char* s; // string
    char* t;       // string - modifiable

    // print() -----------------------------------------------------------------

    print(i);
    print(l);
    print(f);
    print(d);
    print(c);
    print(s);
    print(t);

    print(i,i);
    print(l,i);
    print(f,i);
    print(d,i);
    print(c,i);
    print(s,i);
    print(t,i);

    print(i,l);
    print(l,l);
    print(f,l);
    print(d,l);
    print(c,l);
    print(s,l);
    print(t,l);

    print(i,f);
    print(l,f);
    print(f,f);
    print(d,f);
    print(c,f);
    print(s,f);
    print(t,f);

    print(i,d);
    print(l,d);
    print(f,d);
    print(d,d);
    print(c,d);
    print(s,d);
    print(t,d);

    print(i,c);
    print(l,c);
    print(f,c);
    print(d,c);
    print(c,c);
    print(s,c);
    print(t,c);

    print(i,s);
    print(l,s);
    print(f,s);
    print(d,s);
    print(c,s);
    print(s,s);
    print(t,s);

    print(i,t);
    print(l,t);
    print(f,t);
    print(d,t);
    print(c,t);
    print(s,t);
    print(t,t);

    print(s,s,s);
    print(s,s,s,s);
    print(s,s,s,s,s);

    // println() ---------------------------------------------------------------

    println(i);
    println(l);
    println(f);
    println(d);
    println(c);
    println(s);
    println(t);

    println(i,i);
    println(l,i);
    println(f,i);
    println(d,i);
    println(c,i);
    println(s,i);
    println(t,i);

    println(i,l);
    println(l,l);
    println(f,l);
    println(d,l);
    println(c,l);
    println(s,l);
    println(t,l);

    println(i,f);
    println(l,f);
    println(f,f);
    println(d,f);
    println(c,f);
    println(s,f);
    println(t,f);

    println(i,d);
    println(l,d);
    println(f,d);
    println(d,d);
    println(c,d);
    println(s,d);
    println(t,d);

    println(i,c);
    println(l,c);
    println(f,c);
    println(d,c);
    println(c,c);
    println(s,c);
    println(t,c);

    println(i,s);
    println(l,s);
    println(f,s);
    println(d,s);
    println(c,s);
    println(s,s);
    println(t,s);

    println(i,t);
    println(l,t);
    println(f,t);
    println(d,t);
    println(c,t);
    println(s,t);
    println(t,t);

    println(s,s,s);
    println(s,s,s,s);
    println(s,s,s,s,s);

    // getUserInput() ----------------------------------------------------------

    getUserInput<int>();
    getUserInput<long>();
    getUserInput<float>();
    getUserInput<double>();
    getUserInput<char>();

    // askForInput() -----------------------------------------------------------

    askForInput<int>(s);
    askForInput<long>(s);
    askForInput<float>(s);
    askForInput<double>(s);
    askForInput<char>(s);
}