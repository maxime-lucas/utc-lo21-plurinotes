#ifndef P_VERSIONS
#define P_VERSIONS

#include "main.h"
#include "p_notes.h"
#include <QString>

class Note;

class Version
{
    private:
        unsigned int numVersion;
        Note* state;

    public:
        Version(unsigned int num,Note* s): numVersion(num), state(s) {}

        unsigned int getNumVersion() const { return numVersion; }
        void setNumVersion(unsigned int i) { numVersion = i; }
        Note* getState() const { return state; }

        QString toString() const;
};

#endif // P_VERSIONS

