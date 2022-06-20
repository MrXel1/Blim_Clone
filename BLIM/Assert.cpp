#include "Assert.h"

#include <iostream>
#include <cstdlib>
Assert::Assert(){
	
}

Assert::Assert( bool val, std::string s )
{
	if( !( val ) )
	{
		std::cout << "Falla: " << s << std::endl;
		exit( -1 );
	}
}

