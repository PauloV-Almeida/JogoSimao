#ifndef LIST_H
#define LIST_H

namespace Lists
{
    template<class TYPE>
    class List
    {
    public:
        List() :
            pfirst(NULL),
            size(0)
        {}
        ~List()
        {
            clear();
            pfirst = NULL;
        }

        template <class TE>
        class Element
        {
        private:
            TE* data;
            Element<TE>* pnext;
        public:
            Element() : data(NULL), pnext(NULL)
            {}
            ~Element()
            {
                if (data)
                {
                    delete data;
                }
                data = NULL;
            }
            TE* get_data() const { return data; }
            Element<TE>* get_next() const { return pnext; }

            void set_data(TE* dt) { data = dt; }
            void set_next(Element<TE>* next) { pnext = next; }
        };

        template <class TE>
        class Iterator
        {
        private:
            Element<TE>* current;
        public:
            Iterator(Element<TE>* c = NULL) :
                current(c) {}
            ~Iterator() {}

            Iterator& operator++()
            {
                current = current->get_next();
                return *this;
            }
            Iterator operator++(int)
            {
                Iterator temp = *this;
                current = current->get_next();
                return temp;
            }
            bool operator==(const Iterator& other) const
            {
                return current == other.current;
            }

            bool operator!=(const Iterator& other) const
            {
                return !(*this == other);
            }
            void operator=(const Iterator& other)
            {
                current = other.current;
            }
            TE* operator*() const
            {
                return current->get_data();
            }
        };

    private:
        Element<TYPE>* pfirst;
        int size;

    public:
        Iterator<TYPE> get_first() const { return Iterator<TYPE>(pfirst); }
        void clear()
        {
            Element<TYPE>* aux = NULL;
            while (pfirst)
            {
                aux = pfirst;
                pfirst = pfirst->get_next();
                if (aux)
                    delete aux;
            }
            size = 0;
            pfirst = NULL;
        }
        int get_size() const
        {
            return size;
        }
        void push(TYPE* elem)
        {
            if (!elem)
                return;
            Element<TYPE>* aux = new Element<TYPE>();
            if (aux)
            {
                aux->set_data(elem);
                aux->set_next(pfirst);
                pfirst = aux;
                size++;
            }
        }
    };
}

#endif