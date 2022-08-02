TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    map.h \
    mmap.h \
    ../_includes/BTree/btree.h \
    w_workreport.h \
    w_output.h \
    w_output_pages.h \
    w_output_report_off.h \
    ../_includes/new_vect/vector.h
