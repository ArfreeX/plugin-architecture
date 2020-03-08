#ifndef BASEPLUGIN_H
#define BASEPLUGIN_H

#include <string>


class BasePlugin
{
public:
    BasePlugin(int pluginID, std::string pluginName);

    virtual void sendMessage(char* message) = 0;
    virtual void receiveMessage() = 0;
    std::string getName();
    int getID();

private:
    const int ID;
    const std::string NAME;

};

#endif // BASEPLUGIN_H
