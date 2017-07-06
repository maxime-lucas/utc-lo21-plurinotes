#include "main.h"
#include "models/p_notes.h"

Note::~Note() {}
Article::~Article() {}
Multimedia::~Multimedia() {}
Task::~Task() {}

/*!
 * \brief NotesManager::NotesManager
 * Initialisation du vecteur de Note*.
 */
NotesManager::NotesManager() {
    tab = new std::vector<Note*>;
}
NotesManager::~NotesManager() {
    if (tab) delete[] tab;
}

ActiveNotesManager::ActiveNotesManager() : NotesManager() {}
ActiveNotesManager::~ActiveNotesManager() {}

ArchivedNotesManager::ArchivedNotesManager() : NotesManager() {}
ArchivedNotesManager::~ArchivedNotesManager() {}

DeletedNotesManager::DeletedNotesManager() : NotesManager() {}
DeletedNotesManager::~DeletedNotesManager() {}

/*!
 * \brief Article::toString
 * \return Fonction permettant de transformer un objet Article en chaine de caractère en suivant un modèle spécifique.
 */

QString Article::toString() const {

    QString f;
        f = "[ARTICLE]\n";
        f += "  id : " + getId()+ "\n";
        f += "  title : " + getTitle()+ "\n";
        f += "  createdOn : " + getCreatedOn().toString() + "\n";
        f += "  lastModifOn : " + getLastModifOn().toString() + "\n";
        f += "  text : " + getText() + "\n";
        f += "[VERSIONS][size=" + QString::number(versions->size()) + "]\n";

        for(unsigned int i = 0; i < versions->size(); i++){
            Version *v = versions->at(i);
            f += "\n"+v->toString();
        }

        f += "[/VERSIONS]\n";
        f += "[/ARTICLE]\n";

    return f;
}

/*!
 * \brief Multimedia::toString
 * \return Fonction permettant de transformer un objet Multimédia en chaine de caractère en suivant un modèle spécifique.
 */
QString Multimedia::toString() const {

    QString f;
        f = "[MULTIMEDIA]\n";
        f += "  id : " + id + "\n";
        f += "  title : " + title + "\n";
        f += "  createdOn : " + createdOn.toString() + "\n";
        f += "  lastModifOn : " + lastModifOn.toString() + "\n";
        f += "  description : " + description + "\n";
        f += "  fileName : " + fileName + "\n";
        f += "  type : " + getTypeToQString() + "\n";
        f += "[VERSIONS][size=" + QString::number(versions->size()) + "]\n";

        for(unsigned int i = 0; i < versions->size(); i++){
            Version *v = versions->at(i);
            f += "\n"+v->toString();
        }

        f += "[/VERSIONS]\n";
        f += "[/MULTIMEDIA]\n";

    return f;
}

/*!
 * \brief Task::toString
 * \return Fonction permettant de transformer un objet Tache en chaine de caractère en suivant un modèle spécifique.
 */
QString Task::toString() const {

    QString f;
        f = "[TASK]\n";
        f += "  id : " + id + "\n";
        f += "  title : " + title + "\n";
        f += "  createdOn : " + createdOn.toString() + "\n";
        f += "  lastModifOn : " + lastModifOn.toString() + "\n";
        f += "  action : " + action  + "\n";
        f += "  priority : " + QString::number(priority) + "\n";
        f += "  status : " + getStatusToString() + "\n";
        f += "  toBeDoneOn : " + toBeDoneOn.toString() + "\n";
        f += "[VERSIONS][size=" + QString::number(versions->size()) + "]\n";

        for(unsigned int i = 0; i < versions->size(); i++){
            Version *v = versions->at(i);
            f += "\n"+v->toString();
        }

        f += "[/VERSIONS]\n";
        f += "[/TASK]\n";

    return f;
}
