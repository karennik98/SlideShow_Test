#include "commands.h"
#include <QDebug>

AddRectCommand::AddRectCommand(Position pos, Dimension dim, ID id) : ICommand("add_rect")
{
    qDebug()<<pos.x<<pos.y<<dim.width<<dim.height<<id;
}
