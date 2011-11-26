/**
 Boost.Utilityはさまざまな小道具が入っているBoostのライブラリです。
 今回はそのBoost.Utilityを見ていこうと思います。
 
 noncopyable
 checked_delete, checked_array_delete
 typeof
 address_of
 BOOST_STATIC_ASSERT
 **/

#include <iostream>
#include <boost/utility.hpp>
#include <boost/checked_delete.hpp>
#include <vector>
#include <map>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>

#include "boost_test.h"

//コピーできないようにする(boost/utility)
int copyerror ()
{
    /**
     please_dont_make_copies d1;
     please_dont_make_copies d2(d1);
     please_dont_make_copies d3;
     d3 = d1;
     **/
    
    return 0;
}

//checked_deleteのサンプル(boost/checked_delete)
some_class* create()
{
    return (some_class*)0;
}

int checked_delete_test ()
{
    /**
     some_class* p = create();
     boost::checked_delete(p);
     **/
    
    return 0;
}

//拡張forループのテスト、後述のassignも使用している(boost/assign)
int auto_test()
{
    
    using namespace boost::assign;
    
    std::vector<int> vec;
    
    /**
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);....
    と続くものが次の１行で済む
    **/
    vec += 1,2,3,4,5;
    
    for (int x: vec){
        std::cout << x << std::endl;
    }
    
    return 0;
}

//面倒なコンテナへの値の代入を行う、ちょっと難しいmapバージョン(boost/assign)
int assign_test()
{
    std::map<char,int> m = boost::assign::map_list_of('A',1)('J',11)('Q',12)('K',13);
    
    for (std::map<char, int>::value_type x: m){
        std::cout << x.first << ":" << x.second << std::endl;
    }
    
    return 0;
}

//変数のアドレスを取得できるようにする美しくない作業をやってくれる(boost/utility)
int addressof_test()
{
    OpAmpOverloaded obj;
    
    std::cout << reinterpret_cast<int*>(boost::addressof(obj)) << std::endl;
    
    //できない
    //std::cout << reinterpret_cast<int*>(&obj) << std::endl;
    
    return 0;    
}

//式の型を取得(boost/typeof/typeof.hpp)
int typeof_test()
{
    std::cout << typeid(BOOST_TYPEOF(1+2.34)).name() << std::endl;
    std::cout << typeid(BOOST_TYPEOF(100)).name() << std::endl;
    std::cout << typeid(BOOST_TYPEOF('a')).name() << std::endl;
    std::cout << typeid(BOOST_TYPEOF("")).name() << std::endl;
    std::cout << typeid(BOOST_TYPEOF("hehehe")).name() << std::endl;            //英文字一文字A1+1
    std::cout << typeid(BOOST_TYPEOF("アース")).name() << std::endl;           //日本語一文字A3*3+1
    std::cout << typeid(BOOST_TYPEOF("アノマロカリモン")).name() << std::endl;  //char型のarrayという扱いかな？
    
    //BOOST_AUTO(x, 1+2.34);は
    //BOOST_TYPEOF(1+2.34)x = 1+2.34;と
    //double x = 1+2.34;と同じである
    
    return 0;
}
