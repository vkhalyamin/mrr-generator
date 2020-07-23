#ifndef UI_H_SENTRY
#define UI_H_SENTRY

#include <QWidget>
#include <QtWidgets>

#include "mrr.h"

class ui : public QWidget
{
    Q_OBJECT

public:
    ui();
    ~ui();

private slots:
    void generateMRR();
    void clearFields();

private:
    void createUI();

private:
    // Text labels
    QLabel surnameLabel;
    QLabel nameLabel;
    QLabel patronymicLabel;
    QLabel seriesLabel;
    QLabel numberLabel;
    QLabel dateOfBirthLabel;
    QLabel dateOfExtraditionLabel;
    QLabel departamentCodeLabel;
    QLabel sexLabel;
    QLabel MRRLabel;

private:
    // Edit fields
    QLineEdit surname;
    QLineEdit name;
    QLineEdit patronymic;
    QLineEdit series;
    QLineEdit number ;
    QDateEdit dateOfBirth;
    QDateEdit dateOfExtradition;
    QLineEdit departamentCode;
    QTextEdit MRR;

private:
    // Layouts
    QVBoxLayout mainVLayout;

    QHBoxLayout nameAndSurnameLayout;
    QHBoxLayout patronymicAndSexLayout;
    QHBoxLayout dateLayout;
    QHBoxLayout infoLayout;
    QHBoxLayout mainButtonsLayout;

    QVBoxLayout surnameLayout;
    QVBoxLayout nameLayout;
    QVBoxLayout patronymicLayout;
    QVBoxLayout sexLayout;
    QHBoxLayout sexButtonsLayout;
    QVBoxLayout dateOfBirthLayout;
    QVBoxLayout dateOfExtraditionLayout;
    QVBoxLayout seriesLayout;
    QVBoxLayout numberLayout;
    QVBoxLayout departamentCodeLayout;

private:
    // Buttons
    QRadioButton sexButtonM;
    QRadioButton sexButtonF;
    QPushButton generateMRRButton;
    QPushButton clearFieldsButton;

};

#endif // UI_H_SENTRY

