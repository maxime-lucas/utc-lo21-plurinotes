#include "v_centralnote.h"
#include "ui_v_centralnote.h"
#include <QFileDialog>

V_CentralNote::V_CentralNote(QWidget *parent,V_Mainwindow* m) :
    QWidget(parent),
    ui(new Ui::V_CentralNote)
{
    parentView = m;
    ui->setupUi(this);

    parentView->connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(deleteNote()));
    parentView->connect(ui->btnEdit, SIGNAL(clicked()), this, SLOT(editNote()));


}

void V_CentralNote::deleteNote() {
    parentView->getController()->deleteByID(this->ui->labelID->text());
}

void V_CentralNote::editNote()
{
    Note* n = parentView->getController()->getApp()->getNoteByID(this->getUi()->labelID->text());

    if(typeid(*n) == typeid(Article))
    {
        Article* article = new Article(dynamic_cast<Article&>(*n));
        V_CentralArticle* Aview = new V_CentralArticle(article,getMainwindow());
        Aview->editArticle();
    }
    else if(typeid(*n) == typeid(Multimedia))
    {
        Multimedia* multimedia = new Multimedia(dynamic_cast<Multimedia&>(*n));
        V_CentralMultimedia* Mview = new V_CentralMultimedia(multimedia,getMainwindow());
        Mview->editMultimedia();
    }
    else if(typeid(*n) == typeid(Task))
    {
        Task* task = new Task(dynamic_cast<Task&>(*n));
        V_CentralTask* Tview = new V_CentralTask(task,getMainwindow());
        Tview->editTask();
    }

}

V_CentralNote::~V_CentralNote()
{
    delete ui;
}

V_CentralArticle::V_CentralArticle(Article *a,V_Mainwindow* m) : V_CentralNote(0,m) {
    this->getUi()->labelType->setText("Type : Article");
    this->getUi()->labelID->setText(a->getId());
    this->getUi()->textTitle->setText(a->getTitle());
    this->getUi()->labelCreatedOn->setText(a->getCreatedOn().toString());
    this->getUi()->labelLastModifOn->setText(a->getLastModifOn().toString());

    text = new QPlainTextEdit(a->getText());
    QVBoxLayout *formWidgetLayout = new QVBoxLayout();
    formWidgetLayout->addWidget(text);
    this->getUi()->formWidget->setLayout(formWidgetLayout);


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


V_CentralMultimedia::V_CentralMultimedia(Multimedia *m, V_Mainwindow*mw) : V_CentralNote(0,mw){
    this->getUi()->labelType->setText("Type : Multimedia/"+m->getTypeToQString());
    this->getUi()->labelID->setText(m->getId());
    this->getUi()->textTitle->setText(m->getTitle());
    this->getUi()->labelCreatedOn->setText(m->getCreatedOn().toString());
    this->getUi()->labelLastModifOn->setText(m->getLastModifOn().toString());

    desc = new QPlainTextEdit(m->getDescription());
    desc->setFixedHeight(100);
    QVBoxLayout *formWidgetLayout = new QVBoxLayout();
    formWidgetLayout->addWidget(desc);

    if( m->getType() == PICTURE ) {
        QFile *file = new QFile(m->getFileName());
        QFileInfo fileInfo(file->fileName());
        QDir dirToRessources(QDir::currentPath());
        dirToRessources.cd("../plurinotes/ressources/");
        QString path(dirToRessources.absolutePath()+ QDir::separator() + m->getId() + "." + fileInfo.completeSuffix());
        QLabel *img = new QLabel(this);
        img->setPixmap(QPixmap(path));
        img->setAlignment(Qt::AlignCenter);
        formWidgetLayout->addWidget(img);
    }

    pathToFile = m->getFileName();
    type = m->getType();

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

    QHBoxLayout *WidgetLayout = new QHBoxLayout();
    WidgetLayout->addWidget(pend);
    WidgetLayout->addWidget(prog);
    WidgetLayout->addWidget(fini);


    formWidgetLayout->addRow(tr("Status : "),WidgetLayout);

    this->getUi()->formWidget->setLayout(formWidgetLayout);

}

void V_CentralTask::editTask()
{
    if(action->text().isEmpty() || this->getUi()->textTitle->text().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");

    TaskStatus type;

    if(pend->isChecked())
        type = PENDING;
    else if(prog->isChecked())
        type = PROGRESS;
    else if(fini->isChecked())
        type = FINISHED;



    else {
    Task* editTask = new Task(
                this->getUi()->labelID->text(),
                this->getUi()->textTitle->text(),
                QDateTime::fromString(this->getUi()->labelCreatedOn->text()),
                QDateTime::currentDateTime(),
                action->text(),
                priority->value(),
                deadline->dateTime(),
                type
                );

    this->getMainwindow()->getController()->editTask(this->getUi()->labelID->text(),editTask);
    }
}

V_CentralArticle::~V_CentralArticle(){}
V_CentralMultimedia::~V_CentralMultimedia(){}
V_CentralTask::~V_CentralTask(){}
