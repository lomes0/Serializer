#ifndef __FOO__
#define __FOO__

#include "./serizliaer.hpp"

/*
 * 1. __attribute__((__packed__))
 * 2. changing the actual, not just making a copy and changing the copy.
 */
struct foo {

        int a1;

} __attribute__((packed));

template <>
void serializer_desc(Serializer<foo, int>& s) {

        s.in<decltype(foo::a1)>("a1");
}

#endif // __FOO__
