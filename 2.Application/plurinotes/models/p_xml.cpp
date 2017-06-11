#include "main.h"
#include "p_xml.h"
#include "p_core.h"


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

        createdOn = article.firstChildElement("createdOn").text();
        lastModifOn = article.firstChildElement("lastModifOn").text();

        Article *a = new Article(
            article.firstChildElement("id").text(),
            article.firstChildElement("title").text(),
            QDateTime::fromString(createdOn),
            QDateTime::fromString(lastModifOn),
            article.firstChildElement("text").text()
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

        createdOn = multimedia.firstChildElement("createdOn").text();
        lastModifOn = multimedia.firstChildElement("lastModifOn").text();

        enum TypeMultimedia type;
        if( multimedia.firstChildElement("type").text() == "picture" ) type = PICTURE;
        else if( multimedia.firstChildElement("type").text() == "video" ) type = VIDEO;
        else type = AUDIO;

        Multimedia *m = new Multimedia(
            multimedia.firstChildElement("id").text(),
            multimedia.firstChildElement("title").text(),
            QDateTime::fromString(createdOn),
            QDateTime::fromString(lastModifOn),
            multimedia.firstChildElement("description").text(),
            multimedia.firstChildElement("fileName").text(),
            type
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

        createdOn = task.firstChildElement("createdOn").text();
        lastModifOn = task.firstChildElement("lastModifOn").text();
        deadline = task.firstChildElement("deadline").text();

        //Convertion de QString en unisgned int
        bool ok;
        priority = task.firstChildElement("priority").text().toInt(&ok,10);


        //Convertion de QString en taskSatus

        if(task.firstChildElement("status").text() == "PENDING")
            status = PENDING;
        else if(task.firstChildElement("status").text() == "PROGRESS")
            status = PROGRESS;
        else if(task.firstChildElement("status").text() == "FINISHED")
            status = FINISHED;

        Task *t = new Task(

            task.firstChildElement("id").text(),
            task.firstChildElement("title").text(),
            QDateTime::fromString(createdOn),
            QDateTime::fromString(lastModifOn),
            task.firstChildElement("action").text(),
            priority,
            QDateTime::fromString(deadline),
            status
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
            QString conv =QString::number(t->getPriority());
            tPriority.appendChild(dom->createTextNode(conv));
        QDomElement tDeadline = dom->createElement("deadline");
            tDeadline.appendChild(dom->createTextNode(t->getDeadline().toString()));
        QDomElement tStatus = dom->createElement("status");
        QDomElement tVersions = dom->createElement("versions");


        QString status;

        if(t->getStatus() == PENDING)
            status = "PENDING";
        else if(t->getStatus() == PROGRESS)
            status = "PROGRESS";
        else if(t->getStatus() == FINISHED)
            status = "FINISHED";

            tStatus.appendChild(dom->createTextNode(status));

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

XMLManager::~XMLManager() {
    doc.close();
}
