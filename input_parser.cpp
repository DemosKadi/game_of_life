#include "input_parser.h"

#include <QDebug>
#include <QFile>
#include <algorithm>

Row parse_line(QString line) {
    Row ret;
    ret.reserve(line.length());
    for(const auto c: line) {
        ret.push_back(c == 'x');
    }
    return ret;
}

Field fix_row_sizes(Field field) {
    const auto max_size = std::max_element(
        field.begin(), field.end(),
        [](Row lhs, Row rhs) {
            return lhs.size() < rhs.size();
        })->size();

    for(Row& row: field) {
        if(row.size() < max_size) { row.resize(max_size); }
    }

    return field;
}

std::optional<Field> parse_input(QString path) {
    QFile input{path};
    if(!input.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Could not open file:" << path;
        return std::nullopt;
    }

    Field ret_field;
    QTextStream in(&input);
    while(!in.atEnd()) {
        ret_field.push_back(parse_line(in.readLine()));
    }

    return fix_row_sizes(ret_field);
}
