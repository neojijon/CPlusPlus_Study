#include <tuple>        // std::tuple
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>    // std::sort
#include "Array.hpp"    // Array

typedef std::tuple<std::string, std::string, int> Account;
void print( Account& val ) {
    std::string account;
    std::string name;
    int bal;
    std::tie( account, name, bal ) = val;

    std::printf( "계 좌 : %s, 소유자 : %s", account.data(), name.data() );
    std::printf( ",\t 잔 액 : %d\n", bal );
}

bool Compare( const Account& i, const Account& j ) {
    return std::get<2>( i ) < std::get<2>( j );
}

int main() {
    Array<Account> array = {
        std::make_tuple( "120-345-129099", "홍길동", 60000 ),
        std::make_tuple( "120-345-223011", "김홍도", 10000 ),
        std::make_tuple( "210-545-144011", "신사임당", 50000 )
    };

    Account lee( "156-734-002391", "이순신", 20000 );
    Account kim( "316-374-203191", "김유신", 10000 );
    
    // std::tie() and std::ignore.
    std::string name;
    int bal;
    size_t count = std::tuple_size<Account>::value;
    
    std::tie( std::ignore, name, bal ) = lee;
    std::cout << name << ", " << bal << std::endl;

    auto myNums = std::tuple_cat( lee, kim );

    std::cout << "Value 1 : " << std::get<0>( myNums ) << ", "
              << std::get<1>( myNums ) << ", " << std::get<2>( myNums ) << std::endl;
    std::cout << "Value 2 : " << std::get<3>( myNums ) << ", "
              << std::get<4>( myNums ) << ", " << std::get<5>( myNums ) << std::endl;

    array.push_back( lee );
    array.push_back( kim );
    array.push_back( std::make_tuple( "124-012-009834", "권율", 20000 ) );
//  array.push_back( std::forward_as_tuple( "124-012-009834", "권율", 20000 ) );
    std::sort( array.begin(), array.end(), Compare );
    
    for (auto& a : array) {
        print( a );
    }
    return 0;
}