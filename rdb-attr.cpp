//Name-Hrushikesh Reddy
//Roll number-21CS30028
#include "rdb.h"
//Taking the input of type
string take_type()
{
    string t;
    cin >> t;
    while (t != "int" && t != "string" && t != "float")
    {
        cout << "Invalid Type! Enter again" << endl;
        cin >> t;
    }
    return t;
}
//Attribute constructor
Attr::Attr(string t) : type(t) {}
//Returning the type of a attribute
string Attr::gettype() const
{
    return type;
}
//StringAttribute Constructor
StringAttribute::StringAttribute(string v) : Attr("string"), val(v) {}
// Returning the value
string StringAttribute::get_val()
{
    return val;
}
//Overloading Different comparison operators for StringAttribute
bool StringAttribute::operator==(const Attr &right)
{
    if (right.gettype() != "string")
        return false;
    else
        return (val == dynamic_cast<const StringAttribute &>(right).val);
}
bool StringAttribute::operator!=(const Attr &right)
{
    if (right.gettype() != "string")
        return true;
    else
        return (val != dynamic_cast<const StringAttribute &>(right).val);
}
bool StringAttribute::operator>(const Attr &right)
{
    if (right.gettype() != "string")
    {
        cout << "Invalid" << endl;
        return false;
    }
    else
        return (val > dynamic_cast<const StringAttribute &>(right).val);
}
bool StringAttribute::operator>=(const Attr &right)
{
    if (right.gettype() != "string")
    {
        cout << "Invalid" << endl;
        return false;
    }
    else
        return (val >= dynamic_cast<const StringAttribute &>(right).val);
}
bool StringAttribute::operator<(const Attr &right)
{
    if (right.gettype() != "string")
    {
        cout << "Invalid" << endl;
        return false;
    }
    else
        return (val < dynamic_cast<const StringAttribute &>(right).val);
}
bool StringAttribute::operator<=(const Attr &right)
{
    if (right.gettype() != "string")
    {
        cout << "Invalid" << endl;
        return false;
    }
    else
        return (val <= dynamic_cast<const StringAttribute &>(right).val);
}
//IntegerAttribute Constructor
IntegerAttribute::IntegerAttribute(int v) : Attr("int"), val(v) {}
// Returning the value
int IntegerAttribute::get_val()
{
    return val;
}
//Overloading Different comparison operators for IntegerAttribute
bool IntegerAttribute::operator==(const Attr &right)
{
    if (right.gettype() != "int")
        return false;
    else
        return (val == dynamic_cast<const IntegerAttribute &>(right).val);
}
bool IntegerAttribute::operator!=(const Attr &right)
{
    if (right.gettype() != "int")
        return true;
    else
        return (val != dynamic_cast<const IntegerAttribute &>(right).val);
}
bool IntegerAttribute::operator>(const Attr &right)
{
    if (right.gettype() != "int")
    {
        // cout << "Invalid" << endl;
        return false;
    }
    else
        return (val > dynamic_cast<const IntegerAttribute &>(right).val);
}
bool IntegerAttribute::operator>=(const Attr &right)
{
    if (right.gettype() != "int")
    {
        // cout << "Invalid" << endl;
        return false;
    }
    else
        return (val >= dynamic_cast<const IntegerAttribute &>(right).val);
}
bool IntegerAttribute::operator<(const Attr &right)
{
    if (right.gettype() != "int")
    {
        // cout << "Invalid" << endl;
        return false;
    }
    else
        return (val < dynamic_cast<const IntegerAttribute &>(right).val);
}
bool IntegerAttribute::operator<=(const Attr &right)
{
    if (right.gettype() != "int")
    {
        // cout << "Invalid" << endl;
        return false;
    }
    else
        return (val <= dynamic_cast<const IntegerAttribute &>(right).val);
}
//FloatAttribute Constructor
FloatAttribute::FloatAttribute(float v) : Attr("float"), val(v) {}
// Returning the value
float FloatAttribute::get_val()
{
    return val;
}
//Overloading Different comparison operators for FloatAttribute
bool FloatAttribute::operator==(const Attr &right)
{
    if (right.gettype() != "float")
        return false;
    else
        return (val == dynamic_cast<const FloatAttribute &>(right).val);
}
bool FloatAttribute::operator!=(const Attr &right)
{
    if (right.gettype() != "float")
        return true;
    else
        return (val != dynamic_cast<const FloatAttribute &>(right).val);
}
bool FloatAttribute::operator>(const Attr &right)
{
    if (right.gettype() != "float")
    {
        cout << "Invalid" << endl;
        return false;
    }
    else
        return (val > dynamic_cast<const FloatAttribute &>(right).val);
}
bool FloatAttribute::operator>=(const Attr &right)
{
    if (right.gettype() != "float")
    {
        cout << "Invalid" << endl;
        return false;
    }
    else
        return (val >= dynamic_cast<const FloatAttribute &>(right).val);
}
bool FloatAttribute::operator<(const Attr &right)
{
    if (right.gettype() != "float")
    {
        cout << "Invalid" << endl;
        return false;
    }
    else
        return (val < dynamic_cast<const FloatAttribute &>(right).val);
}
bool FloatAttribute::operator<=(const Attr &right)
{
    if (right.gettype() != "float")
    {
        cout << "Invalid" << endl;
        return false;
    }
    else
        return (val <= dynamic_cast<const FloatAttribute &>(right).val);
}
//Default constructor for record
Record::Record() {}
//Definitions of member fuctions of record
void Record::add_attribute(string t, string attrname)
{
    // cout << "Enter type" << endl;
    // string t;
    // cin >> t;
    if (t == "int")
    {
        int x;
        cout << "Enter the value of " << attrname << "(type " << t << ") : ";
        cin >> x;
        IntegerAttribute *a = new IntegerAttribute(x);
        attrptr.push_back(/*dynamic_cast<IntegerAttribute*>*/ (a));
        // cout << attrptr.size();
        cout << endl;
    }
    else if (t == "string")
    {
        string x;
        cout << "Enter the value of " << attrname << "(type " << t << ") : ";
        cin >> x;
        StringAttribute *a = new StringAttribute(x);
        attrptr.push_back(/*dynamic_cast<StringAttribute*>*/ (a));
        // cout << attrptr.size();
        cout << endl;
    }
    else if (t == "float")
    {
        float x;
        cout << "Enter the value of " << attrname << "(type " << t << ") : ";
        cin >> x;
        FloatAttribute *a = new FloatAttribute(x);
        attrptr.push_back(/*dynamic_cast<FloatAttribute*>*/ (a));
        // cout << attrptr.size();
        cout << endl;
    }
}
Record::Record(Record &r)
{
    for (int i = 0; i < r.attrptr.size(); i++)
    {
        string t = r.attrptr[i]->gettype();
        if (t == "int")
        {
            int x;
            x = dynamic_cast<IntegerAttribute *>(r.attrptr[i])->get_val();
            IntegerAttribute *a = new IntegerAttribute(x);
            attrptr.push_back(/*dynamic_cast<IntegerAttribute*>*/ (a));
            // cout << attrptr.size();
        }
        else if (t == "string")
        {
            string x;
            x = dynamic_cast<StringAttribute *>(r.attrptr[i])->get_val();
            StringAttribute *a = new StringAttribute(x);
            attrptr.push_back(/*dynamic_cast<StringAttribute*>*/ (a));
            // cout << attrptr.size();
        }
        else if (t == "float")
        {
            float x;
            x = dynamic_cast<FloatAttribute *>(r.attrptr[i])->get_val();
            FloatAttribute *a = new FloatAttribute(x);
            attrptr.push_back(/*dynamic_cast<FloatAttribute*>*/ (a));
            // cout << attrptr.size();
        }
    }
}
Record::Record(Record &r1, Record &r2)
{
    for (int i = 0; i < r1.attrptr.size(); i++)
    {
        string t = r1.attrptr[i]->gettype();
        if (t == "int")
        {
            int x;
            x = dynamic_cast<IntegerAttribute *>(r1.attrptr[i])->get_val();
            IntegerAttribute *a = new IntegerAttribute(x);
            attrptr.push_back(/*dynamic_cast<IntegerAttribute*>*/ (a));
            // cout << attrptr.size();
        }
        else if (t == "string")
        {
            string x;
            x = dynamic_cast<StringAttribute *>(r1.attrptr[i])->get_val();
            StringAttribute *a = new StringAttribute(x);
            attrptr.push_back(/*dynamic_cast<StringAttribute*>*/ (a));
            // cout << attrptr.size();
        }
        else if (t == "float")
        {
            float x;
            x = dynamic_cast<FloatAttribute *>(r1.attrptr[i])->get_val();
            FloatAttribute *a = new FloatAttribute(x);
            attrptr.push_back(/*dynamic_cast<FloatAttribute*>*/ (a));
            // cout << attrptr.size();
        }
    }
    for (int i = 0; i < r2.attrptr.size(); i++)
    {
        string t = r2.attrptr[i]->gettype();
        if (t == "int")
        {
            int x;
            x = dynamic_cast<IntegerAttribute *>(r2.attrptr[i])->get_val();
            IntegerAttribute *a = new IntegerAttribute(x);
            attrptr.push_back(/*dynamic_cast<IntegerAttribute*>*/ (a));
            // cout << attrptr.size();
        }
        else if (t == "string")
        {
            string x;
            x = dynamic_cast<StringAttribute *>(r2.attrptr[i])->get_val();
            StringAttribute *a = new StringAttribute(x);
            attrptr.push_back(/*dynamic_cast<StringAttribute*>*/ (a));
            // cout << attrptr.size();
        }
        else if (t == "float")
        {
            float x;
            x = dynamic_cast<FloatAttribute *>(r2.attrptr[i])->get_val();
            FloatAttribute *a = new FloatAttribute(x);
            attrptr.push_back(/*dynamic_cast<FloatAttribute*>*/ (a));
            // cout << attrptr.size();
        }
    }
}
void Record::print(vector<string> attrnames)
{
    // cout << attrptr.size()<<endl;
    for (int i = 0; i < attrptr.size(); i++)
    {
        // cout<<i<<endl;
        if (attrptr[i]->gettype() == "int")
        {
            cout << attrnames[i] << ": " << dynamic_cast<IntegerAttribute *>(attrptr[i])->get_val() << endl;
        }
        else if (attrptr[i]->gettype() == "string")
        {
            cout << attrnames[i] << ": " << dynamic_cast<StringAttribute *>(attrptr[i])->get_val() << endl;
        }
        else if (attrptr[i]->gettype() == "float")
        {
            cout << attrnames[i] << ": " << dynamic_cast<FloatAttribute *>(attrptr[i])->get_val() << endl;
        }
    }
    cout << endl;
}
void Record::create_record(int size, vector<string> t, vector<string> names)
{
    for (int i = 0; i < size; i++)
        add_attribute(t[i], names[i]);
}
Attr* Record::getattr(int i){
    return attrptr[i];
}
//Definitions of member functions for Relation class
Relation::Relation(int flag)
{
    if (flag)
    {
        cout << "Enter the number of attributes ";
        cin >> natttr;
        cout << "Enter the number of records you want to create in this relation: ";
        cin >> nrecs;
    }
}
Relation::Relation(const Relation &R)
{
    natttr = R.natttr;
    nrecs = R.nrecs;
    for (int i = 0; i < R.attrnames.size(); i++)
    {
        attrnames.push_back(R.attrnames[i]);
        type.push_back(R.type[i]);
        attrinds.push_back(i + 1);
    }
    for (auto it = R.recs.begin(); it != R.recs.end(); it++)
    {
        Record *r = new Record(**it);
        recs.push_back(r);
    }
}
void Relation::create()
{
    cout << "Enter the attributes names and type" << endl;
    string x;
    for (int i = 0; i < natttr; i++)
    {
        cout << "Attribute Name: ";
        cin >> x;
        attrnames.push_back(x);
        cout << endl
             << "Attribute type of " << x << " : ";
        x = take_type();
        cout << endl;
        type.push_back(x);
        attrinds.push_back(i + 1);
    }
    cout << "Enter the records" << endl;
    for (int i = 0; i < nrecs; i++)
    {
        Record *r = new Record;
        cout << "Enter the details of " << i + 1 << "th record in order of attribute names" << endl
             << endl;
        r->create_record(natttr, type, attrnames);
        recs.push_back(r);
        // cout<<recs.size();
        cout << endl;
    }
    // auto it = recs.begin();
    // cout << (*it)->attrptr.size();
}
void Relation::print_relation()
{
    if (recs.empty())
    {
        cout << "No record" << endl;
    }
    for (auto it = recs.begin(); it != recs.end(); it++)
        (*it)->print(attrnames);
    //(*it)->print();
}
void Relation::delete_record(Record *r)
{
}
string Relation::gettypebyattrname(string name)
{
    int p = find(attrnames.begin(), attrnames.end(), name) - attrnames.begin();
    if (p == natttr)
        return "\0";
    return type[p];
}
void Relation::print_attr()
{
    for (int i = 0; i < natttr; i++)
    {
        cout << attrnames[i] << " ";
    }
    cout << endl;
}
string Relation::gettype(int index)
{
    return type[index];
}
void Relation::add_Record()
{
    Record *r = new Record();
    r->create_record(natttr, type, attrnames);
    recs.push_back(r);
    nrecs++;
}
