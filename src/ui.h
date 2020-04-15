#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QtWidgets>

#include "mrr.h"

class ui : public QWidget
{
    Q_OBJECT

public:
    ui();

private slots:
    void generateMRR();
    void clearFields();

private:
    void createUI();

private:
    QLabel* surnameLabel;
    QLabel* nameLabel;
    QLabel* patronymicLabel;
    QLabel* seriesLabel;
    QLabel* numberLabel;
    QLabel* dateOfBirthLabel;
    QLabel* dateOfExtraditionLabel;
    QLabel* departamentCodeLabel;
    QLabel* sexLabel;
    QLabel* MRRLabel;

private:
    QLineEdit *surname;
    QLineEdit *name;
    QLineEdit *patronymic;
    QLineEdit *series;
    QLineEdit *number ;
    QDateEdit *dateOfBirth;
    QDateEdit *dateOfExtradition;
    QLineEdit *departamentCode;
    QTextEdit *MRR;

private:
    QVBoxLayout* mainVLayout;

    QHBoxLayout* nameAndSurnameLayout;
    QHBoxLayout* patronymicAndSexLayout;
    QHBoxLayout* dateLayout;
    QHBoxLayout* infoLayout;
    QHBoxLayout* mainButtonsLayout;

    QVBoxLayout* surnameLayout;
    QVBoxLayout* nameLayout;
    QVBoxLayout* patronymicLayout;
    QVBoxLayout* sexLayout;
    QHBoxLayout* sexButtonsLayout;
    QVBoxLayout* dateOfBirthLayout;
    QVBoxLayout* dateOfExtraditionLayout;
    QVBoxLayout* seriesLayout;
    QVBoxLayout* numberLayout;
    QVBoxLayout* departamentCodeLayout;

private:
    QRadioButton* sexButtonM;
    QRadioButton* sexButtonF;
    QPushButton* generateMRRButton;
    QPushButton* clearFieldsButton;

};

#endif // UI_H
