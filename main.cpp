#include "foo.hpp"

int main() {

        foo f;
        f.a1 = 2.3;

        Serializer<foo, int> s;
        serializer_desc(s);
        int a = 1;
        s.write(f, &a);
}
