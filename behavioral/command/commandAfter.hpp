/**

  commandAfter.hpp
 
 This is based on the Command (After) example from:
    https://sourcemaking.com/design_patterns/command/cpp/1
 
 See the repo's README.md for a breakdown of what was done to the example.


  Created by Tal Lancaster on 3/28/17.
  Copyright � 2017 Tal Lancaster. All rights reserved.
**/

#include <algorithm>
#include <deque>
#include <iterator>
#include <iostream>
#include <vector>

class Giant
{
public:
    Giant()
    {
        m_id = s_next++;
    }
    void fee()
    {
        std::cout << m_id << "-fee  ";
    }
    void phi()
    {
        std::cout << m_id << "-phi  ";
    }
    void pheaux()
    {
        std::cout << m_id << "-pheaux  ";
    }
private:
    int m_id;
    static int s_next;
};

class Command
{
public:
    using ActionFunc = void(Giant::*)();
    Command(Giant *object, ActionFunc method)
    : m_object {object},
    m_method {method}
    { }

    void execute()
    {
        (m_object->*m_method)();
    }
private:
    Giant *m_object;
    ActionFunc m_method;
};

void testInterface ();

