TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += force_debug_info
CONFIG -= qt
linux-g++: LIBS += -pthread
SOURCES += cpu-test.cpp
