#include "commands.h"
#include <QDebug>

AddRectCommand::AddRectCommand(Position pos, Dimension dim) : ICommand("add_rect")
{
    qDebug()<<pos.x<<pos.y<<dim.width<<dim.height;
}
