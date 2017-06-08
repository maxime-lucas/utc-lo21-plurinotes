#include "main.h"
#include "models/p_notes.h"

Note::~Note() {}
Article::~Article() {}
Multimedia::~Multimedia() {}
Task::~Task() {}

NotesManager::NotesManager() {
    tab = new std::vector<Note*>;
}
NotesManager::~NotesManager() {}

ActiveNotesManager::ActiveNotesManager() : NotesManager() {}
ActiveNotesManager::~ActiveNotesManager() {}

ArchivedNotesManager::ArchivedNotesManager() : NotesManager() {}
ArchivedNotesManager::~ArchivedNotesManager() {}

DeletedNotesManager::DeletedNotesManager() : NotesManager() {}
DeletedNotesManager::~DeletedNotesManager() {}
