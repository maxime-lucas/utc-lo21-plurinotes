#ifndef NOTE
#define NOTE

#include "main.h"

class Note {

    private:
        std::string id;
        std::string title;
        Datetime createdOn;
        Datetime lastModifOn;

    public:
        Note(std::string i = "", std::string t = "", Datetime co = 0, Datetime lmo = 0) :
            id(i),
            title(t),
            createdOn(co),
            lastModifOn(lmo) {}
        virtual ~Note() = 0;

        std::string getId() const { return id; }
        std::string getTitle() const { return title; }
        Datetime getCreatedOn() const { return createdOn; }
        Datetime getLastModifOn() const { return lastModifOn; }

        void setId(std::string i) { id = i; }
        void setTitle(std::string t) { title = t; }
        void setCreatedOn(Datetime co) { createdOn = co; }
        void setLastModifOn(Datetime lmo) { lastModifOn = lmo; }

};

class Article : public Note {
    private :
        std::string text;

    public :
        Article(std::string i = "", std::string t = "", Datetime co = 0, Datetime lmo = 0, std::string txt = "" ) : Note(i,t,co,lmo), text(txt) {}

        ~Article();
};

class Multimedia : public Note {
    private :
        std::string description;
        std::string pathToFile;
        enum TypeMultimedia type;

    public :
        Multimedia(std::string i = "", std::string t = "", Datetime co = 0, Datetime lmo = 0, std::string desc, std::string ptf, TypeMultimedia t) : Note(i,t,co,lmo), description(desc), pathToFile(ptf), type(t) {}

        ~Multimedia();
};

#endif // NOTE

