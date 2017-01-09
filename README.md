# srcmkg\_design\_patterns
tweaked design patterns examples (C++) from sourcemaking.com 

[![Build Status](https://travis-ci.org/tlanc007/srcmkg_design_patterns.svg?branch=master)](https://travis-ci.org/tlanc007/srcmkg_design_patterns)

## Table of Contents
* [Background](#background)
* Structural
  * Adapter
     * [externalPolymorphism](#externalpolymorphism)

## Background
(01/07/17 -- Tal
I have just created the site. I will be adding examples as I get around to them.)

[SOURCEMAKING](https://sourcemaking.com/) does a good job on explaining many of the common [Design Patterns](https://sourcemaking.com/design_patterns).  Typically for each design pattern covered, there is a series of examples, covering a number of different languages.  Many of examples in C++ relying on older C++ syntax rather than taking advantage of more modern syntax.

This repo gives my take of what the example would look like using more modern C++.  I don't claim to be an expert on the various design patterns.

The repo makes use of [Catch](https://github.com/philsquared/Catch) for C++ unit-testing.  (If one can call it unit-testing, as the repo is just catching and comparing stdout rather than doing any real testing).

## Structural
Structural design patterns

### Adapters
#### externalPolymorphism
This is my first pass on this example.

The original code can be found on [SourceMaking.com](https://sourcemaking.com) at:  [externalPolymorphism](https://sourcemaking.com/design_patterns/adapter/cpp/2).

The example has been broken out into a number of files:

* adapterExternalPolymorphism.h
* adapterExternalPolymorphism.cpp
* adapterOldInterface.h
* main.cpp

Here is a list of the changes done:

* Dropped the use of "using namespace std"
  * This is a bad habit to fall into.
* Switched the `std::endl` (or literally `endl` as the original code read).  
  * This causes a flush of the buffer and can be a performance bottleneck.  So it is best to avoid it unless you really need to flush the buffer.
*  Swapped out old style initialization for *brace-init-list* form.
*  Dropped the C-style array for a `std::array`.  
  * `std::vector` would be a viable option.  But in this case the original example had a fixed size and `std::array` is a bit lighter weight as it doesn't have to deal with resizing.
*   Was able to get rid of one layer of deletes by using the smart pointer: `std::shared_ptr`.  It still bothers me that there is the delete needed in **ExecuteAdapter** class.  I may take another pass on this to see about cleaning that up.
*   
