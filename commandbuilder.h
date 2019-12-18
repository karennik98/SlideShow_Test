#ifndef COMMANDBUILDER_H
#define COMMANDBUILDER_H

#include "token.h"
#include "basic_types.h"
#include "declarations.h"

#include <QVector>
#include <QPair>

#include <memory>


constexpr uint32_t val_32_const = 0x811c9dc5;
constexpr uint32_t prime_32_const = 0x1000193;
constexpr uint64_t prime_64_const = 0x100000001b3;

inline constexpr uint32_t hash_function(const char* const str, const uint32_t value = val_32_const) noexcept {
    return (str[0] == '\0') ? value : hash_function(&str[1], (value ^ uint32_t(str[0])) * prime_32_const);
}

enum class CommandType : uint32_t {
    add_rect = hash_function("add_rect"),
    unknown_type = hash_function("unknown_type"),
};





class ICommand;

class CommandBuilder
{
public:
    CommandBuilder(const QVector<Token>& tokens)
        : mBegin(tokens.begin())
        , mEnd(tokens.end())
    {}
   ICommand* build();
private:
    CommandType getCommandType() const;
    std::tuple<Position, Dimension, ID> getAddRectCommandArgs();
    QPair<int, int> getIntegerValues();
    ID getIDValue();

    bool isCommandType() const;

    Token current() const;
    void eat();
private:
    QVector<Token>::const_iterator mBegin;
    QVector<Token>::const_iterator mEnd;
};

#endif // COMMANDBUILDER_H
