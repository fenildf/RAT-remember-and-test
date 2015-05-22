//:Word.cpp
#include "Word.h"
#include "Entry.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
using namespace std;
Word::Word ()
{
    quan0=EntrySize();
    quan1=EntrySize();
    quan2=EntrySize();
}
void Word::Quanchange0(){
    int lin=0;
    for(int i=0; i<EntrySize(); i++){
        lin+=entries[i]->test->quan0;
    }
    quan0=lin;
}
void Word::Quanchange1(){
    int lin=0;
    for(int i=0; i<EntrySize(); i++){
        lin+=entries[i]->test->quan1;
    }
    quan1=lin;
}
void Word::Quanchange2(){
    int lin=0;
    for(int i=0; i<EntrySize(); i++){
        lin+=entries[i]->test->quan2;
    }
    quan2=lin;
}
ostream& operator<< (ostream& out, Word& w)
{
    out << "_____________________________________________" << endl;
    out << w.spell << ":" << endl;
    for (int i = 0; i < w.entries.size(); ++i)
    {
        out << "_____________________________________________" << endl;
        out << "entry " << i + 1 << ":"<< endl;
        out << *(w.entries[i]) << endl;
    }
    return out;
    
}
bool Word::Familiar()
{
    if (!haveRecited)
        return false;
    if (kill)
        return true;
    int correct = 0;
    int allNum = 0;
    for (int i = check.size() - 1; i >= 0; i--)
    {
        allNum++;
        if (check[i])
            correct++;
    }
    return double(correct) / allNum > 0.6;
}