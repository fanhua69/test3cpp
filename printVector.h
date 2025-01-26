//
//  printVector.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-13.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

const string g_separators = "@.-:,\n";

class ps : public std::stack<char>
{
public:

    ps(int n)
    {
        for(int i = 0; i< n; i++)
            add(',');
    }
    ps(string s)
    {
        add(s);
    }

    void clear()
    {
        while(!empty())
            pop();
    }

    void add(string s)
    {
        for(char c: s)
        {
            add(c);
        }
    }

    void add(char cBetween)
    {
        emplace(cBetween);
    }

    void add()
    {
        add(',');
    }

};

template <class T>
bool isSimpleType()
{
    return (std::is_same<T,std::string>::value||
            std::is_same<T,int>::value ||
            std::is_same<T,float>::value ||
            std::is_same<T,double>::value ||
            std::is_same<T,char>::value ||
            std::is_same<T,int>::value);
}


template < class T>
void print(T &a, ps &s)
{
    cout << a;
}

#include <list>
template <typename T>
void print(std::list<T> &a)
{
    for(auto it = a.begin(); it != a.end(); ++it)
        cout << *it << ", ";

    cout << endl;
}


template < class T>
void print(T &a)
{
    cout << a << endl;
}


template<class T1, class T2 >
void print(std::pair<T1, T2> &v, ps separators = ps(""))
{
    char cb = ',';
    if(separators.size() > 0)
    {
        cb = separators.top();
        separators.pop();
    }

    print(v.first, separators);
    cout << cb;
    print(v.second, separators);

    separators.add(cb);
}

template<class T>
void print(std::set<T> &v, ps separators = ps(""))
{
    char cb = ',';
    if(separators.size() > 0)
    {
        cb = separators.top();
        separators.pop();
    }

    int ss = v.size();
    int i = 0;
    for( auto a : v)
    {
        print(a, separators);
        if ( i != ss-1)
        {
            cout << cb;
        }
    }

    separators.add(cb);
}

template<class T>
void printme(std::set<T> &v, string s = "")
{
    if(s.size()==0)
        s = g_separators;

    cout << "-------------------------------" << endl;
    print(v, ps(s));
    cout << endl;
    cout << "-------------------------------" << endl;
}

template<class T1, class T2>
void printme(std::pair<T1,T2> &v, string s)
{
    if(s.size()==0)
        s = g_separators;

    cout << "-------------------------------" << endl;
    print(v, ps(s));
    cout << endl;
    cout << "-------------------------------" << endl;

}

template <class T>
void print(vector<T> &v, ps separators = ps(""))
{
    char cb = ',';
    if(separators.size() > 0)
    {
        cb = separators.top();
        separators.pop();
    }

    for (int i = 0; i< v.size(); i++)
    {
        print(v[i],separators);
        if( i != v.size() - 1)
        {
            cout << cb;
        }
    }

    separators.add(cb);
}

template <class T>
void printme(vector<T> &v, string s = "")
{
    if(s.size()==0)
        s = g_separators;

    cout << "-------------------------------" << endl;
    print(v, ps(s));
    cout << endl;
    cout << "-------------------------------" << endl;
}

template<class T1, class T2>
void print(std::map<T1,T2> &m, ps separators = ps(""))
{
    char cb = ',';
    if(separators.size() != 0)
    {
        cb = separators.top();
        separators.pop();
    }


    auto last = m.rbegin();
    ++last;

    for( auto it = m.begin(); it != m.end(); ++it)
    {
        print(*it, separators);

        if(it != last.base())
        {
            cout << cb;
        }
    }

    separators.add(cb);
}

template<class T1, class T2>
void printme(std::map<T1,T2> &v, string s = "")
{
    if(s.empty())
        s = g_separators;

    cout << "-------------------------------" <<endl;;
    print(v, ps(s));
    cout << endl;
    cout << "-------------------------------" << endl;
}


template<class T1, class T2>
void print(std::stack<T1,T2> s, ps separators = ps(""))
{
    char cb = ',';
    if(separators.size() != 0)
    {
        cb = separators.top();
        separators.pop();
    }

    while(s.size())
    {
        print(s.top(), separators);

        if(s.size()!=1)
        {
            cout << cb;
        }

        s.pop();
    }

    separators.add(cb);
}

template<class T1, class T2>
void printme(std::stack<T1, T2> &stack, string s = "")
{
    if(s.empty())
    {
        s = g_separators;
    }

    cout << "-------------------------------" <<endl;;
    print(stack, ps(s));
    cout << endl;
    cout << "-------------------------------" << endl;
}



template<class T1>
void print(std::deque<T1> s, ps separators = ps(""))
{
    char cb = ',';
    if(separators.size() != 0)
    {
        cb = separators.top();
        separators.pop();
    }

    while(s.size())
    {
        print(s.front(), separators);

        if(s.size()!=1)
        {
            cout << cb;
        }

        s.pop_front();
    }

    separators.add(cb);
}

template<class T1>
void printme(std::deque<T1> &q, string s = "")
{
    if(s.empty())
    {
        s = g_separators;
    }

    cout << "-------------------------------" <<endl;;
    print(q, ps(s));
    cout << endl;
    cout << "-------------------------------" << endl;
}
