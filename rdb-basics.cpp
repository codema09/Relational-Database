//Name-Hrushikesh Reddy
//Roll number-21CS30028
#include "rdb.h"
//Checking schema is same or not
int check_attributes(Relation *R1, Relation *R2)
{
    if (R1->natttr != R2->natttr)
        return 0;
    for (int i = 0; i < R1->natttr; i++)
    {
        if (R1->attrnames[i] != R2->attrnames[i])
            return 0;
    }
    return 1;
}
//Checking if record is present in relation
int check_Record(Relation *R, Record *r)
{
    auto it = R->recs.begin();
    for (int i = 0; i < R->nrecs; i++, it++)
    {
        for (int j = 0; j < R->natttr; j++)
        {
            // cout<<i<<" "<<j<<endl;

            if ((*it)->attrptr[j]->gettype() == "string" && *(dynamic_cast<StringAttribute *>((*it)->attrptr[j])) != *(r->attrptr[j]))
                break;
            else if ((*it)->attrptr[j]->gettype() == "int" && (*dynamic_cast<IntegerAttribute *>((*it)->attrptr[j])) != *(r->attrptr[j]))
                break;
            else if ((*it)->attrptr[j]->gettype() == "float" && *(dynamic_cast<FloatAttribute *>((*it)->attrptr[j])) != *(r->attrptr[j]))
                break;
            else if (j == R->natttr - 1)
                return 1;
        }
    }
    return 0;
};
//Searching for a string in list
int searchb(list<string> p, string x)
{
    auto it = p.begin();
    for (; it != p.end(); it++)
    {
        if ((*it) == x)
            return 1;
    }
    return 0;
}
//Union of 2 Relations
Relation *union_relation(Relation *R1, Relation *R2)
{
    Relation *R = new Relation(*R1);
    if (check_attributes(R1, R2) == 0)
    {
        cout << "Invalid Union as attribute names are different" << endl;
        return NULL;
    }
    else
    {
        auto it = R2->recs.begin();
        for (; it != R2->recs.end(); it++)
        {
            if (check_Record(R, *it) == 0)
            {
                (R->nrecs)++;
                Record *r = new Record(**it);
                R->recs.push_back(r);
            }
        }
    }
    return R;
}
//Difference of 2 Relations
Relation *difference(Relation *R1, Relation *R2)
{
    if (check_attributes(R1, R2) == 0)
    {
        cout << "Invalid Difference as attribute names are different" << endl;
        return NULL;
    }
    Relation *R = new Relation(0);
    R->natttr = R1->natttr;
    for (int i = 0; i < R1->natttr; i++)
    {
        R->attrnames.push_back(R1->attrnames[i]);
        R->type.push_back(R1->type[i]);
    }
    R->nrecs = 0;
    for (auto it = R1->recs.begin(); it != R1->recs.end(); it++)
    {
        if (!check_Record(R2, *it))
        {
            (R->nrecs)++;
            Record *r = new Record(**it);
            R->recs.push_back(r);
        }
    }
    return R;
}
//Cartesian Product of 2 Relations
Relation *catersianproduct(Relation *R1, Relation *R2)
{
    Relation *R = new Relation(0);
    R->natttr = R1->natttr + R2->natttr;
    int i;
    for (i = 0; i < R1->natttr; i++)
        R->attrnames.push_back(R1->attrnames[i]);
    for (i = 0; i < R2->natttr; i++)
        R->attrnames.push_back(R2->attrnames[i]);
    auto it1 = R1->recs.begin();
    auto it2 = R2->recs.begin();
    for (; it1 != R1->recs.end(); it1++)
    {
        for (it2 = R2->recs.begin(); it2 != R2->recs.end(); it2++)
        {
            (R->nrecs)++;
            Record *r = new Record(**it1, **it2);
            R->recs.push_back(r);
        }
    }
    return R;
}
//Projection of Relation according to given attribute names
Relation *projection(Relation *R1, list<string> projectattrs)
{
    Relation *R = new Relation(0);
    auto it = R1->recs.begin();
    auto itl = projectattrs.begin();
    R->natttr = 0;
    R->nrecs = 0;
    for (; itl != projectattrs.end(); itl++)
    {
        (R->natttr)++;
        R->attrnames.push_back(*itl);
    }
    for (; it != R1->recs.end(); it++)
    {
        // cout<<"0"<<endl;
        Record *r = new Record;

        for (int i = 0; i < (*it)->attrptr.size(); i++)
        {
            // cout<<"-1"<<endl;
            if (searchb(projectattrs, R1->attrnames[i]))
            {
                // cout<<"1"<<endl;
                if (it == R1->recs.begin())
                    R->type.push_back((*it)->attrptr[i]->gettype());
                string t = (*it)->attrptr[i]->gettype();
                if (t == "int")
                {
                    int x;
                    x = dynamic_cast<IntegerAttribute *>((*it)->attrptr[i])->get_val();
                    IntegerAttribute *a = new IntegerAttribute(x);
                    r->attrptr.push_back(/*dynamic_cast<IntegerAttribute*>*/ (a));
                    // cout << attrptr.size();
                }
                else if (t == "string")
                {
                    string x;
                    x = dynamic_cast<StringAttribute *>((*it)->attrptr[i])->get_val();
                    StringAttribute *a = new StringAttribute(x);
                    r->attrptr.push_back(/*dynamic_cast<StringAttribute*>*/ (a));
                    // cout << attrptr.size();
                }
                else if (t == "float")
                {
                    float x;
                    x = dynamic_cast<FloatAttribute *>((*it)->attrptr[i])->get_val();
                    FloatAttribute *a = new FloatAttribute(x);
                    r->attrptr.push_back(/*dynamic_cast<FloatAttribute*>*/ (a));
                    // cout << attrptr.size();
                }
            }
        }
        if (it == R1->recs.begin())
        {
            R->recs.push_back(r);
            (R->nrecs)++;
        }
        if (it != R1->recs.begin() && !check_Record(R, r))
        {
            R->recs.push_back(r);
            (R->nrecs)++;
        }
    }
    return R;
}
//Renaing a attribute name
Relation *difference(Relation *R1, string s1, string s2)
{
    Relation *R = new Relation(*R1);
    for (int i = 0; i < R->natttr; i++)
    {
        if (R->attrnames[i] == s1)
            R->attrnames[i] = s2;
    }
    return R;
}
//Selection of records from a Relation
Relation *union_relation(Relation *R1, DNFformula *f)
{
    Relation *R = new Relation(0);
    R->natttr = R1->natttr;
    R->nrecs = 0;
    for (int i = 0; i < R->natttr; i++)
        R->attrnames.push_back(R1->attrnames[i]);
    auto itr = R1->recs.begin();
    for (; itr != R1->recs.end(); itr++)
    {
        auto it1 = f->ops.begin();
        for (; it1 != f->ops.end(); it1++)
        {
            auto it2 = it1->begin();
            int flag = 1;
            for (; it2 != it1->end(); it2++)
            {
                auto k = find(R->attrnames.begin(), R->attrnames.end(), get<0>(*it2));
                int p = k - R->attrnames.begin();
                if (get<1>(*it2) == '=')
                {
                    // auto a=getp((*itr)->attrptr[p]->gettype(),(*itr)->attrptr[p]);
                    string t = (*itr)->attrptr[p]->gettype();
                    if (t == "int")
                    {
                        if ((dynamic_cast<IntegerAttribute &>(*((*itr)->attrptr[p]))) != (*(get<2>(*it2))))
                        {
                            flag = 0;
                            break;
                        }
                    }
                    else if (t == "string")
                    {
                        if ((dynamic_cast<StringAttribute &>(*((*itr)->attrptr[p]))) != (*(get<2>(*it2))))
                        {
                            flag = 0;
                            break;
                        }
                    }
                    else if (t == "float")
                    {
                        if ((dynamic_cast<FloatAttribute &>(*((*itr)->attrptr[p]))) != (*(get<2>(*it2))))
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (get<1>(*it2) == '>')
                {
                    // auto a=getp((*itr)->attrptr[p]->gettype(),(*itr)->attrptr[p]);
                    string t = (*itr)->attrptr[p]->gettype();
                    if (t == "int")
                    {
                        if (!((dynamic_cast<IntegerAttribute &>(*((*itr)->attrptr[p]))) > (*(get<2>(*it2)))))
                        {
                            flag = 0;
                            break;
                        }
                    }
                    else if (t == "string")
                    {
                        if (!((dynamic_cast<StringAttribute &>(*((*itr)->attrptr[p]))) > (*(get<2>(*it2)))))
                        {
                            flag = 0;
                            break;
                        }
                    }
                    else if (t == "float")
                    {
                        if (!((dynamic_cast<FloatAttribute &>(*((*itr)->attrptr[p]))) > (*(get<2>(*it2)))))
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (get<1>(*it2) == '<')
                {
                    // auto a=getp((*itr)->attrptr[p]->gettype(),(*itr)->attrptr[p]);
                    string t = (*itr)->attrptr[p]->gettype();
                    if (t == "int")
                    {
                        if (!((dynamic_cast<IntegerAttribute &>(*((*itr)->attrptr[p]))) < (*(get<2>(*it2)))))
                        {
                            flag = 0;
                            break;
                        }
                    }
                    else if (t == "string")
                    {
                        if (!((dynamic_cast<StringAttribute &>(*((*itr)->attrptr[p]))) < (*(get<2>(*it2)))))
                        {
                            flag = 0;
                            break;
                        }
                    }
                    else if (t == "float")
                    {
                        if (!((dynamic_cast<FloatAttribute &>(*((*itr)->attrptr[p]))) < (*(get<2>(*it2)))))
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
            if (flag)
            {
                Record *r = new Record(**itr);
                R->recs.push_back(r);
                R->nrecs++;
                break;
            }
        }
    }
    // cout << "1" << endl;
    return R;
}
