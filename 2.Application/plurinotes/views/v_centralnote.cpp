#include <QFileDialog>
#include <typeinfo>
#include <QMessageBox>

#include "main.h"
#include "v_centralnote.h"
#include "ui_v_centralnote.h"

V_CentralNote::V_CentralNote(QWidget *parent,V_Mainwindow* m) :
    QWidget(parent),
    ui(new Ui::V_CentralNote)
{
    parentView = m;
    ui->setupUi(this);

    parentView->connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(deleteNote()));
    parentView->connect(ui->btnEdit, SIGNAL(clicked()), this, SLOT(editNote()));

    setFixedWidth(580);
    ui->formWidget->setFixedHeight(342);
}

void V_CentralNote::deleteNote() {
    parentView->getController()->deleteByID(this->ui->labelID->text());
}

void V_CentralNote::editNote()
{
    Note* n = parentView->getController()->getApp()->getNoteByID(this->getUi()->labelID->text());

    if(typeid(*n) == typeid(Article))
    {
        V_CentralArticle* v_centralArticle = &(dynamic_cast<V_CentralArticle&>(*this));
        v_centralArticle->editArticle();
    }
    else if(typeid(*n) == typeid(Multimedia))
    {
        V_CentralMultimedia* v_centralMultimedia = &(dynamic_cast<V_CentralMultimedia&>(*this));
        v_centralMultimedia->editMultimedia();
    }
    else if(typeid(*n) == typeid(Task))
    {
        V_CentralTask* v_centralTask = &(dynamic_cast<V_CentralTask&>(*this));
        v_centralTask->editTask();
    }
}

V_CentralNote::~V_CentralNote()
{
    delete ui;
}
/*!
 * \brief V_CentralArticle::V_CentralArticle
 * \param a(article)
 * \param m(Fenetre Principal)
 *
 * Affichage d'un article dans la central View
 */
V_CentralArticle::V_CentralArticle(Article *a,V_Mainwindow* m) : V_CentralNote(0,m) {
    this->getUi()->labelType->setText("Type : Article");
    this->getUi()->labelID->setText(a->getId());
    this->getUi()->textTitle->setText(a->getTitle());
    this->getUi()->labelCreatedOn->setText(a->getCreatedOn().toString());
    this->getUi()->labelLastModifOn->setText(a->getLastModifOn().toString());

    text = new QPlainTextEdit(a->getText());
    text->setFixedWidth(500);
    QVBoxLayout *formWidgetLayout = new QVBoxLayout();
    this->getUi()->formWidget->setLayout(formWidgetLayout);

    formWidgetLayout->addWidget(text);
    formWidgetLayout->setAlignment(Qt::AlignCenter);

}

