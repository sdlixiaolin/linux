#include <iostream>

#include "InputEvent.hpp"
#include "InputOperation.hpp"
#include "TouchEvent.hpp"

using namespace std;

int openInputDevice( int num )
{
    char name[64];
    int ret = 0 ;
    
    sprintf( name , "/dev/input/event%d" , num );

    ret = open( name , O_RDWR , 0 );
    if ( ret < 0)
    {
        cerr << "Open " << name << " failed " << endl ;
        return -1 ; 
    }
    return ret ;
}

int main(int argc, char *argv[])
{
    int fd = openInputDevice( 0 ) ;

    if ( fd < 0   )
    {
        return -1 ; 
    }

    TouchEvent touchEvent( Position( 62 , 88 ));
    shared_ptr<InputOperation> op = touchEvent.generateOperation( fd ) ;
    op->execute() ;

    close( fd );
    return 0;
}
