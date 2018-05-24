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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonX;
    QPushButton *pushButtonY;
    QLCDNumber *lcdNumberZ;
    QLineEdit *lineEditX;
    QLabel *labelZ;
    QPushButton *pushButtonZ;
    QLineEdit *lineEditZ;
    QLCDNumber *lcdNumberY;
    QLabel *labelY;
    QLCDNumber *lcdNumberX;
    QLabel *labelX;
    QLineEdit *lineEditY;
    QGraphicsView *graphicsViewCam;
    QPushButton *pushButtonCam;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonX = new QPushButton(gridLayoutWidget);
        pushButtonX->setObjectName(QStringLiteral("pushButtonX"));

        gridLayout->addWidget(pushButtonX, 0, 2, 1, 1);

        pushButtonY = new QPushButton(gridLayoutWidget);
        pushButtonY->setObjectName(QStringLiteral("pushButtonY"));

        gridLayout->addWidget(pushButtonY, 1, 2, 1, 1);

        lcdNumberZ = new QLCDNumber(gridLayoutWidget);
        lcdNumberZ->setObjectName(QStringLiteral("lcdNumberZ"));
        lcdNumberZ->setSmallDecimalPoint(false);

        gridLayout->addWidget(lcdNumberZ, 2, 1, 1, 1);

        lineEditX = new QLineEdit(gridLayoutWidget);
        lineEditX->setObjectName(QStringLiteral("lineEditX"));

        gridLayout->addWidget(lineEditX, 0, 3, 1, 1);

        labelZ = new QLabel(gridLayoutWidget);
        labelZ->setObjectName(QStringLiteral("labelZ"));

        gridLayout->addWidget(labelZ, 2, 0, 1, 1);

        pushButtonZ = new QPushButton(gridLayoutWidget);
        pushButtonZ->setObjectName(QStringLiteral("pushButtonZ"));

        gridLayout->addWidget(pushButtonZ, 2, 2, 1, 1);

        lineEditZ = new QLineEdit(gridLayoutWidget);
        lineEditZ->setObjectName(QStringLiteral("lineEditZ"));

        gridLayout->addWidget(lineEditZ, 2, 3, 1, 1);

        lcdNumberY = new QLCDNumber(gridLayoutWidget);
        lcdNumberY->setObjectName(QStringLiteral("lcdNumberY"));

        gridLayout->addWidget(lcdNumberY, 1, 1, 1, 1);

        labelY = new QLabel(gridLayoutWidget);
        labelY->setObjectName(QStringLiteral("labelY"));

        gridLayout->addWidget(labelY, 1, 0, 1, 1);

        lcdNumberX = new QLCDNumber(gridLayoutWidget);
        lcdNumberX->setObjectName(QStringLiteral("lcdNumberX"));

        gridLayout->addWidget(lcdNumberX, 0, 1, 1, 1);

        labelX = new QLabel(gridLayoutWidget);
        labelX->setObjectName(QStringLiteral("labelX"));

        gridLayout->addWidget(labelX, 0, 0, 1, 1);

        lineEditY = new QLineEdit(gridLayoutWidget);
        lineEditY->setObjectName(QStringLiteral("lineEditY"));

        gridLayout->addWidget(lineEditY, 1, 3, 1, 1);

        graphicsViewCam = new QGraphicsView(centralWidget);
        graphicsViewCam->setObjectName(QStringLiteral("graphicsViewCam"));
        graphicsViewCam->setGeometry(QRect(400, 50, 640, 480));
        pushButtonCam = new QPushButton(centralWidget);
        pushButtonCam->setObjectName(QStringLiteral("pushButtonCam"));
        pushButtonCam->setGeometry(QRect(440, 10, 80, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonX->setText(QApplication::translate("MainWindow", "Set", nullptr));
        pushButtonY->setText(QApplication::translate("MainWindow", "Set", nullptr));
        labelZ->setText(QApplication::translate("MainWindow", "Z", nullptr));
        pushButtonZ->setText(QApplication::translate("MainWindow", "Set", nullptr));
        labelY->setText(QApplication::translate("MainWindow", "Y", nullptr));
        labelX->setText(QApplication::translate("MainWindow", "X", nullptr));
        pushButtonCam->setText(QApplication::translate("MainWindow", "Webcam", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
