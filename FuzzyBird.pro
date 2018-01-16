#-------------------------------------------------
#
# Project created by QtCreator 2017-11-19T00:14:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FuzzyBird
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH = include fuzlog/include

SOURCES += \
		src/main.cpp \
		src/MainWindow.cpp \
	src/MenuWidget.cpp \
	src/GameWidget.cpp \
	src/KeyboardController.cpp \
	src/Receiver.cpp \
	src/Game.cpp \
	src/GameOverWidget.cpp \
	src/AIController.cpp \
    fuzlog/src/parser/Parser.cpp \
    fuzlog/src/parser/Tokenizer.cpp \
    fuzlog/src/parser/ParserStates.cpp \
	fuzlog/src/engine/EngineFactory.cpp \
	fuzlog/src/engine/Engine.cpp \
	fuzlog/src/engine/EngineProperties.cpp \
    fuzlog/src/engine/InputVar.cpp \
	fuzlog/src/engine/OutputVar.cpp \
    fuzlog/src/engine/Triangle.cpp \
    fuzlog/src/engine/Rectangle.cpp \
    fuzlog/src/engine/Trapezoid.cpp \
    fuzlog/src/engine/Binary.cpp \
    fuzlog/src/engine/Ramp.cpp \
    fuzlog/src/engine/RuleBlock.cpp \
    fuzlog/src/engine/AndExpr.cpp \
    fuzlog/src/engine/Minimum.cpp \
    fuzlog/src/engine/Aggregator.cpp \
    fuzlog/src/engine/Bisector.cpp \
    fuzlog/src/engine/Centroid.cpp \
    fuzlog/src/engine/Maximum.cpp \
    fuzlog/src/engine/AlgebraicProduct.cpp \
    fuzlog/src/engine/BoundedSum.cpp \
    fuzlog/src/engine/Implicator.cpp

HEADERS += \
		include/MainWindow.hpp \
	include/MenuWidget.hpp \
	include/GameWidget.hpp \
	include/Controller.hpp \
	include/KeyboardController.hpp \
	include/Receiver.hpp \
	include/Game.hpp \
	include/Constants.hpp \
	include/GameOverWidget.hpp \
	include/AIController.hpp \
    fuzlog/include/Parser.hpp \
    fuzlog/include/Tokenizer.hpp \
    fuzlog/include/ParserStates.hpp \
	fuzlog/include/EngineFactory.hpp \
	fuzlog/include/Engine.hpp \
	fuzlog/include/EngineProperties.hpp \
    fuzlog/include/Defuzzifier.hpp \
    fuzlog/include/InputVar.hpp \
    fuzlog/include/OutputVar.hpp \
	fuzlog/include/Norm.hpp \
    fuzlog/include/Term.hpp \
    fuzlog/include/Triangle.hpp \
    fuzlog/include/Rectangle.hpp \
    fuzlog/include/Trapezoid.hpp \
    fuzlog/include/Binary.hpp \
    fuzlog/include/fuzlog.h \
    fuzlog/include/Ramp.hpp \
    fuzlog/include/RuleBlock.hpp \
    fuzlog/include/AndExpr.hpp \
    fuzlog/include/Expression.hpp \
    fuzlog/include/Minimum.hpp \
    fuzlog/include/utility.h \
    fuzlog/include/Aggregator.hpp \
    fuzlog/include/Bisector.hpp \
    fuzlog/include/Centroid.hpp \
    fuzlog/include/Maximum.hpp \
    fuzlog/include/AlgebraicProduct.hpp \
    fuzlog/include/BoundedSum.hpp \
    fuzlog/include/Implicator.hpp
