//Name-Hrushikesh Reddy
//Roll number-21CS30028
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <tuple>
using namespace std;

class Relation;
class Record;
class Attr;
//Defining Struct for DNF 
typedef struct DNFformula
{
    list<list<tuple<string, char, Attr *>>> ops;
} DNFformula;
//Attribute class prototype
class Attr
{
protected:
    string type;

public:
    Attr(string t);

    string gettype() const;
    virtual bool operator==(const Attr &right) = 0;
    virtual bool operator!=(const Attr &right) = 0;
    virtual bool operator<(const Attr &right) = 0;
    virtual bool operator<=(const Attr &right) = 0;
    virtual bool operator>(const Attr &right) = 0;
    virtual bool operator>=(const Attr &right) = 0;
    friend int check_attributes(Relation *, Relation *);
    friend int check_Record(Relation *R, Record *r);
    friend Relation *union_relation(Relation *R1, Relation *R2);
    friend Relation *catersianproduct(Relation *R1, Relation *R2);
    friend Relation *projection(Relation *R1, list<string> projectattrs);
    friend Relation *difference(Relation *R1, string s1, string s2);
    friend Relation *union_relation(Relation *R1, DNFformula *f);
    friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
};
//StringAttribute class prototype
class StringAttribute : public Attr
{
    string val;

public:
    StringAttribute(string v);
    string get_val();
    bool operator==(const Attr &right);
    bool operator!=(const Attr &right);
    bool operator>(const Attr &right);
    bool operator>=(const Attr &right);
    bool operator<(const Attr &right);
    bool operator<=(const Attr &right);
    friend class Record;
    friend class Relation;
    friend int check_attributes(Relation *, Relation *);
    friend int check_Record(Relation *R, Record *r);
    friend Relation *union_relation(Relation *R1, Relation *R2);
    friend Relation *catersianproduct(Relation *R1, Relation *R2);
    friend Relation *projection(Relation *R1, list<string> projectattrs);
    friend Relation *difference(Relation *R1, string s1, string s2);
    friend Relation *union_relation(Relation *R1, DNFformula *f);
    friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
};
//IntegerAttribute class prototype
class IntegerAttribute : public Attr
{
    int val;

public:
    IntegerAttribute(int v);
    int get_val();
    bool operator==(const Attr &right);
    bool operator!=(const Attr &right);
    bool operator>(const Attr &right);
    bool operator>=(const Attr &right);
    bool operator<(const Attr &right);
    bool operator<=(const Attr &right);
    friend class Record;
    friend class Relation;
    friend int check_attributes(Relation *, Relation *);
    friend int check_Record(Relation *R, Record *r);
    friend Relation *union_relation(Relation *R1, Relation *R2);
    friend Relation *catersianproduct(Relation *R1, Relation *R2);
    friend Relation *projection(Relation *R1, list<string> projectattrs);
    friend Relation *difference(Relation *R1, string s1, string s2);
    friend Relation *union_relation(Relation *R1, DNFformula *f);
    friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
};
//FloatAttribute class prototype
class FloatAttribute : public Attr
{
    float val;

public:
    FloatAttribute(float v);
    float get_val();
    bool operator==(const Attr &right);
    bool operator!=(const Attr &right);
    bool operator>(const Attr &right);
    bool operator>=(const Attr &right);
    bool operator<(const Attr &right);
    bool operator<=(const Attr &right);
    friend class Record;
    friend class Relation;
    friend int check_attributes(Relation *, Relation *);
    friend int check_Record(Relation *R, Record *r);
    friend Relation *union_relation(Relation *R1, Relation *R2);
    friend Relation *catersianproduct(Relation *R1, Relation *R2);
    friend Relation *projection(Relation *R1, list<string> projectattrs);
    friend Relation *difference(Relation *R1, string s1, string s2);
    friend Relation *union_relation(Relation *R1, DNFformula *f);
    friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
};
//Record Class Prototype
class Record
{ // storing data for each record
    vector<Attr *> attrptr;
public:
    Record();
    void add_attribute(string t, string attrname);
    Attr* getattr(int);
    Record(Record &r);
    Record(Record &r1, Record &r2);
    void print(vector<string> attrnames);
    void create_record(int size, vector<string> t, vector<string> names);
    friend int check_attributes(Relation *, Relation *);
    friend int check_Record(Relation *R, Record *r);
    friend Relation *union_relation(Relation *R1, Relation *R2);
    friend Relation *catersianproduct(Relation *R1, Relation *R2);
    friend Relation *projection(Relation *R1, list<string> projectattrs);
    friend Relation *difference(Relation *R1, string s1, string s2);
    friend Relation *union_relation(Relation *R1, DNFformula *f);
    friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
    friend class Relation;
};
//Relation class prototype
class Relation
{ // storing a relation

    int natttr, nrecs;        // number of attributes and records
    vector<int> attrinds;     // mapping schema to indices
    list<Record *> recs;      // list of records
    vector<string> type;

public:
    vector<string> attrnames; // schema
    Relation(int flag = 1);
    Relation(const Relation &R);
    void create();
    void print_relation();
    void delete_record(Record *r);
    string gettypebyattrname(string name);
    void print_attr();
    string gettype(int index);
    void add_Record();
    friend int check_attributes(Relation *, Relation *);
    friend int check_Record(Relation *R, Record *r);
    friend Relation *union_relation(Relation *R1, Relation *R2);
    friend Relation *difference(Relation *R1, Relation *R2);
    friend Relation *catersianproduct(Relation *R1, Relation *R2);
    friend Relation *projection(Relation *R1, list<string> projectattrs);
    friend Relation *difference(Relation *R1, string s1, string s2);
    friend Relation *union_relation(Relation *R1, DNFformula *f);
    friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
};
Relation *union_relation(Relation *R1, Relation *R2);
Relation *difference(Relation *R1, Relation *R2);
Relation *catersianproduct(Relation *R1, Relation *R2);
Relation *projection(Relation *R1, list<string> projectattrs);
Relation *difference(Relation *R1, string s1, string s2);
Relation *union_relation(Relation *R1, DNFformula *f);
Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
