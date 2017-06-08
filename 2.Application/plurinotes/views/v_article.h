#ifndef V_ARTICLE_H
#define V_ARTICLE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLayout>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QFormLayout>

#include "models/p_notes.h"

class v_article : public QWidget {
    Q_OBJECT
private:
    QLabel *id1, *titre1, *text1;
    QLineEdit *id, *titre;
    QTextEdit *text;
    QPushButton *save;
    QFormLayout *layout;
    QVBoxLayout *Vlayout;
    Article *article;
public:
    v_article();
    //explicit v_article(Article &article, QWidget *parent = 0);
public slots:
    void saveArticle();
private slots:
    void enabledSave();
};

#endif // V_ARTICLE_H
