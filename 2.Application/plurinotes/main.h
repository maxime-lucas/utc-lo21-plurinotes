#ifndef MAIN
#define MAIN

typedef enum TaskStatus { PENDING, PROGRESS, FINISHED } TaskStatus;
typedef enum TypeMultimedia { PICTURE, AUDIO, VIDEO } TypeMultimedia;

#define NBMAX 100

#include <ctime>
#include <string>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QAction>
#include <QMenuBar>
#include "models/datetime.h"
#include "models/operatorsoverloading.h"

#endif // MAIN

