#ifndef MRR_H_SENTRY
#define MRR_H_SENTRY

#include <QtCore>

const QString ru = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
const QString RU = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
const QString EN = "ABVGDE2JZIQKLMNOPRSTUFHC34WXY9678";

struct passData {
    QString surname;
    QString name;
    QString patronymic;
    QString seriesAndNumber;
    QDate dateOfBirth;
    QDate dateOfExtradition;
    QString departamentCode;
    QString sex;
};

class mrr {

public:
    mrr(passData &pata);
    QString getFirstLine(){ return firstLine; }
    QString getSecondLine() { return secondLine; }
    void makeMRR();

private:
    void translateString(QString& str);
    void addControlDigit(QString& str);
    void makeFirstLine();
    void makeSecondLine();

private:
    passData data;

private:
    QString firstLine;
    QString secondLine;
};

#endif // MRR_H_SENTRY
