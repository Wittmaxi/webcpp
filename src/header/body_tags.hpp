#ifndef __BODY__TAGS
#define __BODY__TAGS
#include "base_traits.hpp"

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
    void outputOpening();
    void outputClosing();
};

} // namespace WCP

#endif