QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

include(../../testConfig.pri)

SOURCES +=  tst_testrecord.cpp
