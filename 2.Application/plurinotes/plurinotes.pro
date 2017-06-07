QT += widgets

HEADERS += \
    models/datetime.h \
    models/p_notes.h \
    models/p_versions.h \
    models/p_relations.h \
    models/notesexception.h \
    main.h \
    models/p_core.h \
    models/operatorsoverloading.h \
    views/v_mainwindow.h \
    controllers/c_mainwindow.h

SOURCES += \
    models/p_notes.cpp \
    models/p_versions.cpp \
    models/p_relations.cpp \
    main.cpp \
    models/p_core.cpp \
    models/operatorsoverloading.cpp \
    views/v_mainwindow.cpp \
    controllers/c_mainwindow.cpp
