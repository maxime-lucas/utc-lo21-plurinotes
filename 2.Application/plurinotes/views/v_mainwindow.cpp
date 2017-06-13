#include "main.h"
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

    delete centralMainLayout;
    centralMainLayout = new QHBoxLayout;
    centralNote->setFixedWidth(580);
    centralMainLayout->addWidget(leftWidget);
    centralMainLayout->addWidget(centralNote);
    centralMainLayout->addWidget(rightWidget);
    centralWidget()->setLayout(centralMainLayout);
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
    centralNote->setFixedWidth(560);
    centralNote->setLayout(centralNoteLayout);

    delete centralMainLayout;
    centralMainLayout = new QHBoxLayout;
    centralMainLayout->addWidget(leftWidget);
    centralMainLayout->addWidget(centralNote);
    centralMainLayout->addWidget(rightWidget);
    centralWidget()->setLayout(centralMainLayout);

}

void V_Mainwindow::toggleAscDescView() {

    if( this->getUi()->actionShow_Asc_Desc_View->isChecked() ) {
        if(typeid(*(centralWidget()->layout())) == typeid(QHBoxLayout))
            rightWidget->setVisible(true);
    }
    else {
        if(typeid(*(centralWidget()->layout())) == typeid(QHBoxLayout))
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
            item = nullptr;
        }
        delete centralMainLayout;

        centralSecondLayout = new QVBoxLayout;
        centralSecondLayout->hasHeightForWidth();
        relationView = new V_MainView(0,getController());
        relationView->adjustSize();
        centralSecondLayout->addWidget(relationView);
        centralWidget()->setLayout(centralSecondLayout);


    } else {
        // Remise à 0 du GridLayout
        QLayoutItem* item;
        while ( ( item = centralSecondLayout->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
            item = nullptr;
        }
        delete centralSecondLayout;

        init();

        controller->refreshActiveNotes();
        controller->refreshTask();
    }

}

void V_Mainwindow::init() {
    labelActiveNotes = new QLabel("Active Notes");
    labelActiveNotes->setFixedSize(200,20);
    labelActiveNotes->setAlignment(Qt::AlignCenter);

    labelArchivedNotes = new QLabel("Archived Notes");
    labelArchivedNotes->setFixedSize(200,20);
    labelArchivedNotes->setAlignment(Qt::AlignCenter);

    labelTasks = new QLabel("Tasks");
    labelTasks->setFixedSize(200,20);
    labelTasks->setAlignment(Qt::AlignCenter);

    activeNotes = new V_Multiplenotes;
    tasks = new V_Multiplenotes;
    archivedNotes = new V_Multiplenotes;

    leftWidget = new QWidget;
    rightWidget = new QWidget;
    leftLayout = new QVBoxLayout;
    rightLayout = new QVBoxLayout;

    leftLayout->addWidget(labelActiveNotes);
    leftLayout->addWidget(activeNotes);
    leftLayout->addWidget(labelTasks);
    leftLayout->addWidget(tasks);
    leftLayout->addWidget(labelArchivedNotes);
    leftLayout->addWidget(archivedNotes);
    leftLayout->setMargin(5);

    relation = new V_Multiplerelation;

    rightLayout->addWidget(relation);
    rightLayout->setSpacing(0);
    rightLayout->setMargin(5);

    leftWidget->setLayout(leftLayout);
    leftWidget->setFixedWidth(210);

    rightWidget->setLayout(rightLayout);
    rightWidget->setFixedWidth(210);

    centralNote = new QWidget();
    QVBoxLayout *centralNoteLayout = new QVBoxLayout;
    QLabel *beginningTitle = new QLabel("Select a note in the left tab");
    beginningTitle->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    centralNoteLayout->addWidget(beginningTitle);
    centralNote->setFixedWidth(560);
    centralNote->setLayout(centralNoteLayout);

    centralMainLayout = new QHBoxLayout;
    centralNote->setFixedWidth(580);
    centralMainLayout->addWidget(leftWidget);
    centralMainLayout->addWidget(centralNote);
    centralMainLayout->addWidget(rightWidget);
    centralWidget()->setLayout(centralMainLayout);

    if( this->getUi()->actionShow_Asc_Desc_View->isChecked() ) rightWidget->setVisible(true);
    else {
        rightWidget->setVisible(false);
    }
}

V_Mainwindow::~V_Mainwindow()
{
    delete ui;
}
