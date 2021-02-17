#ifndef FIELD_H
#define FIELD_H

#include <QVector>

class Row: public QVector<bool> {
public:
    using QVector<bool>::QVector;

    bool at(int x) const;
};

class Field: public QVector<Row> {
public:
    using QVector<Row>::QVector;

    bool at(int x, int y) const;
    bool& at(int x, int y);
    std::size_t neighbours(int x, int y) const;
};

#endif
