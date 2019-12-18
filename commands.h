#ifndef COMMANDS_H
#define COMMANDS_H

#include "ICommand.h"
#include "basic_types.h"
#include "declarations.h"

class AddRectCommand : public ICommand
{
public:
    AddRectCommand()=default;
    AddRectCommand(Position pos, Dimension dim, ID id);
    virtual void execute() override{}
};


#endif // COMMANDS_H
