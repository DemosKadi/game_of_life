#include "game.h"
#include "input_parser.h"

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QTimer>


auto main(int argc, char *argv[]) -> int {
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("Game of life");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("A simple game of life simulator");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("input", "Initial setup of the simulation");
    parser.addOptions({
        {{"W", "width"}, "Set width of the simulation", "width", "30"},
        {{"H", "height"}, "Set height of the simulation", "height", "30"},
        {{"t", "time"}, "Time between simulation steps in ms", "time", "500"},
        {{"x", "xoffset"}, "Input offset for x axis (starts top left)", "xoffset", "0"},
        {{"y", "yoffset"}, "Input offset for y axis (starts top left)", "yoffset", "0"},
    });

    parser.process(a);

    const std::size_t width{
        static_cast<std::size_t>(parser.value("width").toInt())};
    const std::size_t height{
        static_cast<std::size_t>(parser.value("height").toInt())};
    const std::size_t time{
        static_cast<std::size_t>(parser.value("time").toInt())};
    const std::size_t xoffset{
        static_cast<std::size_t>(parser.value("xoffset").toInt())};
    const std::size_t yoffset{
        static_cast<std::size_t>(parser.value("yoffset").toInt())};

    QString input{};
    const QStringList positional_arguments{parser.positionalArguments()};
    if(positional_arguments.size() > 0) { input = positional_arguments[0]; }

    const auto input_field = parse_input(input).value_or(Field{});
    Game game_of_life(width, height, input_field, xoffset, yoffset);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&game_of_life]() {
        game_of_life.print();
        game_of_life.tick();
    });

    timer.start(time);

    return a.exec();
}
