//Name-Shivang Agrawal
//Roll No.-21CS30048
#include "rdb.h"
//Function to search for a string in list 
int searchj(list<string> p, string x)
{
    auto it = p.begin();
    for (; it != p.end(); it++)
    {
        if ((*it) == x)
            return 1;
    }
    return 0;
}
//Natural Join function
Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr)
{
    auto it = joinattr.begin();
    Relation *T = new Relation(*R2);
    list<string> proj;
    //Renaming the common attribute names in R2
    for (; it != joinattr.end(); it++)
    {
        T = difference(T, *it, (*it) + (*it));
        proj.push_back((*it) + (*it));
       // T->print_relation();
    }
    // Taking the cartesian Product
    Relation *P = catersianproduct(R1, T);
   //Construction of DNFformula for selection
    DNFformula *f = new DNFformula;
    auto itr = T->recs.begin();
    for (; itr != T->recs.end(); itr++)
    {
        list<tuple<string, char, Attr *>> li;
        for (it = joinattr.begin(); it != joinattr.end(); it++)
        {
            string s = *it;
            char c = '=';
            int p = find(T->attrnames.begin(), T->attrnames.end(), (*it) + (*it)) - T->attrnames.begin();
            Attr *x = (*itr)->attrptr[p];
            li.push_back(make_tuple(s, c, x));
            li.push_back(make_tuple(s + (*it), c, x));
        }
        f->ops.push_back(li);
    }
    //Taking the selection of records
    P = union_relation(P, f);
    list<string> projatt;
    for (int i = 0; i < P->attrnames.size(); i++)
    {
        if (!searchj(proj, P->attrnames[i]))
            projatt.push_back(P->attrnames[i]);
    }
    //Taking the projection to remove the 2nd occurence of common attributes
    P = projection(P, projatt);
    return P;
}
