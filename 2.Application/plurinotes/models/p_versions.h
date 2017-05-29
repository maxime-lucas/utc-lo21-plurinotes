#ifndef P_VERSIONS
#define P_VERSIONS

#include "main.h"

class Version
{
    private:
        unsigned int numero;
        Note* state;

    public:
        Version(unsigned int num,Note* s): numero(num), state(s) {}
};

#endif // P_VERSIONS

