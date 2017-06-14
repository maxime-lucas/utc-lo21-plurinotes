QT += widgets
QT += xml
QT += core gui
QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    models/p_notes.h \
    models/p_versions.h \
    models/p_relations.h \
    models/notesexception.h \
    models/p_core.h \
    models/operatorsoverloading.h \
    models/p_xml.h \
    views/v_mainwindow.h \
    views/v_multiplenotes.h \
    views/v_littlenote.h\
    main.h \
    controllers/c_mainwindow.h \
    views/v_articleform.h \
    views/v_multimediaform.h \
    views/v_taskform.h \
    views/v_centralnote.h \
    views/v_multiplerelation.h \
    views/v_mainrelation.h \
    views/v_centralrelation.h \
    views/v_relationform.h \
    views/v_coupleform.h

SOURCES += \
    models/p_notes.cpp \
    models/p_versions.cpp \
    models/p_relations.cpp \
    main.cpp \
    models/p_core.cpp \
    models/operatorsoverloading.cpp \
    views/v_mainwindow.cpp \
    controllers/c_mainwindow.cpp \
    models/p_xml.cpp \
    views/v_multiplenotes.cpp \
    views/v_littlenote.cpp \
    views/v_articleform.cpp \
    views/v_multimediaform.cpp \
    views/v_taskform.cpp \
    views/v_centralnote.cpp \
    views/v_multiplerelation.cpp \
    views/v_mainrelation.cpp \
    views/v_centralrelation.cpp \
    views/v_relationform.cpp \
    views/v_coupleform.cpp


FORMS += \
    views/v_mainwindow.ui \
    views/v_multiplenotes.ui \
    views/v_articleform.ui \
    views/v_multimediaform.ui \
    views/v_taskform.ui \
    views/v_centralnote.ui \
    views/v_multiplerelation.ui \
    views/v_mainrelation.ui \
    views/v_centralrelation.ui \
    views/v_relationform.ui \
    views/v_coupleform.ui
