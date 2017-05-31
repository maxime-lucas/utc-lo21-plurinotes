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
