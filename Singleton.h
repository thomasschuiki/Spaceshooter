////  Singleton.h

#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class Singleton
{
public:
    static T* Instance()
    {
        static T myT;
        return &myT;
    }
};

#endif

////////////////////////////////////////////////
/////Usage

//#include "Singleton.h"
//
//class Foo
//{
//  public:
//     ~Foo();
//
//  private:
//
//     Foo();
//     friend class Singleton<Foo>;
//}
