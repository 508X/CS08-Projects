TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    averager.cpp

HEADERS += \
    timer.h \
    sorts.h \
    ../../Heap/heap_re.h \
    ../../Heap/cmp.h \
    averager.h \
    w_output.h \
    w_workreport.h
