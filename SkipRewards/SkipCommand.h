#pragma once

enum class EventType {
    Instant,
    BlindEnter,
    BlindClear
};

class SkipCommand {
public:
    virtual ~SkipCommand() = default;
    virtual void execute() = 0;
    virtual EventType getEventType() const = 0;
};
