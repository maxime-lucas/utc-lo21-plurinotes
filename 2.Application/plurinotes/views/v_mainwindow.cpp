#include "main.h"

#include <typeinfo>
#include <QSignalMapper>

#include "v_mainwindow.h"
#include "ui_v_mainwindow.h"
#include "ui_v_multiplenotes.h"
#include "ui_v_multiplerelation.h"

V_Mainwindow::V_Mainwindow(QWidget *parent, C_Mainwindow*c) :
    QMainWindow(parent),
    ui(new Ui::V_Mainwindow)
{
    ui->setupUi(this);
    controller = c;

    move(0,0);
    setStyleSheet("V_Mainwindow { background-color:#FFF;}");

    ui->actionArticle->setIcon(QIcon(QPixmap("../plurinotes/ressources/newArticle.png")));
    ui->actionMultimedia->setIcon(QIcon(QPixmap("../plurinotes/ressources/newMultimedia.png")));
    ui->actionTask->setIcon(QIcon(QPixmap("../plurinotes/ressources/newTask.png")));
    ui->actionShow_Asc_Desc_View->setIcon(QIcon(QPixmap("../plurinotes/ressources/asc_desc.png")));

    ui->actionShow_Asc_Desc_View->setChecked(true);
    init();
    this->connect(versions, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(restoreVersion(QListWidgetItem*)));
}

void V_Mainwindow::openNewArticle() {
    articleForm = new V_ArticleForm(0,this);
    articleForm->show();
}

void V_Mainwindow::openNewMultimedia(){
    multimediaForm = new V_MultimediaForm(0,this);
    multimediaForm->show();
}


void V_Mainwindow::openNewTask(){
    taskForm = new V_TaskForm(0,this);
    taskForm->show();
}

void V_Mainwindow::refreshCentralNote(QString id) {

    Note* note = controller->getApp()->getNoteByID(id);

    if(centralNote != 0) { delete centralNote; centralNote = 0; }

    if( typeid(*note) == typeid(Article) ) {
        Article* article = new Article(dynamic_cast<Article&>(*note));
        V_CentralArticle *v_centralArticle = new V_CentralArticle(article,this);
        centralNote = v_centralArticle;
    }

    if( typeid(*note) == typeid(Multimedia) ) {
        Multimedia* multimedia = new Multimedia(dynamic_cast<Multimedia&>(*note));
        V_CentralMultimedia *v_centralMultimedia = new V_CentralMultimedia(multimedia,this);
        centralNote = v_centralMultimedia;
    }

    if( typeid(*note) == typeid(Task) ) {
        Task* task = new Task(dynamic_cast<Task&>(*note));
        V_CentralTask *v_centralTask = new V_CentralTask(task,this);
        centralNote = v_centralTask;
    }

    centralNote->setFixedWidth(580);
    centralNote->setObjectName("centralNote");

    delete middleLayout;
    middleLayout = new QVBoxLayout;

    middleLayout->addWidget(centralNote);
    middleLayout->addWidget(bottomWidget);

    middleLayout->setMargin(0);
    middleLayout->setSpacing(0);

    middleWidget->setLayout(middleLayout);

    delete centralMainLayout;
    centralMainLayout = new QHBoxLayout;

    centralMainLayout->addWidget(leftWidget);
    centralMainLayout->addWidget(middleWidget);
    centralMainLayout->addWidget(rightWidget);

    refreshVersions(id);
}

void V_Mainwindow::refreshVersions(QString id) {

    Note* note = controller->getApp()->getNoteByID(id);

    std::vector<Version*>* noteVersions = note->getVersions();

    // CLEAR RELATIONS QLISTWIDGET
    while(versions->count()>0) versions->takeItem(0);

    for(unsigned int i = 0; i < noteVersions->size(); i++) {
        Version*v = noteVersions->at(i);
        Note*s = v->getState();

        // PREPARE THE DISPLAY OF A VERSION IN THE QLISTWIDGET
        QString f;
        f += "[v." + QString::number(v->getNumVersion()) + "] ";
        f += s->getTitle()+" - ";

        if( typeid(*s) == typeid(Article) ) {
            Article *a = new Article(dynamic_cast<Article&>(*s));
            f += a->getText();

        } else if( typeid(*s) == typeid(Multimedia) ) {
            Multimedia *m = new Multimedia(dynamic_cast<Multimedia&>(*s));
            f += m->getDescription();
        }

        QListWidgetItem *item = new QListWidgetItem;
        item->setData(Qt::UserRole,note->getId()+":"+QString::number(v->getNumVersion()));
        item->setText(f);

        versions->addItem(item);
    }
}

