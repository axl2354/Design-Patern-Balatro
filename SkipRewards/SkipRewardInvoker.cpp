#include "SkipRewardInvoker.h"
#include <algorithm>

void SkipRewardInvoker::addCommand(std::unique_ptr<SkipCommand> command) {
    if (command) {
        commands.push_back(std::move(command));
    }
}

void SkipRewardInvoker::executeAll() {
    for (auto& command : commands) {
        if (command) {
            command->execute();
        }
    }
    commands.clear();
}

void SkipRewardInvoker::executeByEvent(EventType eventType) {
    auto it = commands.begin();
    while (it != commands.end()) {
        if (*it && (*it)->getEventType() == eventType) {
            (*it)->execute();
            it = commands.erase(it);
        } else {
            ++it;
        }
    }
}

void SkipRewardInvoker::clearCommands() {
    commands.clear();
}
