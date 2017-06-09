#ifndef NOTESEXCEPTION
#define NOTESEXCEPTION

#include "main.h"

class NotesException{
    public:
        NotesException(const QString& message):info(message){}
        QString getInfo() const { return info; }
    private:
        QString info;
};

#endif // NOTESEXCEPTION

