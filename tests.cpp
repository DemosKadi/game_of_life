#include "field.h"
#include "input_parser.h"

#include <QtTest/QtTest>
#include <QString>
#include <QVector>

class Tests: public QObject {
    Q_OBJECT
private slots:
    void parser_parse_line();
    void parser_fix_row_sizes();
    void row_at();
    void field_at_const();
    void field_at();
    void field_neighbours();
};

void Tests::parser_parse_line() {
    QString input1{""};
    QVector<bool> check1{};
    QString input2{"oooo"};
    QVector<bool> check2{false, false, false, false};
    QString input3{"xxxx"};
    QVector<bool> check3{true, true, true, true};
    QString input4{"oxoxo"};
    QVector<bool> check4{false, true, false, true, false};
    QString input5{"123x456"};
    QVector<bool> check5{false, false, false, true, false, false, false};

    QVERIFY(parse_line(input1) == check1);
    QVERIFY(parse_line(input2) == check2);
    QVERIFY(parse_line(input3) == check3);
    QVERIFY(parse_line(input4) == check4);
    QVERIFY(parse_line(input5) == check5);
}

void Tests::parser_fix_row_sizes() {
    Field field{
        {false},
        {false, false, false},
        {false, false}
    };

    QVERIFY(field[0].size() == 1);
    QVERIFY(field[1].size() == 3);
    QVERIFY(field[2].size() == 2);

    field = fix_row_sizes(field);

    QVERIFY(field[0].size() == 3);
    QVERIFY(field[1].size() == 3);
    QVERIFY(field[2].size() == 3);
}

void Tests::row_at() {
    const Row row{true, false, true};
    QVERIFY(row.at(-1) == false);
    QVERIFY(row.at(0) == true);
    QVERIFY(row.at(1) == false);
    QVERIFY(row.at(2) == true);
    QVERIFY(row.at(3) == false);
}

void Tests::field_at_const() {
    const Field field{{true, false}, {false, true}};

    QVERIFY(field.at(-1, -1) == false);
    QVERIFY(field.at(-1, 0) == false);
    QVERIFY(field.at(0, -1) == false);
    QVERIFY(field.at(0, 0) == true);
    QVERIFY(field.at(0, 1) == false);
    QVERIFY(field.at(1, 0) == false);
    QVERIFY(field.at(1, 1) == true);
    QVERIFY(field.at(1, 2) == false);
    QVERIFY(field.at(2, 1) == false);
    QVERIFY(field.at(2, 2) == false);
}

void Tests::field_at() {
    Field field{{true, false}, {false, true}};

    QVERIFY(field.at(0, 0) == true);
    field.at(0, 0) = false;
    QVERIFY(field.at(0, 0) == false);

    QVERIFY(field.at(1, 0) == false);
    field.at(1, 0) = true;
    QVERIFY(field.at(1, 0) == true);
}

void Tests::field_neighbours() {
    const Field field{{true, false}, {false, true}};

    QVERIFY(field.neighbours(0, 0) == 1);
    QVERIFY(field.neighbours(0, 1) == 2);
    QVERIFY(field.neighbours(1, 0) == 2);
    QVERIFY(field.neighbours(1, 1) == 1);
}

QTEST_MAIN(Tests)
#include "tests.moc"
