#ifndef BODY_TAGS
#define BODY_TAGS
#include "base_traits.hpp"
#include "util.hpp"

namespace WCP
{
class Body : public Block
{
  public:
    template <class... T>
    explicit Body(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    Body();
    explicit Body(const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class H1 : public Block, public BodyObject
{
  public:
    template <class... T>
    explicit H1(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H1();
    explicit H1(const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class H2 : public Block, public BodyObject
{
  public:
    template <class... T>
    explicit H2(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H2();
    explicit H2(const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class H3 : public Block, public BodyObject
{
  public:
    template <class... T>
    explicit H3(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H3();
    explicit H3(const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class H4 : public Block, public BodyObject
{
  public:
    template <class... T>
    explicit H4(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H4();
    explicit H4(const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class H5 : public Block, public BodyObject
{
  public:
    template <class... T>
    explicit H5(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H5();
    explicit H5(const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class H6 : public Block, public BodyObject
{
  public:
    template <class... T>
    explicit H6(T... arg)
    {
        restricted_unpacker<BodyObject>(arg...);
    }
    H6();
    explicit H6(const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class LineBreak : public Block, public BodyObject 
{
public:
    LineBreak ();
    void outputOpening() const;
    void outputClosing() const;
};
extern LineBreak Break;

class Centered : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Centered (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Centered ();
    explicit Centered (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class Table : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Table (T... arg) {
        restricted_unpacker<TableObject> (arg...);
    }
    Table ();
    explicit Table (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class Row : public Block, public TableObject 
{
public:
    template<class... T>
    explicit Row (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Row ();
    explicit Row (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class Cell : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Cell (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    explicit Cell (const char*);
    Cell ();
    void outputOpening() const;
    void outputClosing() const;
};

class HighlightedCell : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit HighlightedCell (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    HighlightedCell ();
    explicit HighlightedCell (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class Container : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Container (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Container ();
    explicit Container (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class NavBar : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit NavBar (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    NavBar ();
    explicit NavBar (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class HyperLink : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit HyperLink (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    HyperLink ();
    explicit HyperLink(const char*);
    void outputOpening() const;
    void outputClosing() const;
private: 
    std::string href;
};

class Marked : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Marked (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Marked ();
    explicit Marked (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class Form : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Form (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Form ();
    explicit Form (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class Input : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Input (T... arg) {
        restricted_unpacker<StyleObject> (arg...);
    }
    Input ();
    void outputOpening() const;
    void outputClosing() const;
};

class Paragraph : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Paragraph (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Paragraph ();
    explicit Paragraph (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class Image : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Image (T... arg) {
        restricted_unpacker<StyleObject> (arg...);
    }
    Image ();
    void outputOpening() const;
    void outputClosing() const;
};

class Picture : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Picture (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Picture ();
    explicit Picture (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class Source : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Source (T... arg) {
        restricted_unpacker<StyleObject> (arg...);
    }
    Source ();
    void outputOpening() const;
    void outputClosing() const;
};

class HorizontalLine : public Block, public BodyObject 
{
public:
    HorizontalLine ();
    void outputOpening() const;
    void outputClosing() const;
};

class Quote : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Quote (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Quote ();
    explicit Quote (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

class Label : public Block, public BodyObject 
{
public:
    template<class... T>
    explicit Label (T... arg) {
        restricted_unpacker<BodyObject> (arg...);
    }
    Label ();
    explicit Label (const char*);
    void outputOpening() const;
    void outputClosing() const;
};

} // namespace WCP

#endif