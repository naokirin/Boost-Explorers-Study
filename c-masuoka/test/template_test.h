
#ifndef test_template_test_h
#define test_template_test_h

#include <string.h>

//入ってきたすべての型を２倍にして返す関数テンプレート
template <class Number> Number twice( Number original )
{ return original + original; }

//int foo()はvoid foo()にするとパラメータが型名ではないので動かないということの確認
template <int count> int foo( )  // パラメータが型名ではないので無効
{
    int x[count];
    for (int i = 0; i < count; ++i ) {
        // ... x により何かを行う
        x[i] = count;
    }
        
     return 0;
}

//doubleを取り、twiceを使用して、２倍の値を返す
static double twicedouble( double item )
{ return twice( item ); }

//不完全なクラステンプレート、任意の型を取る
template <class Elem> class Array;

template <class Elem> class Array {
    Elem* data;
    int size;
public:
    Array( int sz );
    int GetSize();
    Elem& operator[]( int idx );
};

//szサイズのElem型の配列を作り、sizeにサイズを記憶
template <class Elem> Array<Elem>::Array( int sz )
{ size = sz; data = new Elem[ size ]; }

//sizeを返す
template <class Elem> int Array<Elem>::GetSize( )
{ return size; }

//式パラメータをとる
template <unsigned Size> class String;

template <unsigned Size> class String {
    char data[Size];
    static int overflows;
public:
    String( char *initial );
    int length();
};

template <unsigned Size> int String<Size>::length( )
{ int len = 0;
    while ( len < Size && data[len] != '\0' ) len++;
    return len; }

template <unsigned Size> int String<Size>::overflows = 0;

template <unsigned Size> String<Size>::String( char *initial )
{ strncpy( data, initial, Size );
    if ( length() == Size ) overflows++; }


//コンパイラがテンプレート引数を明確に確認できる場合には、テンプレート引数を省略することができる
template <> unsigned twice( unsigned original )
{ return original; }

//template <> sort( Array<char*> store );

#endif
