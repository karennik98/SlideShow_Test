#include <QCoreApplication>
#include <QVector>
#include <QDebug>
#include <QString>

#include <memory>

#include "commandparser.h"
#include "token.h"
#include "commandbuilder.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CommandParser parser("add_rect -center (2,3) -size (20,30)");
    QVector<Token> tokens { parser.parse() };

    CommandBuilder bld(tokens);
    std::unique_ptr<ICommand> cmd = bld.build();

    for(const auto el : tokens)
    {
        qDebug() << el.name <<","<<QString::number(static_cast<int>(el.type));
    }

    return a.exec();
}
