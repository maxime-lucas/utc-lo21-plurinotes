#include "main.h"
#include "v_mainwindow.h"
#include "ui_v_mainwindow.h"
#include "ui_v_multiplenotes.h"

V_Mainwindow::V_Mainwindow(QWidget *parent, C_Mainwindow*c) :
    QMainWindow(parent),
    ui(new Ui::V_Mainwindow)
{
    ui->setupUi(this);
    controller = c;

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

    centralLayout = new QHBoxLayout;
    leftWidget = new QWidget;
    leftLayout = new QVBoxLayout;

    leftLayout->addWidget(labelActiveNotes);
    leftLayout->addWidget(activeNotes);
    leftLayout->addWidget(labelTasks);
    leftLayout->addWidget(tasks);
    leftLayout->addWidget(labelArchivedNotes);
    leftLayout->addWidget(archivedNotes);

    centralNote = new QWidget();
    QVBoxLayout *centralNoteLayout = new QVBoxLayout;
    QLabel *beginningTitle = new QLabel("Select a note in the left tab");
    beginningTitle->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    centralNoteLayout->addWidget(beginningTitle);
    centralNote->setFixedSize(560,560);
    centralNote->setLayout(centralNoteLayout);

    leftWidget->setLayout(leftLayout);
    leftWidget->setFixedWidth(210);

    centralLayout->addWidget(leftWidget);
    centralLayout->addWidget(centralNote);
    centralWidget()->setLayout(centralLayout);
}

void V_Mainwindow::openNewArticle() {
    articleForm = new V_ArticleForm(0,this);
    articleForm->show();
}

void V_Mainwindow::refreshCentralNote(QString id) {
    Note* note = controller->getApp()->getNoteByID(id);

    if(centralNote != 0) delete centralNote;

    if( typeid(*note) == typeid(Article) ) {
        Article* article = new Article(dynamic_cast<Article&>(*note));
        V_CentralArticle *v_centralArticle = new V_CentralArticle(article);
        centralNote = v_centralArticle;
        centralLayout->addWidget(centralNote);
    }

}

V_Mainwindow::~V_Mainwindow()
{
    delete ui;
}
