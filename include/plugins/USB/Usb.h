#ifndef USB_H
#define USB_H

#include "plugins/BasePlugin.h"


class Usb : private BasePlugin
{
public:
    Usb(int id, std::string name);
    ~Usb();

    void sendMessage(char *message) override;
    void receiveMessage() override;
    std::string getName();

private:

};

#endif // USB_H
