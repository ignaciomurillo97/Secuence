#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "naipe.h"
#include <QDebug>

class CardArrayList
{
    public:
        CardArrayList(int pMax);
        CardArrayList();
        virtual ~CardArrayList();
        Naipe* getValue();
        Naipe* getValue(int x);
        void setValue(int x, Naipe* value);
        int findElement(Naipe * value);
        int getPos();
        int getSize();
        void gotoStart();
        void gotoEnd();
        void gotoPos(int pos);
        void previous();
        void next();
        void append(Naipe* pElement);
        void insert(Naipe* pElement);
        Naipe* remove();
        Naipe* remove(int index);
        void print();
        void clear();
        int getMax() const;

protected:
        int size;
        int max;
        int pos;
    private:

        Naipe** elements;
};

#endif // ARRAYLIST_H
