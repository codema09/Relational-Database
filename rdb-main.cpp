// Name-Shivang Agrawal
// Roll No.-21CS30048
#include "rdb.h"
// Printing Instructions according to which action will be performed
void instructions()
{
    cout << "1)To create a new relation type 1" << endl;
    cout << "2)To delete an existing relation type 2" << endl;
    cout << "3)To add a record to existing relation type 3" << endl;
    cout << "4)To print a relation type 4" << endl;
    cout << "5)To add a union of two relation type 5" << endl;
    cout << "6)To add a difference of two relation type 6" << endl;
    cout << "7)To add a cartesian product of two relation type 7" << endl;
    cout << "8)To add a selection of records from an existing relation type 8" << endl;
    cout << "9)To add a join of two relation type 9" << endl;
    cout << "10)To rename an attribute type 10" << endl;
    cout << "11)To take projection type 11" << endl;
    cout << "12)To exit type 12" << endl;
}
// Checking if size is 0
int check(int size)
{
    if (size == 0)
    {
        cout << "Cannot perform the action as there is no existing relation" << endl;
        return 1;
    }
    return 0;
}
// Checking if provided index is in range
int take_index(int size)
{
    int i;
    int c = 0;
    do
    {
        if (c)
        {
            cout << "Index not in range!!" << endl;
            cout << "Enter an index value from 1 to " << size << endl;
        }
        cin >> i;
        c++;
    } while (i <= 0 || i > size);
}
// Taking the input of comparison operator
char take_comparison()
{
    char c;
    int i = 0;
    do
    {
        cin >> c;
        if (i)
        {
            cout << "Enter a valid comparison operator" << endl;
        }
        i++;
    } while (c != '<' && c != '=' && c != '>');
    return c;
}
// Printing the attributes name
void print_all_attr(int size, Relation *R[])
{
    cout << "Printing all the attribute names of all relations" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ") ";
        R[i]->print_attr();
    }
}
int main()
{
    Relation *R[100];
    int size = 0;
    int key;
    instructions();
    while (1)
    {
        // Taking the input of key from user and performing actions according to that
        cout << "Enter the key to perform a required action" << endl
             << "(Type 0 to print instructions)" << endl;
        cin >> key;
        if (key == 12)
        {
            break;
        }
        else if (key == 0)
        {
            instructions();
        }
        else if (key == 1)
        {
            cout << "<----------------Creating a new relation------------------------->" << endl;
            R[size] = new Relation();
            R[size++]->create();
            cout << "Relation Created" << endl;
            cout << "<----------------Printing the created relation------------------------->" << endl;
            R[size - 1]->print_relation();
            cout << endl;
        }
        else if (key == 2)
        {
            if (check(size))
                continue;
            cout << "<----------------Deleting an existing relation------------------------->" << endl;
            print_all_attr(size, R);
            cout << "Enter the serial number of Relation you want to delete" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index = take_index(size) - 1;
            for (int i = index; i < size - 1; i++)
            {
                R[i] = R[i + 1];
            }
            R[size - 1] = NULL;
            size--;
            cout << "Relation at serial number " << index + 1 << " deleted" << endl;
        }
        else if (key == 3)
        {
            if (check(size))
                continue;
            cout << "<----------------Add a record to an existing relation------------------------->" << endl;
            print_all_attr(size, R);
            cout << "Enter The serial number of Relation to which you want to add a record" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index = take_index(size) - 1;
            // Record *r = new Record();
            // r->create_record(R[index]->natttr, R[index]->type, R[index]->attrnames);
            // R[index]->recs.push_back(r);
            // R[index]->nrecs++;
            R[index]->add_Record();
            cout << "<----------------Printing the edited relation------------------------->" << endl;
            R[index]->print_relation();
            cout << endl;
        }
        else if (key == 4)
        {
            if (check(size))
                continue;
            cout << "<----------------Print an existing relation------------------------->" << endl;
            print_all_attr(size, R);
            cout << "Enter The serial number of Relation to which you want to add a record" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index = take_index(size) - 1;
            R[index]->print_relation();
            cout << endl;
        }
        else if (key == 5)
        {
            if (check(size))
                continue;
            cout << "<----------------Union of two existing relations------------------------->" << endl
                 << endl;
            print_all_attr(size, R);
            cout << endl;
            cout << "Enter the serial number of first Relation" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index1 = take_index(size) - 1;
            cout << "Enter the serial number of second Relation" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index2 = take_index(size) - 1;
            R[size++] = union_relation(R[index1], R[index2]);
            if (R[size - 1] == NULL)
            {
                cout << "No new relation Created" << endl;
                size--;
            }
            else
            {
                cout << "<----------------Printing the union relation------------------------->" << endl;
                R[size - 1]->print_relation();
            }
        }
        else if (key == 6)
        {
            if (check(size))
                continue;
            cout << "<----------------Difference of two existing relations------------------------->" << endl
                 << endl;
            print_all_attr(size, R);
            cout << endl;
            cout << "Enter the serial number of first Relation" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index1 = take_index(size) - 1;
            cout << "Enter the serial number of second Relation" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index2 = take_index(size) - 1;
            R[size++] = difference(R[index1], R[index2]);
            if (R[size - 1] == NULL)
            {
                cout << "No new relation Created" << endl;
                size--;
            }
            else
            {
                cout << "<----------------Printing the difference relation------------------------->" << endl;
                R[size - 1]->print_relation();
            }
        }
        else if (key == 7)
        {
            if (check(size))
                continue;
            cout << "<----------------Cartersian of two existing relations------------------------->" << endl
                 << endl;
            ;
            print_all_attr(size, R);
            cout << endl;
            cout << "Enter the serial number of first Relation" << endl
                 << "(Range is 1 to " << size << " )";
            int index1 = take_index(size) - 1;
            cout << "Enter the serial number of second Relation" << endl
                 << "(Range is 1 to " << size << " )";
            int index2 = take_index(size) - 1;
            R[size++] = catersianproduct(R[index1], R[index2]);
            if (R[size - 1] == NULL)
            {
                cout << "No new relation Created" << endl;
                size--;
            }
            else
            {
                cout << "<----------------Printing the Cartesian Product relation------------------------->" << endl;
                R[size - 1]->print_relation();
            }
        }
        else if (key == 8)
        {
            if (check(size))
                continue;
            cout << "<----------------Selection of records from an existing relations------------------------->" << endl;
            print_all_attr(size, R);
            cout << endl;
            cout << "Enter the serial number of  Relation" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            ;
            int index = take_index(size) - 1;
            DNFformula *f = new DNFformula;
            int nl, nll;
            string s;
            char a;
            string type;
            cout << "Enter the number of lists of lists of tupels" << endl;
            cin >> nl;
            for (int i = 0; i < nl; i++)
            {
                cout << "Enter the number of tupels in list" << endl;
                cin >> nll;
                list<tuple<string, char, Attr *>> li;
                for (int j = 0; j < nll; j++)
                {
                    cout << "Enter the attribute name" << endl;
                    cin >> s;
                    cout << "Enter the comparison character" << endl;
                    a = take_comparison();
                    type = R[index]->gettypebyattrname(s);
                    if (type == "\0")
                    {
                        cout << "No such attribute name" << endl;
                        continue;
                    }
                    Record r;
                    r.add_attribute(type, s);
                    li.push_back(make_tuple(s, a, r.getattr(0)));
                }
                f->ops.push_back(li);
            }
            R[size++] = union_relation(R[index], f);
            if (R[size - 1] == NULL)
            {
                cout << "No relation created" << endl;
                size--;
            }
            else
            {
                cout << "<----------------Printing the Selected relation------------------------->" << endl;
                R[size - 1]->print_relation();
            }
        }
        else if (key == 9)
        {
            if (check(size))
                continue;
            cout << "<----------------Natural Join of two existing relations------------------------->" << endl;
            print_all_attr(size, R);
            cout << endl;
            cout << "Enter the serial number of first Relation" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index1 = take_index(size) - 1;
            cout << "Enter the serial number of second Relation" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index2 = take_index(size) - 1;
            list<string> common;
            for (int i = 0; i < R[index1]->attrnames.size(); i++)
            {
                if (find(R[index2]->attrnames.begin(), R[index2]->attrnames.end(), R[index1]->attrnames[i]) != R[index2]->attrnames.end())
                    common.push_back(R[index1]->attrnames[i]);
            }
            if (common.empty())
            {
                cout << "There is no common attribute name so no join" << endl;
                continue;
            }
            R[size++] = naturaljoin(R[index1], R[index2], common);
            if (R[size - 1] == NULL)
            {
                cout << "No join created" << endl;
                size--;
            }
            else
            {
                cout << "<----------------Printing the joined relation------------------------->" << endl;
                R[size - 1]->print_relation();
            }
        }
        else if (key == 10)
        {
            cout << "<----------------------------Renaming an attribute in Relation----------------->" << endl;
            print_all_attr(size, R);
            cout << "Enter The serial number of Relation in which you want to rename an attribute" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index = take_index(size) - 1;
            cout << "Enter the attribute name you want to change" << endl;
            string s1;
            cin >> s1;
            cout << "Enter new name" << endl;
            string s2;
            cin >> s2;
            R[size++] = difference(R[index], s1, s2);
            cout << "<----------------Printing the edited relation------------------------->" << endl;
            R[size - 1]->print_relation();
        }
        else if (key == 11)
        {
            cout << "<----------------------------Projections of attributes in Relation----------------->" << endl;
            print_all_attr(size, R);
            cout << "Enter The serial number of Relation in which you want to take projection" << endl
                 << "(Range is 1 to " << size << " )" << endl;
            int index = take_index(size) - 1;
            int n;
            cout << "Enter the number of attributes" << endl;
            cin >> n;
            cout << "Enter the attribute names you want to change" << endl;
            list<string> projact;
            for (int i = 0; i < n; i++)
            {
                string s1;
                cin >> s1;
                projact.push_back(s1);
            }
            R[size++] = projection(R[index], projact);
            cout << "<----------------Printing the projected relation------------------------->" << endl;
            R[size - 1]->print_relation();
        }
        else
        {
            cout << "Not a valid key!!!" << endl
                 << endl;
        }
    }
}