void V_Mainwindow::setEmptyCentralNote() {

    if(centralNote != NULL && ( typeid(*centralNote) == typeid(V_CentralArticle))) {
        delete &(dynamic_cast<V_CentralArticle&>(*centralNote));
    } else if(centralNote != NULL && ( typeid(*centralNote) == typeid(V_CentralMultimedia))) {
        delete &(dynamic_cast<V_CentralMultimedia&>(*centralNote));
    } else if(centralNote != NULL && ( typeid(*centralNote) == typeid(V_CentralTask))){
        delete &(dynamic_cast<V_CentralTask&>(*centralNote));
    }

    centralNote = new QWidget();
    QVBoxLayout *centralNoteLayout = new QVBoxLayout;
    QLabel *beginningTitle = new QLabel("Select a note in the left tab");
    beginningTitle->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    centralNoteLayout->addWidget(beginningTitle);
    centralNote->setFixedWidth(580);
    centralNote->setLayout(centralNoteLayout);

    delete middleLayout;
    middleLayout = new QVBoxLayout;

    middleLayout->addWidget(centralNote);
    middleLayout->addWidget(bottomWidget);

    middleLayout->setMargin(0);
    middleLayout->setSpacing(0);

    middleWidget->setLayout(middleLayout);

    delete centralMainLayout;
    centralMainLayout = new QHBoxLayout;

    centralMainLayout->addWidget(leftWidget);
    centralMainLayout->addWidget(middleWidget);
    centralMainLayout->addWidget(rightWidget);

}

