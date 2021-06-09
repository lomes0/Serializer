#ifndef __SERIALIZER__
#define __SERIALIZER__

#include <vector>
#include <iostream>
#include <list>

#include "register.hpp"

using namespace std;

template <typename F, typename I>
void write(F* f, void** p, const char* n) {

        cout << *((I*)*p) << endl;

        I** t = (I**)p;
        (*t)++;
}

template <typename T, typename F>
class Serializer {

        typedef void(*write_op_ptr)(F* f, void** p, const char*);

        template <typename A, typename B, typename C>
        friend struct Register;

        public:
        template <typename I>        
        void in(const char*);

        void write(const T& obj, F* file) const {

                void* ptr = (void*)&obj;
                void** p = &ptr;

                for (auto op : m_writes) {

                        op(file, p, "a");
                }
        }

        private:
        list<write_op_ptr> m_writes;
        list<const char*> m_names;
};

template <typename T, typename F>
void serializer_desc(Serializer<T, F>& s);

template <typename T, typename F>
template <typename I>
void Serializer<T, F>::in(const char* n) {

        Register<T, F, I> r;
        r.in(this, n);
}

#endif // __SERIALIZER__
