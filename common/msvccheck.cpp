#include "msvccheck.h"

int msvccheck()
{
    #if _MSC_VER >= 1930
    std::cout << "Visual Studio 2022" << std::endl;
#elif _MSC_VER >= 1920
    std::cout << "Visual Studio 2019" << std::endl;
#elif _MSC_VER >= 1910
    std::cout << "Visual Studio 2017" << std::endl;
#elif _MSC_VER >= 1900
    std::cout << "Visual Studio 2015" << std::endl;
#elif _MSC_VER >= 1800
    std::cout << "Visual Studio 2013" << std::endl;
#elif _MSC_VER >= 1700
    std::cout << "Visual Studio 2012" << std::endl;
#elif _MSC_VER >= 1600
    std::cout << "Visual Studio 2010" << std::endl;
#else
    std::cout << "Unknown Version" << std::endl;
#endif
    return 0;
}