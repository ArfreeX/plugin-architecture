#include <dlfcn.h>

#include "PluginManager.h"
#include "plugins/BasePlugin.h"


PluginManager::PluginManager()
{

}

bool PluginManager::loadPlugins(std::string& pluginPath)
{
    std::cout << "Loading plugins" << "\n";
    std::string usbPluginPath = pluginPath + "/libusb.so";
    void* handle = dlopen(usbPluginPath.c_str(), RTLD_LAZY);
    BasePlugin* (*create)();

    void (*destroy)(BasePlugin*);

    create = (BasePlugin* (*)())dlsym(handle, "create_object");

    destroy = (void (*)(BasePlugin*))dlsym(handle, "destroy_object");

    BasePlugin* myClass = (BasePlugin*)create();
    std::cout << myClass->getName() << "\n";
    myClass->sendMessage("ABCD");
    //destroy( myClass );
    return true;
}

bool PluginManager::handlePropertyChange()
{
    return true;
}

uint32_t PluginManager::getProperty(uint32_t propertyId)
{
    return 0x0012;
}
