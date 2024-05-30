#pragma once

class Statuses final
{
private:
    bool _fireStatus;

    bool _torchStatus;

    bool _keyStatus;

public:
    Statuses(bool fireStatus, bool torchStatus, bool keyStatus);
    Statuses();
    ~Statuses() = default;

    bool fireStatus() const;
    bool fireStatus();

    bool torchStatus() const;
    bool torchStatus();

    bool keyStatus() const;
    bool keyStatus();

    void addFireStatus();
    void removeFireStatus();

    void addTorchStatus();
    void removeTorchStatus();

    void addKeyStatus();
    void removeKeyStatus();
};