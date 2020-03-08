#include <iostream>
#include <memory>

#include "plugins/USB/Usb.h"


extern "C" Usb* create_object()
{
    return new Usb(0x0001, "USB");
}

extern "C" void destroy_object( Usb* object )
{
  delete object;
}

extern "C" void promptMessage(std::string & msg)
{
    std::cout << msg << "\n";
}
