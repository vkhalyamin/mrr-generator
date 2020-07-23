#include "ui.h"

#include <QDebug>

ui::ui()
{
    createUI();
    QObject::connect(&clearFieldsButton, &QPushButton::clicked, this, &ui::clearFields);
    QObject::connect(&generateMRRButton, &QPushButton::clicked, this, &ui::generateMRR);
}

ui::~ui() {}

void ui::createUI()
{
    surnameLabel.setText("Фамилия");
    nameLabel.setText("Имя:");
    patronymicLabel.setText("Отчество:");
    seriesLabel.setText("Серия:");
    numberLabel.setText("Номер:");
    dateOfBirthLabel.setText("Дата рождения:");
    dateOfExtraditionLabel.setText("Дата выдачи:");
    departamentCodeLabel.setText("Код подразделения:");
    sexLabel.setText("Пол:");
    MRRLabel.setText("Машиночитаемая запись:");

    sexButtonM.setText("М");
    sexButtonF.setText("Ж");

    generateMRRButton.setText("Генерировать");
    clearFieldsButton.setText("Очистить");


    // LAYOUTS STRUCTURE

    // Main Layout
    mainVLayout.addLayout(&nameAndSurnameLayout);
    mainVLayout.addLayout(&patronymicAndSexLayout);
    mainVLayout.addLayout(&dateLayout);
    mainVLayout.addLayout(&infoLayout);
    mainVLayout.addWidget(&MRRLabel);
    mainVLayout.addWidget(&MRR);
    mainVLayout.addLayout(&mainButtonsLayout);

    // Second level layouts
    nameAndSurnameLayout.addLayout(&surnameLayout);
    nameAndSurnameLayout.addLayout(&nameLayout);

    patronymicAndSexLayout.addLayout(&patronymicLayout, 2);
    patronymicAndSexLayout.addLayout(&sexLayout, 1);
    patronymicAndSexLayout.addStretch(1);

    dateLayout.addLayout(&dateOfBirthLayout);
    dateLayout.addLayout(&dateOfExtraditionLayout);

    infoLayout.addLayout(&seriesLayout, 1);
    infoLayout.addLayout(&numberLayout, 1);
    infoLayout.addLayout(&departamentCodeLayout, 1);

    mainButtonsLayout.addStretch();
    mainButtonsLayout.addWidget(&generateMRRButton);
    mainButtonsLayout.addWidget(&clearFieldsButton);
    mainButtonsLayout.addStretch();

    // Third level layouts
    surnameLayout.addWidget(&surnameLabel);
    surnameLayout.addWidget(&surname);

    nameLayout.addWidget(&nameLabel);
    nameLayout.addWidget(&name);

    patronymicLayout.addWidget(&patronymicLabel);
    patronymicLayout.addWidget(&patronymic);

    sexLayout.addWidget(&sexLabel);
    sexLayout.addLayout(&sexButtonsLayout);

    dateOfBirthLayout.addWidget(&dateOfBirthLabel);
    dateOfBirthLayout.addWidget(&dateOfBirth);

    dateOfExtraditionLayout.addWidget(&dateOfExtraditionLabel);
    dateOfExtraditionLayout.addWidget(&dateOfExtradition);

    seriesLayout.addWidget(&seriesLabel);
    seriesLayout.addWidget(&series);

    numberLayout.addWidget(&numberLabel);
    numberLayout.addWidget(&number);

    departamentCodeLayout.addWidget(&departamentCodeLabel);
    departamentCodeLayout.addWidget(&departamentCode);

    // Fourth level layouts
    sexButtonsLayout.addWidget(&sexButtonM);
    sexButtonsLayout.addWidget(&sexButtonF);
    sexButtonsLayout.setAlignment(Qt::AlignVCenter);


    // SETUP

    // Layouts
    mainVLayout.setContentsMargins(10, 10, 10, 10);
    mainButtonsLayout.setContentsMargins(0, 5, 0, 0);

    // Buttons
    sexButtonM.setChecked(true);
    generateMRRButton.setMinimumWidth(80);
    clearFieldsButton.setMinimumWidth(80);

    // EditLines
    series.setMaxLength(4);
    series.setValidator(new QIntValidator(0, 9999, this));
    number.setMaxLength(6);
    departamentCode.setMaxLength(6);
    number.setValidator(new QIntValidator(0, 999999, this));
    departamentCode.setValidator(new QIntValidator(0, 999999, this));
    MRR.setReadOnly(true);
    MRR.setMaximumHeight(80);

    // Main Widget
    this->setFixedSize(350, 300);
    this->setLayout(&mainVLayout);
}

void ui::clearFields()
{
    surname.clear();
    name.clear();
    patronymic.clear();
    dateOfBirth.clear();
    dateOfExtradition.clear();
    series.clear();
    number.clear();
    departamentCode.clear();
    MRR.clear();
    sexButtonM.setChecked(true);
}

void ui::generateMRR()
{
    passData data;
    data.surname = surname.text();
    data.name = name.text();
    data.patronymic = patronymic.text();
    data.seriesAndNumber = series.text() + number.text();
    data.dateOfBirth = dateOfBirth.date();
    data.dateOfExtradition = dateOfExtradition.date();
    data.departamentCode = departamentCode.text();

    sexButtonM.isChecked() ? data.sex = "M" : data.sex = "F";

    // Check for empty input-fields
    if(data.surname == "" || data.name == "" || data.patronymic == "" ||
            data.seriesAndNumber == "" || data.departamentCode == "") {
        MRR.setText("Некорректные данные!\nПроверьте правильность заполнения всех полей.");
        return;
    }

    class mrr mrr(data);
    mrr.makeMRR();
    MRR.setText(mrr.getFirstLine() + "\n" + mrr.getSecondLine());
}
