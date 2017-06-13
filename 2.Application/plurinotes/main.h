#ifndef MAIN
#define MAIN

typedef enum TaskStatus { PENDING, PROGRESS, FINISHED } TaskStatus;
typedef enum TypeMultimedia { PICTURE, AUDIO, VIDEO } TypeMultimedia;
typedef enum eTypeNote { article, multimedia, task } TypeNote;

#define NBMAX 100


#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <typeinfo>

#include <QApplication>
#include <QString>
#include <QLayout>
#include <QAction>
#include <QMenuBar>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QtXml>
#include <QMessageBox>
#include <QFile>
#include <QObject>
#include <QDomDocument>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDateTime>
#include <QTabWidget>

#include "models/operatorsoverloading.h"

#endif // MAIN

