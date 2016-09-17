#include "cardarraylist.h"
#include "naipe.h"

CardArrayList::CardArrayList(int pmax)
{
    elements=new Naipe*[pmax];
    size = 0;
    max = pmax;
    pos = 0;
}

CardArrayList::CardArrayList()
{
    elements=new Naipe*[1024];
    size = 0;
    max = 1024;
    pos = 0;
}


void CardArrayList::append(Naipe* naipe)
{
    elements[size]=naipe;
    size++;
}

int CardArrayList::getPos()
{
    return pos;
}

Naipe* CardArrayList::getValue()
{
    return elements[pos];
}

Naipe* CardArrayList::getValue(int x)
{
    return elements[x];
}

void CardArrayList::setValue(int x, Naipe *value)
{
    elements[x] = value;
}

int CardArrayList::findElement(Naipe *value)
{
    for (int i = 0; i < size; i++)
    {
        //qDebug() << elements[i];
        /*
        qDebug() << QString("0x%1").arg((quintptr)elements[i],
                                        QT_POINTER_SIZE * 2, 16, QChar('0'));
        qDebug() << QString("0x%1").arg((quintptr)value,
                                        QT_POINTER_SIZE * 2, 16, QChar('0'));
                                        */
        if (elements[i] == value)
        {
            return i;
        }
    }
    return -1;
}


int CardArrayList::getSize()
{
    return size;
}

void CardArrayList::gotoStart()
{
    pos = 0;
}

void CardArrayList::gotoEnd(){
    pos = size;
}

void CardArrayList::gotoPos(int x){
    pos = x;
}

void CardArrayList::next(){
    pos++;
}

void CardArrayList::previous(){
    pos--;
}

Naipe* CardArrayList::remove()
{
    Naipe* deletedElement=elements[pos];
    for (int i=pos; i<size; i++){
        elements[i]=elements[i+1];
    }
    size--;
    return (deletedElement);
}

Naipe *CardArrayList::remove(int index)
{
    Naipe* deletedElement=elements[index];
    for (int i=index; i<size; i++){
        elements[i]=elements[i+1];
    }
    size--;
    return (deletedElement);
}


void CardArrayList::clear()
{
    size=0;
    pos=0;
    delete[]elements;
}

int CardArrayList::getMax() const
{
    return max;
}

CardArrayList::~CardArrayList()
{
    size=0;
    pos=0;
    delete[]elements;
}
