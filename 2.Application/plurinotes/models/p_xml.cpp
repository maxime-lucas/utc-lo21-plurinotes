#include <QMessageBox>
#include <QTextStream>
#include <typeinfo>

#include "main.h"
#include "p_xml.h"
#include "p_core.h"
#include "p_versions.h"


XMLManager::XMLManager(const QString &path ) : QWidget()  {
    dom = new QDomDocument("XMLManagerDom");
    pathToFile = path;
    QFile doc(path);

    if(!doc.open(QIODevice::ReadOnly)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    if (!dom->setContent(&doc)) {
        doc.close();
        QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre attribue a l'objet QDomDocument.");
        return;
    }
    doc.close();
}

std::vector<Article*> XMLManager::getAllActiveArticles() const {

    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement articles = activeNotes.firstChildElement("articles");
    QDomElement article = articles.firstChildElement("article");
    QString createdOn,lastModifOn;

    std::vector<Article*> tab;

    for(;!article.isNull(); article = article.nextSiblingElement("article")) {

        std::vector<Version*> *versionsTab = new std::vector<Version*>;

        createdOn = article.firstChildElement("createdOn").text();
        lastModifOn = article.firstChildElement("lastModifOn").text();

        QDomElement versions = article.firstChildElement("versions");
        QDomElement version = versions.firstChildElement("version");

        for(;!version.isNull(); version = version.nextSiblingElement("version")) {

            unsigned int numVersion = version.firstChildElement("numVersion").text().toInt();

            Article *aV = new Article(
                version.firstChildElement("article").firstChildElement("id").text(),
                version.firstChildElement("article").firstChildElement("title").text(),
                QDateTime::fromString(version.firstChildElement("article").firstChildElement("createdOn").text()),
                QDateTime::fromString(version.firstChildElement("article").firstChildElement("lastModifOn").text()),
                version.firstChildElement("article").firstChildElement("text").text()
            );

            Version *v = new Version(numVersion,aV);

            versionsTab->push_back(v);
        }

        Article *a = new Article(
            article.firstChildElement("id").text(),
            article.firstChildElement("title").text(),
            QDateTime::fromString(createdOn),
            QDateTime::fromString(lastModifOn),
            article.firstChildElement("text").text(),
            versionsTab
        );

        tab.push_back(a);
    }

    return tab;
}

std::vector<Multimedia*> XMLManager::getAllActiveMultimedia() const {
    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement multimedias = activeNotes.firstChildElement("multimedias");
    QDomElement multimedia = multimedias.firstChildElement("multimedia");
    QString createdOn,lastModifOn;

    std::vector<Multimedia*> tab;

    for(;!multimedia.isNull(); multimedia = multimedia.nextSiblingElement("multimedia")) {

        std::vector<Version*> *versionsTab = new std::vector<Version*>;

        createdOn = multimedia.firstChildElement("createdOn").text();
        lastModifOn = multimedia.firstChildElement("lastModifOn").text();

        enum TypeMultimedia type;
        if( multimedia.firstChildElement("type").text() == "picture" ) type = PICTURE;
        else if( multimedia.firstChildElement("type").text() == "video" ) type = VIDEO;
        else type = AUDIO;

        QDomElement versions = multimedia.firstChildElement("versions");
        QDomElement version = versions.firstChildElement("version");

        for(;!version.isNull(); version = version.nextSiblingElement("version")) {

            unsigned int numVersion = version.firstChildElement("numVersion").text().toInt();

            enum TypeMultimedia typeV;
            if( version.firstChildElement("multimedia").firstChildElement("type").text() == "picture" ) typeV = PICTURE;
            else if( version.firstChildElement("multimedia").firstChildElement("type").text() == "video" ) typeV = VIDEO;
            else type = AUDIO;

            Multimedia *mV = new Multimedia(
                version.firstChildElement("multimedia").firstChildElement("id").text(),
                version.firstChildElement("multimedia").firstChildElement("title").text(),
                QDateTime::fromString(version.firstChildElement("multimedia").firstChildElement("createdOn").text()),
                QDateTime::fromString(version.firstChildElement("multimedia").firstChildElement("lastModifOn").text()),
                version.firstChildElement("multimedia").firstChildElement("description").text(),
                version.firstChildElement("multimedia").firstChildElement("fileName").text(),
                typeV
            );

            Version *v = new Version(numVersion,mV);

            versionsTab->push_back(v);
        }

        Multimedia *m = new Multimedia(
            multimedia.firstChildElement("id").text(),
            multimedia.firstChildElement("title").text(),
            QDateTime::fromString(createdOn),
            QDateTime::fromString(lastModifOn),
            multimedia.firstChildElement("description").text(),
            multimedia.firstChildElement("fileName").text(),
            type,
            versionsTab
        );

        tab.push_back(m);
    }

    return tab;
}

std::vector<Task*> XMLManager::getAllActiveTasks() const {
    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement tasks = activeNotes.firstChildElement("tasks");
    QDomElement task = tasks.firstChildElement("task");    
    unsigned int priority;
    TaskStatus status;
    QString createdOn,lastModifOn,deadline;

    std::vector<Task*> tab;

    for(;!task.isNull(); task = task.nextSiblingElement("task")) {

        //Convertion de QString en unisgned int
        bool ok;
        priority = task.firstChildElement("priority").text().toInt(&ok,10);

        //Convertion de QString en taskSatus

        if(task.firstChildElement("status").text() == "0")
            status = PENDING;
        else if(task.firstChildElement("status").text() == "1")
            status = PROGRESS;
        else if(task.firstChildElement("status").text() == "2")
            status = FINISHED;

        std::vector<Version*> *versionsTab = new std::vector<Version*>;

        QDomElement versions = task.firstChildElement("versions");
        QDomElement version = versions.firstChildElement("version");

        for(;!version.isNull(); version = version.nextSiblingElement("version")) {

            unsigned int numVersion = version.firstChildElement("numVersion").text().toInt();

            TaskStatus statusV;

            if(version.firstChildElement("task").firstChildElement("status").text() == "0")
                statusV = PENDING;
            else if(version.firstChildElement("task").firstChildElement("status").text() == "1")
                statusV = PROGRESS;
            else if(version.firstChildElement("task").firstChildElement("status").text() == "2")
                statusV = FINISHED;

            unsigned int priorityV = version.firstChildElement("task").firstChildElement("priority").text().toInt(&ok,10);

            Task *tV = new Task(

                version.firstChildElement("task").firstChildElement("id").text(),
                version.firstChildElement("task").firstChildElement("title").text(),
                QDateTime::fromString(version.firstChildElement("task").firstChildElement("createdOn").text()),
                QDateTime::fromString(version.firstChildElement("task").firstChildElement("lastModifOn").text()),
                version.firstChildElement("task").firstChildElement("action").text(),
                priorityV,
                QDateTime::fromString(version.firstChildElement("task").firstChildElement("deadline").text()),
                statusV
            );

            Version *v = new Version(numVersion,tV);

            versionsTab->push_back(v);
        }

        Task *t = new Task(

            task.firstChildElement("id").text(),
            task.firstChildElement("title").text(),
            QDateTime::fromString(task.firstChildElement("createdOn").text()),
            QDateTime::fromString(task.firstChildElement("lastModifOn").text()),
            task.firstChildElement("action").text(),
            priority,
            QDateTime::fromString(task.firstChildElement("deadline").text()),
            status,
            versionsTab
        );

        tab.push_back(t);
    }

    return tab;
}

void XMLManager::insertIntoArticle(Article*a) {
    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement articles = activeNotes.firstChildElement("articles");

    QDomElement newArticle = dom->createElement("article");
        QDomElement aID = dom->createElement("id");
            aID.appendChild(dom->createTextNode(a->getId()));
        QDomElement aTitle = dom->createElement("title");
            aTitle.appendChild(dom->createTextNode(a->getTitle()));
        QDomElement aCreatedOn = dom->createElement("createdOn");
            aCreatedOn.appendChild(dom->createTextNode(a->getCreatedOn().toString()));
        QDomElement aLastModifOn = dom->createElement("lastModifOn");
            aLastModifOn.appendChild(dom->createTextNode(a->getLastModifOn().toString()));
        QDomElement aText = dom->createElement("text");
            aText.appendChild(dom->createTextNode(a->getText()));
        QDomElement aVersions = dom->createElement("versions");

    newArticle.appendChild(aID);
    newArticle.appendChild(aTitle);
    newArticle.appendChild(aCreatedOn);
    newArticle.appendChild(aLastModifOn);
    newArticle.appendChild(aText);
    newArticle.appendChild(aVersions);

    articles.appendChild(newArticle);

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;
}

void XMLManager::insertIntoMultimedia(Multimedia*m) {
    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement multimedias = activeNotes.firstChildElement("multimedias");

    QDomElement newMultimedia = dom->createElement("multimedia");
        QDomElement mID = dom->createElement("id");
            mID.appendChild(dom->createTextNode(m->getId()));
        QDomElement mTitle = dom->createElement("title");
            mTitle.appendChild(dom->createTextNode(m->getTitle()));
        QDomElement mCreatedOn = dom->createElement("createdOn");
            mCreatedOn.appendChild(dom->createTextNode(m->getCreatedOn().toString()));
        QDomElement mLastModifOn = dom->createElement("lastModifOn");
            mLastModifOn.appendChild(dom->createTextNode(m->getLastModifOn().toString()));
        QDomElement mDescription = dom->createElement("description");
            mDescription.appendChild(dom->createTextNode(m->getDescription()));
        QDomElement mFileName = dom->createElement("fileName");
            mFileName.appendChild(dom->createTextNode(m->getFileName()));
        QDomElement mType = dom->createElement("type");
            if(m->getType() == AUDIO ) mType.appendChild(dom->createTextNode("audio"));
            else if(m->getType() == VIDEO ) mType.appendChild(dom->createTextNode("video"));
            else mType.appendChild(dom->createTextNode("picture"));
        QDomElement mVersions = dom->createElement("versions");


    newMultimedia.appendChild(mID);
    newMultimedia.appendChild(mTitle);
    newMultimedia.appendChild(mCreatedOn);
    newMultimedia.appendChild(mLastModifOn);
    newMultimedia.appendChild(mDescription);
    newMultimedia.appendChild(mFileName);
    newMultimedia.appendChild(mType);
    newMultimedia.appendChild(mVersions);

    multimedias.appendChild(newMultimedia);

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;
}

void XMLManager::insertIntoTask(Task*t) {
    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement tasks = activeNotes.firstChildElement("tasks");

    QDomElement newtask = dom->createElement("task");
        QDomElement tID = dom->createElement("id");
            tID.appendChild(dom->createTextNode(t->getId()));
        QDomElement tTitle = dom->createElement("title");
            tTitle.appendChild(dom->createTextNode(t->getTitle()));
        QDomElement tCreatedOn = dom->createElement("createdOn");
            tCreatedOn.appendChild(dom->createTextNode(t->getCreatedOn().toString()));
        QDomElement tLastModifOn = dom->createElement("lastModifOn");
            tLastModifOn.appendChild(dom->createTextNode(t->getLastModifOn().toString()));
        QDomElement tAction = dom->createElement("action");
            tAction.appendChild(dom->createTextNode(t->getAction()));
        QDomElement tPriority = dom->createElement("priority");
            tPriority.appendChild(dom->createTextNode(QString::number(t->getPriority())));
        QDomElement tDeadline = dom->createElement("deadline");
            tDeadline.appendChild(dom->createTextNode(t->getDeadline().toString()));
        QDomElement tStatus = dom->createElement("status");
            if(t->getStatus() == PENDING) tStatus.appendChild(dom->createTextNode("0"));
            else if(t->getStatus() == PROGRESS) tStatus.appendChild(dom->createTextNode("1"));
            else tStatus.appendChild(dom->createTextNode("2"));
        QDomElement tVersions = dom->createElement("versions");


    newtask.appendChild(tID);
    newtask.appendChild(tTitle);
    newtask.appendChild(tCreatedOn);
    newtask.appendChild(tLastModifOn);
    newtask.appendChild(tAction);
    newtask.appendChild(tPriority);
    newtask.appendChild(tDeadline);
    newtask.appendChild(tStatus);
    newtask.appendChild(tVersions);

    tasks.appendChild(newtask);

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;
}

void XMLManager::insertIntoRelation(Relation*r) {
    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement relations = root.firstChildElement("relations");

        QDomElement relation = dom->createElement("relation");
            QDomElement rId = dom->createElement("id");
                rId.appendChild(dom->createTextNode(r->getId()));
            QDomElement rTitle = dom->createElement("title");
                rTitle.appendChild(dom->createTextNode(r->getTitle()));
            QDomElement rDescription = dom->createElement("description");
                rDescription.appendChild(dom->createTextNode(r->getDesc()));
            QDomElement rIsOriented = dom->createElement("isOriented");
                if( r->getOriented() ) rIsOriented.appendChild(dom->createTextNode("TRUE"));
                else rIsOriented.appendChild(dom->createTextNode("FALSE"));
            QDomElement rCouples = dom->createElement("couples");

        relation.appendChild(rId);
        relation.appendChild(rTitle);
        relation.appendChild(rDescription);
        relation.appendChild(rIsOriented);
        relation.appendChild(rCouples);
    relations.appendChild(relation);

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;
}

void XMLManager::insertIntoCouple(Couple*c) {
    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement couples = root.firstChildElement("couples");

        QDomElement couple = dom->createElement("couple");
            QDomElement cId = dom->createElement("id");
                cId.appendChild(dom->createTextNode(c->getId()));
            QDomElement cLabel = dom->createElement("label");
                cLabel.appendChild(dom->createTextNode(c->getLabel()));
            QDomElement cNoteX = dom->createElement("noteX");
                cNoteX.appendChild(dom->createTextNode(c->getX()->getId()));
            QDomElement cNoteY = dom->createElement("noteY");
                cNoteY.appendChild(dom->createTextNode(c->getY()->getId()));

        couple.appendChild(cId);
        couple.appendChild(cLabel);
        couple.appendChild(cNoteX);
        couple.appendChild(cNoteY);

    couples.appendChild(couple);

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;
}

void XMLManager::insertIntoRelationCouple(Relation*r,Couple*c) {
    /*QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement relations = root.firstChildElement("relations");

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;*/
}

void XMLManager::deleteFromArticle(Article *a) {
    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement articles = activeNotes.firstChildElement("articles");

    QDomNodeList nodes = articles.elementsByTagName("article");
    for (int i = 0; i < nodes.count(); ++i)
    {
        QDomNode node = nodes.at(i);
        QDomElement child = node.firstChildElement("id");
        if (child.text() == a->getId())
        {
            articles.removeChild(node);
        }
    }

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;

}

void XMLManager::deleteFromMultimedia(Multimedia *a) {

    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement multimedias = activeNotes.firstChildElement("multimedias");

    QDomNodeList nodes = multimedias.elementsByTagName("multimedia");
    for (int i = 0; i < nodes.count(); ++i)
    {
        QDomNode node = nodes.at(i);
        QDomElement child = node.firstChildElement("id");
        if (child.text() == a->getId())
        {
            multimedias.removeChild(node);
        }
    }

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;

}

void XMLManager::deleteFromTask(Task *a) {

    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement tasks = activeNotes.firstChildElement("tasks");

    QDomNodeList nodes = tasks.elementsByTagName("task");
    for (int i = 0; i < nodes.count(); ++i)
    {
        QDomNode node = nodes.at(i);
        QDomElement child = node.firstChildElement("id");
        if (child.text() == a->getId())
        {
            tasks.removeChild(node);
        }
    }

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;

}

unsigned int XMLManager::getLastId() const {
    unsigned int lastID = 0;
    unsigned int foundID = 0;

    // On cherche dans les notes actives
    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");

        // Articles
        QDomElement articles = activeNotes.firstChildElement("articles");
        QDomElement article = articles.firstChildElement("article");
        for(;!article.isNull(); article = article.nextSiblingElement("article")) {
            foundID = article.firstChildElement("id").text().toInt(0,10);
            if(foundID > lastID) lastID = foundID;
        }

        // Multimedia
        QDomElement multimedias = activeNotes.firstChildElement("multimedias");
        QDomElement multimedia = multimedias.firstChildElement("multimedia");
        for(;!multimedia.isNull(); multimedia = multimedia.nextSiblingElement("multimedia")) {
            foundID = multimedia.firstChildElement("id").text().toInt(0,10);
            if(foundID > lastID) lastID = foundID;
        }

        // Tasks
        QDomElement tasks = activeNotes.firstChildElement("tasks");
        QDomElement task = tasks.firstChildElement("task");
        for(;!task.isNull(); task = task.nextSiblingElement("task")) {
            foundID = task.firstChildElement("id").text().toInt(0,10);
            if(foundID > lastID) lastID = foundID;
        }

    // On cherche dans les notes archivées
    QDomElement archivedNotes = root.firstChildElement("archivedNotes");

        // Articles
        articles = archivedNotes.firstChildElement("articles");
        article = articles.firstChildElement("article");
        for(;!article.isNull(); article = article.nextSiblingElement("article")) {
            foundID = article.firstChildElement("id").text().toInt(0,10);
            if(foundID > lastID) lastID = foundID;
        }

        // Multimedia
        multimedias = archivedNotes.firstChildElement("multimedias");
        multimedia = multimedias.firstChildElement("multimedia");
        for(;!multimedia.isNull(); multimedia = multimedia.nextSiblingElement("multimedia")) {
            foundID = multimedia.firstChildElement("id").text().toInt(0,10);
            if(foundID > lastID) lastID = foundID;
        }

        // Tasks
        tasks = archivedNotes.firstChildElement("tasks");
        task = tasks.firstChildElement("task");
        for(;!task.isNull(); task = task.nextSiblingElement("task")) {
            foundID = task.firstChildElement("id").text().toInt(0,10);
            if(foundID > lastID) lastID = foundID;
        }

    return lastID;
}

void XMLManager::updateArticle(Article* oldA,Article* newA) {

    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement articles = activeNotes.firstChildElement("articles");
    QDomElement article = articles.firstChildElement("article");

    for(;!article.isNull(); article = article.nextSiblingElement("article")) {

        if( article.firstChildElement("id").text() == oldA->getId() ) {

            QDomElement versions = article.firstChildElement("versions");
                QDomElement version = dom->createElement("version");
                    QDomElement numVersion = dom->createElement("numVersion");
                        numVersion.appendChild(dom->createTextNode(QString::number(versions.childNodes().size() + 1 )));
                    QDomElement versionArticle = dom->createElement("article");
                        QDomElement aID = dom->createElement("id");
                            aID.appendChild(dom->createTextNode(oldA->getId()));
                        QDomElement aTitle = dom->createElement("title");
                            aTitle.appendChild(dom->createTextNode(oldA->getTitle()));
                        QDomElement aCreatedOn = dom->createElement("createdOn");
                            aCreatedOn.appendChild(dom->createTextNode(oldA->getCreatedOn().toString()));
                        QDomElement aLastModifOn = dom->createElement("lastModifOn");
                            aLastModifOn.appendChild(dom->createTextNode(oldA->getLastModifOn().toString()));
                        QDomElement aText = dom->createElement("text");
                            aText.appendChild(dom->createTextNode(oldA->getText()));
                        versionArticle.appendChild(aID);
                        versionArticle.appendChild(aTitle);
                        versionArticle.appendChild(aCreatedOn);
                        versionArticle.appendChild(aLastModifOn);
                        versionArticle.appendChild(aText);

                    version.appendChild(numVersion);
                    version.appendChild(versionArticle);
                versions.appendChild(version);

            QDomElement oTitle = article.firstChildElement("title");
                oTitle.removeChild(oTitle.childNodes().at(0));
                oTitle.appendChild(dom->createTextNode(newA->getTitle()));
            QDomElement oText = article.firstChildElement("text");
                oText.removeChild(oText.childNodes().at(0));
                oText.appendChild(dom->createTextNode(newA->getText()));
            QDomElement oLastModifOn = article.firstChildElement("lastModifOn");
                oLastModifOn.removeChild(oLastModifOn.childNodes().at(0));
                oLastModifOn.appendChild(dom->createTextNode(newA->getLastModifOn().toString()));
        }

    }

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;

}

void XMLManager::updateMultimedia(Multimedia* oldA,Multimedia* newA) {

    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement multimedias = activeNotes.firstChildElement("multimedias");
    QDomElement multimedia = multimedias.firstChildElement("multimedia");

    for(;!multimedia.isNull(); multimedia = multimedia.nextSiblingElement("multimedia")) {

        if( multimedia.firstChildElement("id").text() == oldA->getId() ) {

            QDomElement versions = multimedia.firstChildElement("versions");
                QDomElement version = dom->createElement("version");
                    QDomElement numVersion = dom->createElement("numVersion");
                        numVersion.appendChild(dom->createTextNode(QString::number(versions.childNodes().size() + 1 )));
                    QDomElement versionMultimedia = dom->createElement("multimedia");
                        QDomElement mID = dom->createElement("id");
                            mID.appendChild(dom->createTextNode(oldA->getId()));
                        QDomElement mTitle = dom->createElement("title");
                            mTitle.appendChild(dom->createTextNode(oldA->getTitle()));
                        QDomElement mCreatedOn = dom->createElement("createdOn");
                            mCreatedOn.appendChild(dom->createTextNode(oldA->getCreatedOn().toString()));
                        QDomElement mLastModifOn = dom->createElement("lastModifOn");
                            mLastModifOn.appendChild(dom->createTextNode(oldA->getLastModifOn().toString()));
                        QDomElement mDescription = dom->createElement("description");
                            mDescription.appendChild(dom->createTextNode(oldA->getDescription()));
                        QDomElement mFileName = dom->createElement("fileName");
                            mFileName.appendChild(dom->createTextNode(oldA->getFileName()));
                        QDomElement mType = dom->createElement("type");
                            if(oldA->getType() == AUDIO ) mType.appendChild(dom->createTextNode("audio"));
                            else if(oldA->getType() == VIDEO ) mType.appendChild(dom->createTextNode("video"));
                            else mType.appendChild(dom->createTextNode("picture"));

                        versionMultimedia.appendChild(mID);
                        versionMultimedia.appendChild(mTitle);
                        versionMultimedia.appendChild(mCreatedOn);
                        versionMultimedia.appendChild(mLastModifOn);
                        versionMultimedia.appendChild(mDescription);
                        versionMultimedia.appendChild(mFileName);
                        versionMultimedia.appendChild(mType);

                    version.appendChild(numVersion);
                    version.appendChild(versionMultimedia);
                versions.appendChild(version);

            QDomElement oTitle = multimedia.firstChildElement("title");
                oTitle.removeChild(oTitle.childNodes().at(0));
                oTitle.appendChild(dom->createTextNode(newA->getTitle()));
            QDomElement oDescription = multimedia.firstChildElement("description");
                oDescription.removeChild(oDescription.childNodes().at(0));
                oDescription.appendChild(dom->createTextNode(newA->getDescription()));
            QDomElement oLastModifOn = multimedia.firstChildElement("lastModifOn");
                oLastModifOn.removeChild(oLastModifOn.childNodes().at(0));
                oLastModifOn.appendChild(dom->createTextNode(newA->getLastModifOn().toString()));
        }

    }

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;

}

void XMLManager::updateTask(Task* oldA,Task* newA) {

    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement tasks = activeNotes.firstChildElement("tasks");
    QDomElement task = tasks.firstChildElement("task");

    for(;!task.isNull(); task = task.nextSiblingElement("task")) {

        if( task.firstChildElement("id").text() == oldA->getId() ) {

            QDomElement versions = task.firstChildElement("versions");
                QDomElement version = dom->createElement("version");
                    QDomElement numVersion = dom->createElement("numVersion");
                        numVersion.appendChild(dom->createTextNode(QString::number(versions.childNodes().size() + 1 )));
                    QDomElement versionTask = dom->createElement("task");
                        QDomElement tID = dom->createElement("id");
                            tID.appendChild(dom->createTextNode(oldA->getId()));
                        QDomElement tTitle = dom->createElement("title");
                            tTitle.appendChild(dom->createTextNode(oldA->getTitle()));
                        QDomElement tCreatedOn = dom->createElement("createdOn");
                            tCreatedOn.appendChild(dom->createTextNode(oldA->getCreatedOn().toString()));
                        QDomElement tLastModifOn = dom->createElement("lastModifOn");
                            tLastModifOn.appendChild(dom->createTextNode(oldA->getLastModifOn().toString()));
                        QDomElement tAction = dom->createElement("action");
                            tAction.appendChild(dom->createTextNode(oldA->getAction()));
                        QDomElement tPriority = dom->createElement("priority");
                            QString conv =QString::number(oldA->getPriority());
                            tPriority.appendChild(dom->createTextNode(conv));
                        QDomElement tDeadline = dom->createElement("deadline");
                            tDeadline.appendChild(dom->createTextNode(oldA->getDeadline().toString()));
                        QDomElement tStatus = dom->createElement("status");
                            if(oldA->getStatus() == PENDING) tStatus.appendChild(dom->createTextNode("0"));
                            else if(oldA->getStatus() == PROGRESS) tStatus.appendChild(dom->createTextNode("1"));
                            else tStatus.appendChild(dom->createTextNode("2"));

                        versionTask.appendChild(tID);
                        versionTask.appendChild(tTitle);
                        versionTask.appendChild(tCreatedOn);
                        versionTask.appendChild(tLastModifOn);
                        versionTask.appendChild(tAction);
                        versionTask.appendChild(tPriority);
                        versionTask.appendChild(tDeadline);
                        versionTask.appendChild(tStatus);

                    version.appendChild(numVersion);
                    version.appendChild(versionTask);
                versions.appendChild(version);

            QDomElement oTitle = task.firstChildElement("title");
                oTitle.removeChild(oTitle.childNodes().at(0));
                oTitle.appendChild(dom->createTextNode(newA->getTitle()));
            QDomElement oAction = task.firstChildElement("action");
                oAction.removeChild(oAction.childNodes().at(0));
                oAction.appendChild(dom->createTextNode(newA->getAction()));
            QDomElement oPriority = task.firstChildElement("priority");
                oPriority.removeChild(oPriority.childNodes().at(0));
                oPriority.appendChild(dom->createTextNode(QString::number(newA->getPriority())));
            QDomElement oDeadline = task.firstChildElement("deadline");
                oDeadline.removeChild(oDeadline.childNodes().at(0));
                oDeadline.appendChild(dom->createTextNode(newA->getDeadline().toString()));
            QDomElement oStatus = task.firstChildElement("status");
                oStatus.removeChild(oStatus.childNodes().at(0));
                if(newA->getStatus() == PENDING) oStatus.appendChild(dom->createTextNode("0"));
                else if(newA->getStatus() == PROGRESS) oStatus.appendChild(dom->createTextNode("1"));
                else oStatus.appendChild(dom->createTextNode("2"));
            QDomElement oLastModifOn = task.firstChildElement("lastModifOn");
                oLastModifOn.removeChild(oLastModifOn.childNodes().at(0));
                oLastModifOn.appendChild(dom->createTextNode(newA->getLastModifOn().toString()));
        }

    }

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;

}

void XMLManager::deleteNoteVersion(Note*n,Version*v) {

    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");

    QDomElement notes;
    QDomElement note;
    if(typeid(*n) == typeid(Article)) {
        notes =  activeNotes.firstChildElement("articles");
        note = notes.firstChildElement("article");
    } else if (typeid(*n) == typeid(Multimedia)) {
        notes =  activeNotes.firstChildElement("multimedias");
        note = notes.firstChildElement("multimedia");
    } else {
        notes =  activeNotes.firstChildElement("tasks");
        note = notes.firstChildElement("task");
    }

    for(;!note.isNull(); note = note.nextSiblingElement(note.text())) {

        if( note.firstChildElement("id").text() == n->getId() ) {

            QDomElement versions = note.firstChildElement("versions");
            QDomElement version = versions.firstChildElement("version");

            while(!version.isNull()) {
                QDomElement nextSibling = version.nextSiblingElement("version");

                QDomElement numVersion = version.firstChildElement("numVersion");

                if( (unsigned)numVersion.text().toInt() >= v->getNumVersion() ) {
                    versions.removeChild(version);

                    version = nextSibling;
                }
                else {
                    version = version.nextSiblingElement("version");
                }
            }
        }
    }

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;
}

void XMLManager::restoreNoteVersion(Note*n,Version*v) {

    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");

    QDomElement notes;
    QDomElement note;

    if(typeid(*n) == typeid(Article)) {
        notes =  activeNotes.firstChildElement("articles");
        note = notes.firstChildElement("article");
    } else if (typeid(*n) == typeid(Multimedia)) {
        notes =  activeNotes.firstChildElement("multimedias");
        note = notes.firstChildElement("multimedia");
    } else {
        notes =  activeNotes.firstChildElement("tasks");
        note = notes.firstChildElement("task");
    }

    for(;!note.isNull(); note = note.nextSiblingElement(note.text())) {

        if( note.firstChildElement("id").text() == n->getId() ) {

            QDomElement versions = note.firstChildElement("versions");
            QDomElement version = versions.firstChildElement("version");

            for(;!version.isNull(); version = version.nextSiblingElement("version")) {

                if( (unsigned)version.firstChildElement("numVersion").text().toInt() == v->getNumVersion() ) {

                    if(typeid(*n) == typeid(Article)) {

                        Article *aFromVersion = new Article(dynamic_cast<Article&>(*(v->getState())));

                        QDomElement oTitle = note.firstChildElement("title");
                            oTitle.removeChild(oTitle.childNodes().at(0));
                            oTitle.appendChild(dom->createTextNode(aFromVersion->getTitle()));
                        QDomElement oText = note.firstChildElement("text");
                            oText.removeChild(oText.childNodes().at(0));
                            oText.appendChild(dom->createTextNode(aFromVersion->getText()));
                        QDomElement oLastModifOn = note.firstChildElement("lastModifOn");
                            oLastModifOn.removeChild(oLastModifOn.childNodes().at(0));
                            oLastModifOn.appendChild(dom->createTextNode(QDateTime::currentDateTime().toString()));
                        note.removeChild(versions);
                        note.appendChild(dom->createElement("versions"));

                    } else if (typeid(*n) == typeid(Multimedia)) {

                        Multimedia *mFromVersion = new Multimedia(dynamic_cast<Multimedia&>(*(v->getState())));

                        QDomElement oTitle = note.firstChildElement("title");
                            oTitle.removeChild(oTitle.childNodes().at(0));
                            oTitle.appendChild(dom->createTextNode(mFromVersion->getTitle()));
                        QDomElement oDescription = note.firstChildElement("description");
                            oDescription.removeChild(oDescription.childNodes().at(0));
                            oDescription.appendChild(dom->createTextNode(mFromVersion->getDescription()));
                        QDomElement oLastModifOn = note.firstChildElement("lastModifOn");
                            oLastModifOn.removeChild(oLastModifOn.childNodes().at(0));
                            oLastModifOn.appendChild(dom->createTextNode(QDateTime::currentDateTime().toString()));

                        note.removeChild(versions);
                        note.appendChild(dom->createElement("versions"));

                    } else {

                        Task *tFromVersion = new Task(dynamic_cast<Task&>(*(v->getState())));

                        QDomElement oTitle = note.firstChildElement("title");
                            oTitle.removeChild(oTitle.childNodes().at(0));
                            oTitle.appendChild(dom->createTextNode(tFromVersion->getTitle()));
                        QDomElement oAction = note.firstChildElement("action");
                            oAction.removeChild(oAction.childNodes().at(0));
                            oAction.appendChild(dom->createTextNode(tFromVersion->getAction()));
                        QDomElement oPriority = note.firstChildElement("priority");
                            oPriority.removeChild(oPriority.childNodes().at(0));
                            oPriority.appendChild(dom->createTextNode(QString::number(tFromVersion->getPriority())));
                        QDomElement oDeadline = note.firstChildElement("deadline");
                            oDeadline.removeChild(oDeadline.childNodes().at(0));
                            oDeadline.appendChild(dom->createTextNode(tFromVersion->getDeadline().toString()));
                        QDomElement oStatus = note.firstChildElement("status");
                            oStatus.removeChild(oStatus.childNodes().at(0));
                            if(tFromVersion->getStatus() == PENDING) oStatus.appendChild(dom->createTextNode("0"));
                            else if(tFromVersion->getStatus() == PROGRESS) oStatus.appendChild(dom->createTextNode("1"));
                            else oStatus.appendChild(dom->createTextNode("2"));
                        QDomElement oLastModifOn = note.firstChildElement("lastModifOn");
                            oLastModifOn.removeChild(oLastModifOn.childNodes().at(0));
                            oLastModifOn.appendChild(dom->createTextNode(QDateTime::currentDateTime().toString()));

                        note.removeChild(versions);
                        note.appendChild(dom->createElement("versions"));

                    }
                }
            }
        }
    }

    QString newDoc = dom->toString();

    QFile doc(pathToFile);
    if(!doc.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
         QMessageBox::warning(this,"Erreur a l'ouverture du document XML","Le document XML n'a pas pu etre ouvert. Verifiez que le nom est le bon et que le document est bien place");
         return;
    }

    QTextStream stream(&doc);

    stream << newDoc;
}

XMLManager::~XMLManager() {

    doc.close();
}

Note* XMLManager::getNoteById(QString id) const {
    std::vector<Article*> articles = getAllActiveArticles();
    std::vector<Multimedia*> multimedias = getAllActiveMultimedia();
    std::vector<Task*> tasks = getAllActiveTasks();

    for(unsigned int i = 0 ; i < articles.size() ; i++ ) {
        Article* article = articles.at(i);
        if( article->getId() == id ) return article;
    }

    for(unsigned int i = 0 ; i < articles.size() ; i++ ) {
        Multimedia* multimedia = multimedias.at(i);
        if( multimedia->getId() == id ) return multimedia;
    }

    for(unsigned int i = 0 ; i < articles.size() ; i++ ) {
        Task* task = tasks.at(i);
        if( task->getId() == id ) return task;
    }

    return 0;
}

Couple* XMLManager::getCoupleById(QString id) const {

    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement couples = root.firstChildElement("couples");
    QDomElement couple = couples.firstChildElement("couple");

    for(;!couple.isNull(); couple = couple.nextSiblingElement("couple")) {

        if(id == couple.firstChildElement("id").text() ) {

            Couple *newC = new Couple(
                couple.firstChildElement("label").text(),
                getNoteById(couple.firstChildElement("noteX").text()),
                getNoteById(couple.firstChildElement("noteY").text())
            );

            return newC;
        }
    }

    return 0;
}
