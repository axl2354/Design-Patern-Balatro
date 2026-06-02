#pragma once

#include <memory>
#include <vector>
#include "SkipCommand.h"

class SkipRewardInvoker {
public:
    void addCommand(std::unique_ptr<SkipCommand> command);
    void executeAll();
    void executeByEvent(EventType eventType);
    void clearCommands();

private:
    std::vector<std::unique_ptr<SkipCommand>> commands;
};
