#include "mrr.h"

mrr::mrr(passData &passData) : data(passData) {}

void mrr::translateString(QString &str)
{
    for (int i = 0; i < str.size(); ++i) {
        for (int j = 0; j < RU.size(); ++j) {
            if (str[i] == RU[j] || str[i] == ru[j]) {
                str[i] = EN[j];
                break;
            }
        }
    }
}

void mrr::makeMRR()
{
    makeFirstLine();
    makeSecondLine();
}

void mrr::makeFirstLine()
{
    int S = data.surname.size();
    int SN = S + data.name.size();
    int SNP = SN + data.patronymic.size();

    translateString(data.surname);
    translateString(data.name);
    translateString(data.patronymic);

    if (SNP < 39) {
    } else if (SN < 38) {
        data.patronymic.truncate(36 - SN);
    } else if (SN >= 38 && S <= 34) {
        data.patronymic.truncate(1);
        data.name.truncate(35 - S);
    } else {
        data.surname.truncate(34);
        data.name.truncate(1);
        data.patronymic.truncate(1);
    }

    firstLine = "PNRUS" + data.surname + "<<" + data.name + "<" + data.patronymic;

    while (firstLine.size() < 44)
        firstLine.push_back("<");
}

void mrr::makeSecondLine()
{
    QString firstControlLine;
    QString secondControlLine;
    QString thirdControlLine;
    QString fourthControlLine;
    QString finalControlLine;

    for (int i = 0; i < data.seriesAndNumber.size(); ++i) {
        if (i != 3)
            firstControlLine.push_back(data.seriesAndNumber[i]);
    }

    secondControlLine = data.dateOfBirth.toString("yyMMdd");
    thirdControlLine = "000000";
    fourthControlLine.push_back(data.seriesAndNumber[3]);
    fourthControlLine += data.dateOfExtradition.toString("yyMMdd");
    fourthControlLine += data.departamentCode;

    addControlDigit(firstControlLine);
    addControlDigit(secondControlLine);
    addControlDigit(thirdControlLine);
    addControlDigit(fourthControlLine);

    fourthControlLine.insert(13, "0");

    finalControlLine = firstControlLine + secondControlLine + thirdControlLine + fourthControlLine;
    addControlDigit(finalControlLine);
    fourthControlLine.replace(13, 1, "<");
    secondLine = firstControlLine + "RUS" + secondControlLine + data.sex + "<<<<<<<" + fourthControlLine + finalControlLine[39];
}

void mrr::addControlDigit(QString &str)
{
    QString function = "731";
    int temp = 0;

    for (int i = 3; i < str.size(); ++i)
        function.push_back(function[i-3]);

    for (int i = 0; i < str.size(); ++i)
        temp += (function[i].digitValue() * str[i].digitValue());

    str.push_back(QString::number(temp %= 10));
}
