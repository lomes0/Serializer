#ifndef __RAW_TYPES__
#define __RAW_TYPES__

template <typename T, typename F>
class Serializer;

template <typename F, typename I>
void write(F*, void**, const char*);

template <typename T, typename F, typename I>
struct Register {

        public:
        void in(Serializer<T, F>& s, const char*);
};

template <typename T, typename F>
struct Register<T, F, int> {

        public:
        void in(Serializer<T, F>* t, const char* n) {

                t->m_writes.push_back(&write<F, int>); 
        }
};


#endif // __RAW_TYPES__
