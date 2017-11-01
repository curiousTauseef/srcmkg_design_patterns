/**

  commandAfter.cpp
 
 This is based on the Command (After) example from:
    https://sourcemaking.com/design_patterns/command/cpp/1
 
 See the repo's README.md for a breakdown of what was done to the example.


  Created by Tal Lancaster on 3/28/17.
  Copyright � 2017 Tal Lancaster. All rights reserved.
**/

#include "commandAfter.hpp"

int Giant::s_next = 0;


void testInterface ()
{
    std::deque<Command*> que;
    std::vector <Command*> input =
    {
        new Command(new Giant, &Giant::fee), new Command(new Giant, &Giant::phi),
        new Command(new Giant, &Giant::pheaux), new Command(new Giant, &Giant::fee),
        new Command(new Giant, &Giant::phi), new Command(new Giant, &Giant::pheaux)
    };

    for (auto&& e: input) {
        que.emplace_front (e);
    }

    std::for_each(que.rbegin(), que.rend(), [&que](Command* e) {
        e->execute();
        que.pop_back();
    } );

    std::cout << '\n';
}