void V_Mainwindow::restoreVersion(QListWidgetItem* i) {
    QString str = i->data(Qt::UserRole).toString();

    QStringList strList = str.split(":");
    QString id = strList.at(0);
    QString numVersion = strList.at(1);

    Version* v = controller->getApp()->getNoteVersionByID(id,numVersion);

    QString mbText = "State of this version : \n\n"+v->toString()+"\n\n What would you like to do ?";

    QMessageBox mb(this);
    mb.setWindowTitle("What would you like to do ?");
    mb.setText(mbText);
    mb.addButton(tr("Delete"),QMessageBox::YesRole);
    mb.addButton(tr("Restore"),QMessageBox::YesRole);
    mb.addButton("Cancel", QMessageBox::NoRole);
    mb.exec();

    if(mb.clickedButton()->text() == "Delete") {
        if(QMessageBox::question(this,"Delete versions","This operation will delete all anterior versions. \n Are you sure you want to continue ?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
            controller->deleteNoteVersion(id,numVersion);
     } else if(mb.clickedButton()->text() == "Restore") {
        controller->restoreNoteVersion(id,numVersion);
     }
}

void V_Mainwindow::toggleAscDescView() {

    if( this->getUi()->actionShow_Asc_Desc_View->isChecked() && !this->getUi()->actionShow_Relations_View->isChecked()) {
        rightWidget->setVisible(true);
    }
    else {
        if(!this->getUi()->actionShow_Relations_View->isChecked())
            rightWidget->setVisible(false);
    }
}

void V_Mainwindow::toggleRelationsView() {

    if( this->getUi()->actionShow_Relations_View->isChecked() ) {
        // Remise à 0 du GridLayout
        QLayoutItem* item;
        while ( ( item = centralMainLayout->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete centralMainLayout;

        centralSecondLayout = new QVBoxLayout;
        relationView = new V_MainRelation;
        centralSecondLayout->addWidget(relationView);
        centralWidget()->setLayout(centralSecondLayout);


    } else {
        // Remise à 0 du GridLayout
        QLayoutItem* item;
        while ( ( item = centralSecondLayout->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete centralSecondLayout;

        init();

        controller->refreshActiveNotes();
        controller->refreshTask();
    }

}

void V_Mainwindow::init() {

    // LEFT WIDGET INIT

    labelActiveNotes = new QLabel("Active Notes");
    labelArchivedNotes = new QLabel("Archived Notes");
    labelTasks = new QLabel("Tasks");
    activeNotes = new V_Multiplenotes;
    tasks = new V_Multiplenotes;
    archivedNotes = new V_Multiplenotes;
    leftWidget = new QWidget;
    leftLayout = new QVBoxLayout;

    labelActiveNotes->setFixedSize(200,20);
    labelActiveNotes->setAlignment(Qt::AlignCenter);
    labelArchivedNotes->setFixedSize(200,20);
    labelArchivedNotes->setAlignment(Qt::AlignCenter);
    labelTasks->setFixedSize(200,20);
    labelTasks->setAlignment(Qt::AlignCenter);

    leftLayout->addWidget(labelActiveNotes);
    leftLayout->addWidget(activeNotes);
    leftLayout->addWidget(labelTasks);
    leftLayout->addWidget(tasks);
    leftLayout->addWidget(labelArchivedNotes);
    leftLayout->addWidget(archivedNotes);
    leftLayout->setMargin(5);

    leftWidget->setLayout(leftLayout);
    leftWidget->setFixedWidth(210);
    leftWidget->setObjectName("leftWidget");

    // RIGHT WIDGET INIT

    relation = new V_Multiplerelation;
    rightWidget = new QWidget;
    rightLayout = new QVBoxLayout;

    rightLayout->addWidget(relation);
    rightLayout->setSpacing(0);
    rightLayout->setMargin(5);

    rightWidget->setLayout(rightLayout);
    rightWidget->setFixedWidth(210);
    rightWidget->setObjectName("rightWidget");

    // CENTRAL NOTE INIT

    centralNote = new QWidget;
    centralNoteLayout = new QVBoxLayout;

    QLabel *beginningTitle = new QLabel("Select a note in the left tab");
    beginningTitle->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    centralNoteLayout->addWidget(beginningTitle);

    centralNote->setLayout(centralNoteLayout);
    centralNote->setFixedWidth(580);

    // BOTTOM WIDGET INIT

    bottomWidget = new QWidget;
    bottomLayout = new QVBoxLayout;
    labelVersions = new QLabel("Versions");
    versions = new QListWidget;


    labelVersions->setAlignment(Qt::AlignCenter);
    labelVersions->setFixedHeight(20);

    bottomLayout->addWidget(labelVersions);
    bottomLayout->addWidget(versions);

    bottomWidget->setLayout(bottomLayout);
    bottomWidget->setFixedHeight(100);
    bottomWidget->setObjectName("bottomWidget");

    // MIDDLE WIDGET INIT

    middleWidget = new QWidget;
    middleLayout = new QVBoxLayout;

    middleLayout->addWidget(centralNote);
    middleLayout->addWidget(bottomWidget);

    middleLayout->setMargin(0);
    middleLayout->setSpacing(0);

    middleWidget->setLayout(middleLayout);
    middleWidget->setObjectName("middleWidget");

    // ADD ALL WIDGETS TO CENTRAL WIDGET

    centralMainLayout = new QHBoxLayout;

    centralMainLayout->addWidget(leftWidget);
    centralMainLayout->addWidget(middleWidget);
    centralMainLayout->addWidget(rightWidget);

    centralMainLayout->setMargin(0);
    centralMainLayout->setSpacing(0);

    centralWidget()->setLayout(centralMainLayout);

    // MISC

    setStyleSheet("#rightWidget,#middleWidget,#leftWidget,#bottomWidget,#centralNote { border: 3px solid #DDD; }");

    if( this->getUi()->actionShow_Asc_Desc_View->isChecked() ) rightWidget->setVisible(true);
    else {
        rightWidget->setVisible(false);
    }
}

V_Mainwindow::~V_Mainwindow()
{
    delete ui;
}
