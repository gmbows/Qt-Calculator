#include "mainwindow.h"
#include "calculator.h"

#include <QApplication>
#include <QLocale>
#include <QPushButton>
#include <QLCDNumber>
#include <QTranslator>

#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    QApplication CalculatorApp(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Calculator_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            CalculatorApp.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    QIcon icon = QIcon(":/icons/calc.png");
    //w.setWindowIcon(icon);
    QLCDNumber* _display = w.findChild<QLCDNumber*>("nDisplay");
    if(!_display) {
        std::cout << "ERROR!" << std::endl;
    }

    std::vector<QPushButton*> keypad = {
        w.findChild<QPushButton*>("pushButton"),
        w.findChild<QPushButton*>("pushButton_2"),
        w.findChild<QPushButton*>("pushButton_3"),
        w.findChild<QPushButton*>("pushButton_4"),
        w.findChild<QPushButton*>("pushButton_5"),
        w.findChild<QPushButton*>("pushButton_6"),
        w.findChild<QPushButton*>("pushButton_7"),
        w.findChild<QPushButton*>("pushButton_8"),
        w.findChild<QPushButton*>("pushButton_9"),
        w.findChild<QPushButton*>("pushButton_10"),
    };

    Calculator c = Calculator();
    c.display = _display;

    w.calculator = c;

    w.show();
    return CalculatorApp.exec();
}
