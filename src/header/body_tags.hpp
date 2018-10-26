#ifndef __BODY__TAGS
#define __BODY__TAGS
#include "base_traits.hpp"
#include "util.hpp"

namespace WCP
{
class Body : public Block
{
  public:
    template <class... T>
    Body(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    Body();
    Body(const char*);
    void outputOpening();
    void outputClosing();
};

class H1 : public Block, public BodyObject
{
  public:
    template <class... T>
    H1(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H1();
    H1(const char*);
    void outputOpening();
    void outputClosing();
};

class H2 : public Block, public BodyObject
{
  public:
    template <class... T>
    H2(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H2();
    H2(const char*);
    void outputOpening();
    void outputClosing();
};

class H3 : public Block, public BodyObject
{
  public:
    template <class... T>
    H3(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H3();
    H3(const char*);
    void outputOpening();
    void outputClosing();
};

class H4 : public Block, public BodyObject
{
  public:
    template <class... T>
    H4(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H4();
    H4(const char*);
    void outputOpening();
    void outputClosing();
};

class H5 : public Block, public BodyObject
{
  public:
    template <class... T>
    H5(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H5();
    H5(const char*);
    void outputOpening();
    void outputClosing();
};

class H6 : public Block, public BodyObject
{
  public:
    template <class... T>
    H6(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H6();
    H6(const char*);
    void outputOpening();
    void outputClosing();
};

class LineBreak : public Block, public BodyObject 
{
public:
    LineBreak ();
    void outputOpening();
    void outputClosing();
};
extern LineBreak Break;

class Centered : public Block, public BodyObject 
{
public:
    template<class... T>
    Centered (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Centered ();
    Centered (const char*);
    void outputOpening();
    void outputClosing();
};

class Table : public Block, public BodyObject 
{
public:
    template<class... T>
    Table (T... arg) {
        restricted_unpacker<TableObject> (arg...);
    }
    Table ();
    Table (const char*);
    void outputOpening();
    void outputClosing();
};

class Row : public Block, public TableObject 
{
public:
    template<class... T>
    Row (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Row ();
    Row (const char*);
    void outputOpening();
    void outputClosing();
};

class Cell : public Block, public BodyObject 
{
public:
    template<class... T>
    Cell (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Cell (const char*);
    Cell ();
    void outputOpening();
    void outputClosing();
};

class HighlightedCell : public Block, public BodyObject 
{
public:
    template<class... T>
    HighlightedCell (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    HighlightedCell ();
    HighlightedCell (const char*);
    void outputOpening();
    void outputClosing();
};

class Container : public Block, public BodyObject 
{
public:
    template<class... T>
    Container (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Container ();
    Container (const char*);
    void outputOpening();
    void outputClosing();
};

class NavBar : public Block, public BodyObject 
{
public:
    template<class... T>
    NavBar (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    NavBar ();
    NavBar (const char*);
    void outputOpening();
    void outputClosing();
};

class HyperLink : public Block, public BodyObject 
{
public:
    template<class... T>
    HyperLink (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    HyperLink ();
    void outputOpening();
    void outputClosing();
private: 
    std::string href;
};

class Marked : public Block, public BodyObject 
{
public:
    template<class... T>
    Marked (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Marked ();
    void outputOpening();
    void outputClosing();
private: 
    std::string href;
};

class Form : public Block, public BodyObject 
{
public:
    template<class... T>
    Form (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Form ();
    void outputOpening();
    void outputClosing();
private: 
    std::string href;
};

class Input : public Block, public BodyObject 
{
public:
    template<class... T>
    Input (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Input ();
    void outputOpening();
    void outputClosing();
private: 
    std::string href;
};
} // namespace WCP

#endif