#pragma once

class Statuses final
{
private:
    bool _fireStatus;

    bool _torchStatus;

public:
    Statuses(bool fireStatus, bool torchStatus);
    Statuses();
    ~Statuses() = default;

    bool fireStatus() const;
    bool fireStatus();

    bool torchStatus() const;
    bool torchStatus();

    void addFireStatus();
    void removeFireStatus();

    void addTorchStatus();
    void removeTorchStatus();
};