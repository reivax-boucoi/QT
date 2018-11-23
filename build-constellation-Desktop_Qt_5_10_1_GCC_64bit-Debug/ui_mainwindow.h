/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSlider *redSlider;
    QPushButton *redButtoon;
    QPushButton *greenButtoon;
    QPushButton *blueButtoon;
    QSlider *greenSlider;
    QSlider *blueSlider;
    QWidget *graphWidget;
    QFrame *line;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(672, 553);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        redSlider = new QSlider(centralWidget);
        redSlider->setObjectName(QStringLiteral("redSlider"));
        redSlider->setMaximum(255);
        redSlider->setSingleStep(128);
        redSlider->setPageStep(128);
        redSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(redSlider, 0, 1, 1, 1);

        redButtoon = new QPushButton(centralWidget);
        redButtoon->setObjectName(QStringLiteral("redButtoon"));

        gridLayout->addWidget(redButtoon, 1, 1, 1, 1);

        greenButtoon = new QPushButton(centralWidget);
        greenButtoon->setObjectName(QStringLiteral("greenButtoon"));

        gridLayout->addWidget(greenButtoon, 1, 2, 1, 1);

        blueButtoon = new QPushButton(centralWidget);
        blueButtoon->setObjectName(QStringLiteral("blueButtoon"));

        gridLayout->addWidget(blueButtoon, 1, 3, 1, 1);

        greenSlider = new QSlider(centralWidget);
        greenSlider->setObjectName(QStringLiteral("greenSlider"));
        greenSlider->setMaximum(255);
        greenSlider->setSingleStep(128);
        greenSlider->setPageStep(128);
        greenSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(greenSlider, 0, 2, 1, 1);

        blueSlider = new QSlider(centralWidget);
        blueSlider->setObjectName(QStringLiteral("blueSlider"));
        blueSlider->setMaximum(255);
        blueSlider->setSingleStep(128);
        blueSlider->setPageStep(128);
        blueSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(blueSlider, 0, 3, 1, 1);

        graphWidget = new QWidget(centralWidget);
        graphWidget->setObjectName(QStringLiteral("graphWidget"));

        gridLayout->addWidget(graphWidget, 5, 0, 1, 4);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 4);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        redButtoon->setText(QApplication::translate("MainWindow", "Red", nullptr));
        greenButtoon->setText(QApplication::translate("MainWindow", "Green", nullptr));
        blueButtoon->setText(QApplication::translate("MainWindow", "Blue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
