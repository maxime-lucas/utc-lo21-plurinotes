#ifndef NOTESEXCEPTION
#define NOTESEXCEPTION

class NotesException{
public:
    NotesException(const std::string& message):info(message){}
    std::string getInfo() const { return info; }
private:
    std::string info;
};



#endif // NOTESEXCEPTION

