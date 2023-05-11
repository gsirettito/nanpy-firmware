#ifndef TM1637_DISPLAY_CLASS
#define TM1637_DISPLAY_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class TM1637Display;

namespace nanpy
{
    class TM1637DisplayClass : public ObjectsManager<TM1637Display>
    {

    public:
        void elaborate(nanpy::MethodDescriptor *m);
        const char *get_firmware_id();
    };
}

#endif