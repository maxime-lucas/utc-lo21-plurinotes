#include "p_xml.h"

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
    QString tmp;
    QDateTime createdOn,lastModifOn;

    std::vector<Article*> tab;

    for(;!article.isNull(); article = article.nextSiblingElement("article")) {

        //Convertion de Qstring de l'XML en QDateTime

        tmp = article.firstChildElement("createdOn").text();
        createdOn.fromString(tmp,"yyyy:MM:dd hh:mm:ss");
        tmp = article.firstChildElement("lastModifOn").text();
        lastModifOn.fromString(tmp,"yyyy:MM:dd hh:mm:ss");

        Article *a = new Article(
            article.firstChildElement("id").text(),
            article.firstChildElement("title").text(),
            createdOn,
            lastModifOn,
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
    QString tmp;
    QDateTime createdOn,lastModifOn;

    std::vector<Multimedia*> tab;

    for(;!multimedia.isNull(); multimedia = multimedia.nextSiblingElement("multimedia")) {

        //Convertion de Qstring de l'XML en QDateTime

        tmp = multimedia.firstChildElement("createdOn").text();
        createdOn.fromString(tmp,"yyyy:MM:dd hh:mm:ss");
        tmp = multimedia.firstChildElement("lastModifOn").text();
        lastModifOn.fromString(tmp,"yyyy:MM:dd hh:mm:ss");

        Multimedia *a = new Multimedia(
            multimedia.firstChildElement("id").text(),
            multimedia.firstChildElement("title").text(),
            createdOn,
            lastModifOn
        );

        tab.push_back(a);
    }

    return tab;
}

std::vector<Task*> XMLManager::getAllActiveTasks() const {
    QDomElement root = dom->firstChildElement("plurinotes");
    QDomElement activeNotes = root.firstChildElement("activeNotes");
    QDomElement tasks = activeNotes.firstChildElement("tasks");
    QDomElement task = tasks.firstChildElement("task");
    QString tmp;
    QDateTime createdOn,lastModifOn,Deadline;
    unsigned int priority;
    TaskStatus status;

    std::vector<Task*> tab;

    for(;!task.isNull(); task = task.nextSiblingElement("task")) {

        //Convertion de Qstring de l'XML en QDateTime

        tmp = task.firstChildElement("createdOn").text();
        createdOn.fromString(tmp,"yyyy:MM:dd hh:mm:ss");
        tmp = task.firstChildElement("lastModifOn").text();
        lastModifOn.fromString(tmp,"yyyy:MM:dd hh:mm:ss");
        tmp = task.firstChildElement("Deadline").text();
        Deadline.fromString(tmp,"yyyy:MM:dd hh:mm:ss");

        //Convertion de QString en unisgned int

        //Convertion de QString en taskSatus

        Task *a = new Task(
            task.firstChildElement("id").text(),
            task.firstChildElement("title").text(),
            createdOn,
            lastModifOn,
            task.firstChildElement("action").text(),
            priority,
            Deadline,
        );

        tab.push_back(a);
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

    newArticle.appendChild(aID);
    newArticle.appendChild(aTitle);
    newArticle.appendChild(aCreatedOn);
    newArticle.appendChild(aLastModifOn);
    newArticle.appendChild(aText);

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
        QDomElement tDeadline = dom->createElement("Deadline");
            tDeadline.appendChild(dom->createTextNode(t->getDeadline().toString()));
        QDomElement tStatus = dom->createElement("status");

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
