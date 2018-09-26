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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionZero;
    QAction *actionAbsolute_move;
    QAction *actionPickup_move;
    QAction *actionDispense_move;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_address;
    QPushButton *initbutton;
    QRadioButton *radioButton_pickup;
    QSlider *poslider;
    QPushButton *pushButton_connect;
    QPushButton *plungermovebutton;
    QLCDNumber *lcdNumber;
    QRadioButton *radioButton_absolute;
    QRadioButton *radioButton_dispense;
    QSpacerItem *verticalSpacer;
    QComboBox *comboBox_valve;
    QPushButton *pushButton_cycle;
    QLabel *label_status;
    QPushButton *pushButton_zeroall;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(393, 359);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionZero = new QAction(MainWindow);
        actionZero->setObjectName(QStringLiteral("actionZero"));
        actionZero->setCheckable(false);
        actionAbsolute_move = new QAction(MainWindow);
        actionAbsolute_move->setObjectName(QStringLiteral("actionAbsolute_move"));
        actionAbsolute_move->setCheckable(true);
        actionAbsolute_move->setChecked(true);
        actionPickup_move = new QAction(MainWindow);
        actionPickup_move->setObjectName(QStringLiteral("actionPickup_move"));
        actionPickup_move->setCheckable(true);
        actionDispense_move = new QAction(MainWindow);
        actionDispense_move->setObjectName(QStringLiteral("actionDispense_move"));
        actionDispense_move->setCheckable(true);
        actionDispense_move->setChecked(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spinBox_address = new QSpinBox(centralWidget);
        spinBox_address->setObjectName(QStringLiteral("spinBox_address"));
        spinBox_address->setMinimum(1);
        spinBox_address->setMaximum(14);
        spinBox_address->setDisplayIntegerBase(16);

        gridLayout->addWidget(spinBox_address, 0, 2, 1, 1);

        initbutton = new QPushButton(centralWidget);
        initbutton->setObjectName(QStringLiteral("initbutton"));
        initbutton->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(initbutton->sizePolicy().hasHeightForWidth());
        initbutton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(initbutton, 0, 3, 1, 1);

        radioButton_pickup = new QRadioButton(centralWidget);
        radioButton_pickup->setObjectName(QStringLiteral("radioButton_pickup"));
        radioButton_pickup->setEnabled(false);

        gridLayout->addWidget(radioButton_pickup, 3, 3, 1, 1);

        poslider = new QSlider(centralWidget);
        poslider->setObjectName(QStringLiteral("poslider"));
        poslider->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(poslider->sizePolicy().hasHeightForWidth());
        poslider->setSizePolicy(sizePolicy1);
        poslider->setMinimumSize(QSize(0, 75));
        poslider->setContextMenuPolicy(Qt::DefaultContextMenu);
        poslider->setMaximum(3000);
        poslider->setSingleStep(1);
        poslider->setValue(0);
        poslider->setTracking(true);
        poslider->setOrientation(Qt::Vertical);
        poslider->setInvertedAppearance(false);
        poslider->setInvertedControls(false);

        gridLayout->addWidget(poslider, 2, 4, 3, 1);

        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        gridLayout->addWidget(pushButton_connect, 0, 1, 1, 1);

        plungermovebutton = new QPushButton(centralWidget);
        plungermovebutton->setObjectName(QStringLiteral("plungermovebutton"));
        plungermovebutton->setEnabled(false);
        sizePolicy.setHeightForWidth(plungermovebutton->sizePolicy().hasHeightForWidth());
        plungermovebutton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(plungermovebutton, 0, 4, 1, 1);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setEnabled(false);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setLineWidth(1);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(4);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdNumber, 5, 4, 1, 1);

        radioButton_absolute = new QRadioButton(centralWidget);
        radioButton_absolute->setObjectName(QStringLiteral("radioButton_absolute"));
        radioButton_absolute->setEnabled(false);
        radioButton_absolute->setChecked(true);

        gridLayout->addWidget(radioButton_absolute, 2, 3, 1, 1);

        radioButton_dispense = new QRadioButton(centralWidget);
        radioButton_dispense->setObjectName(QStringLiteral("radioButton_dispense"));
        radioButton_dispense->setEnabled(false);

        gridLayout->addWidget(radioButton_dispense, 4, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 4, 1, 1);

        comboBox_valve = new QComboBox(centralWidget);
        comboBox_valve->addItem(QString());
        comboBox_valve->addItem(QString());
        comboBox_valve->addItem(QString());
        comboBox_valve->addItem(QString());
        comboBox_valve->setObjectName(QStringLiteral("comboBox_valve"));
        comboBox_valve->setEnabled(false);

        gridLayout->addWidget(comboBox_valve, 5, 3, 1, 1);

        pushButton_cycle = new QPushButton(centralWidget);
        pushButton_cycle->setObjectName(QStringLiteral("pushButton_cycle"));
        pushButton_cycle->setEnabled(false);

        gridLayout->addWidget(pushButton_cycle, 5, 2, 1, 1);

        label_status = new QLabel(centralWidget);
        label_status->setObjectName(QStringLiteral("label_status"));

        gridLayout->addWidget(label_status, 2, 1, 1, 1);

        pushButton_zeroall = new QPushButton(centralWidget);
        pushButton_zeroall->setObjectName(QStringLiteral("pushButton_zeroall"));

        gridLayout->addWidget(pushButton_zeroall, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(poslider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        actionZero->setText(QApplication::translate("MainWindow", "Zero", nullptr));
        actionAbsolute_move->setText(QApplication::translate("MainWindow", "Absolute move", nullptr));
        actionPickup_move->setText(QApplication::translate("MainWindow", "Pickup move", nullptr));
        actionDispense_move->setText(QApplication::translate("MainWindow", "Dispense move", nullptr));
#ifndef QT_NO_TOOLTIP
        initbutton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Initialize the pump and valve</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        initbutton->setText(QApplication::translate("MainWindow", "Zero", nullptr));
        radioButton_pickup->setText(QApplication::translate("MainWindow", "Pickup", nullptr));
        pushButton_connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        plungermovebutton->setText(QApplication::translate("MainWindow", "Move Plunger", nullptr));
        radioButton_absolute->setText(QApplication::translate("MainWindow", "Absolute", nullptr));
        radioButton_dispense->setText(QApplication::translate("MainWindow", "Dispense", nullptr));
        comboBox_valve->setItemText(0, QApplication::translate("MainWindow", "Input", nullptr));
        comboBox_valve->setItemText(1, QApplication::translate("MainWindow", "Output", nullptr));
        comboBox_valve->setItemText(2, QApplication::translate("MainWindow", "Bypass", nullptr));
        comboBox_valve->setItemText(3, QApplication::translate("MainWindow", "Extra", nullptr));

        pushButton_cycle->setText(QApplication::translate("MainWindow", "Cycle", nullptr));
        label_status->setText(QApplication::translate("MainWindow", "label_status", nullptr));
        pushButton_zeroall->setText(QApplication::translate("MainWindow", "Zero All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