void V_CentralArticle::editArticle()
{
    if(text->toPlainText().isEmpty() || this->getUi()->textTitle->text().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");
    else {
        Article* editArticle = new Article(
                    this->getUi()->labelID->text(),
                    this->getUi()->textTitle->text(),
                    QDateTime::fromString(this->getUi()->labelCreatedOn->text()),
                    QDateTime::currentDateTime(),
                    text->toPlainText()
                    );
        this->getMainwindow()->getController()->editArticle(this->getUi()->labelID->text(),editArticle);
    }
}

/*!
 * \brief V_CentralMultimedia::V_CentralMultimedia
 * \param m(multimedia)
 * \param mw(Fenetre principal)
 *
 * Affichage d'un multimedia dans la central View
 */
V_CentralMultimedia::V_CentralMultimedia(Multimedia *m, V_Mainwindow*mw) : V_CentralNote(0,mw){
    this->getUi()->labelType->setText("Type : Multimedia/"+m->getTypeToQString());
    this->getUi()->labelID->setText(m->getId());
    this->getUi()->textTitle->setText(m->getTitle());
    this->getUi()->labelCreatedOn->setText(m->getCreatedOn().toString());
    this->getUi()->labelLastModifOn->setText(m->getLastModifOn().toString());

    desc = new QTextEdit(m->getDescription());
    desc->setFixedHeight(50);
    desc->setAlignment(Qt::AlignCenter);

    QVBoxLayout *formWidgetLayout = new QVBoxLayout();
    formWidgetLayout->addWidget(desc);

    if( m->getType() == PICTURE ) {
        QFile *file = new QFile(m->getFileName());
        QFileInfo fileInfo(file->fileName());
        QDir dirToRessources(QDir::currentPath());
        dirToRessources.cd("../plurinotes/ressources/");
        QString path(dirToRessources.absolutePath()+ QDir::separator() + m->getId() + "." + fileInfo.completeSuffix());
        QLabel *img = new QLabel(this);
        img->setFixedHeight(290);
        img->setPixmap(QPixmap(path));
        img->setAlignment(Qt::AlignCenter);
        formWidgetLayout->addWidget(img);
    }

    pathToFile = m->getFileName();
    type = m->getType();

    this->getUi()->formWidget->setLayout(formWidgetLayout);
}
/*!
 * \brief V_CentralTask::V_CentralTask
 * \param t(tache)
 * \param m(fenetre principal)
 *
 * Affichage d'une tache dans la vue principal
 */
V_CentralTask::V_CentralTask(Task *t, V_Mainwindow*m) : V_CentralNote(0,m){
    this->getUi()->labelType->setText("Type : Task/"+t->getStatusToString());
    this->getUi()->labelID->setText(t->getId());
    this->getUi()->textTitle->setText(t->getTitle());
    this->getUi()->labelCreatedOn->setText(t->getCreatedOn().toString());
    this->getUi()->labelLastModifOn->setText(t->getLastModifOn().toString());

    //ajout champ action
    action = new QLineEdit(this);
    action->setText(t->getAction());
    QFormLayout *formWidgetLayout = new QFormLayout();
    formWidgetLayout->addRow(tr("Action : "),action);

    //ajout champ Deadline
    if(!(t->getDeadline().isNull()))
    {
    deadline = new QDateTimeEdit(t->getDeadline());
    formWidgetLayout->addRow(tr("DeadLine : "),deadline);
    }

    //ajout champ priorité
    priority = new QSpinBox(this);
    priority->setValue(t->getPriority());
    formWidgetLayout->addRow(tr("Priority : "),priority);

    //ajout champ status
    pend = new QRadioButton("PENDING",this);
    prog = new QRadioButton("PROGRESS",this);
    fini = new QRadioButton("FINISHED",this);

    switch(t->getStatus()) {
        case PENDING :
            pend->setChecked(true);
            break;
        case PROGRESS:
            prog->setChecked(true);
            break;
        case FINISHED:
            fini->setChecked(true);
            break;
    }

    QHBoxLayout *WidgetLayout = new QHBoxLayout();
    WidgetLayout->addWidget(pend);
    WidgetLayout->addWidget(prog);
    WidgetLayout->addWidget(fini);

    if(t->getStatus() == PENDING)
        pend->setChecked(true);
    else if(t->getStatus() == PROGRESS)
        prog->setChecked(true);
    else if(t->getStatus() == FINISHED)
        fini->setChecked(true);

    formWidgetLayout->addRow(tr("Status : "),WidgetLayout);

    this->getUi()->formWidget->setLayout(formWidgetLayout);
}

void V_CentralMultimedia::editMultimedia()
{
    if(desc->toPlainText().isEmpty() || this->getUi()->textTitle->text().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");
    else {
    Multimedia* editMultimedia = new Multimedia(
                this->getUi()->labelID->text(),
                this->getUi()->textTitle->text(),
                QDateTime::fromString(this->getUi()->labelCreatedOn->text()),
                QDateTime::currentDateTime(),
                desc->toPlainText(),
                pathToFile,
                type
                );

    this->getMainwindow()->getController()->editMultimedia(this->getUi()->labelID->text(),editMultimedia);
    }
}

void V_CentralTask::editTask()
{
    TaskStatus type;

    if(pend->isChecked())
        type = PENDING;
    else if(prog->isChecked())
        type = PROGRESS;
    else
        type = FINISHED;


    if( action->text().isEmpty() || this->getUi()->textTitle->text().isEmpty() ) {
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");
    }
    else {
        Task* editTask = new Task(
            this->getUi()->labelID->text(),
            this->getUi()->textTitle->text(),
            QDateTime::fromString(this->getUi()->labelCreatedOn->text()),
            QDateTime::currentDateTime(),
            action->text(),
            priority->value(),
            QDateTime::currentDateTime(),
            type
            );

        this->getMainwindow()->getController()->editTask(this->getUi()->labelID->text(),editTask);
    }
}

V_CentralArticle::~V_CentralArticle(){}
V_CentralMultimedia::~V_CentralMultimedia(){}
V_CentralTask::~V_CentralTask(){}
