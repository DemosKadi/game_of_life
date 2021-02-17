#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "field.h"
#include <optional>
#include <QVector>
#include <QString>

Row parse_line(QString line);
Field fix_row_sizes(Field field);
std::optional<Field> parse_input(QString path);
#endif
