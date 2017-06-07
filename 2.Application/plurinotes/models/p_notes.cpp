#include "main.h"
#include "models/p_notes.h"

Note::~Note() {}
Article::~Article() {}
Multimedia::~Multimedia() {}

NotesManager::NotesManager() : tab(0), nb(0), max(0) {}
NotesManager::~NotesManager() {}

ActiveNotesManager::ActiveNotesManager() : NotesManager() {}
ActiveNotesManager::~ActiveNotesManager() {}

ArchivedNotesManager::ArchivedNotesManager() : NotesManager() {}
ArchivedNotesManager::~ArchivedNotesManager() {}

DeletedNotesManager::DeletedNotesManager() : NotesManager() {}
DeletedNotesManager::~DeletedNotesManager() {}

void NotesManager::addElement(Note *n) {
    if(nb == max)
    {
        //Augmente taille tab**
        Note** newtab = new Note*[max+NBMAX];

        for(unsigned int i=0; i<nb; i++)
            newtab[i]=tab[i];

        Note** oldTab=tab;
        tab=newtab;
        max+=NBMAX;
        if (oldTab) delete[] oldTab;
    }
    tab[nb+1] = n;
    nb++;
}
