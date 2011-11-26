
#include <iostream>
#include <string.h>

#include "template_test.h"
#include "boost_test.h"

static int template_Test(){
    
    // insert code here...
    std::cout << twice(10) << std::endl;
    
    unsigned x = 10;
    
    std::cout << twice(x) << std::endl;
    
    std::cout << foo<10>() << std::endl;
    
    std::cout << twicedouble(10) << std::endl;
    
    //クラステンプレート
    Array<int> Array( 100 );
    std::cout << Array.GetSize() << std::endl;
    
    String<10> String( "hello" );
    std::cout << String.length() << std::endl;
    
    return 0; 
}

int main (int argc, const char * argv[])
{

    //return template_Test();
    //auto_test();
    //assign_test();
    //addressof_test();
    typeof_test();
    
    
    return 0;
    
}

