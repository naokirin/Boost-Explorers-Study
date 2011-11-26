//
//  boost_test.h
//  test
//
//  Created by 大田 on 11/11/14.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef test_boost_test_h
#define test_boost_test_h

#include <boost/utility.hpp>
#include <boost/checked_delete.hpp>
#include <vector>

class please_dont_make_copies : boost::noncopyable {};

int copyerror ();

//checked_deleteのサンプル
class some_class;

some_class* create();
int checked_delete_test ();

int auto_test();

int assign_test();

//addressofのテスト
struct OpAmpOverloaded
{
    void operator&(){}
};

int addressof_test();

//typeofのテスト
int typeof_test();

#endif
