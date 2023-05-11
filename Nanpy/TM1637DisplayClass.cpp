#include "cfg.h"

#if USE_TM1637Display

#include <Arduino.h>
#include <TM1637Display.h>
#include "TM1637DisplayClass.h"
#include <stdlib.h>

const char *nanpy::TM1637DisplayClass::get_firmware_id()
{
    return "TM1637Display";
}

void nanpy::TM1637DisplayClass::elaborate(MethodDescriptor *m)
{
    ObjectsManager<TM1637Display>::elaborate(m);

    if (strcmp(m->getName(), "new") == 0)
    {
        int clk_pin = m->getInt(0);
        int dio_pin = m->getInt(1);
        // int bitDelay = m->getInt(2);

        v.insert(new TM1637Display(clk_pin, dio_pin, 100));
        m->returns(v.getLastIndex());
    }
    if (strcmp(m->getName(), "setBrightness") == 0)
    {
        if (m->getNArgs() == 2)
        {
            v[m->getObjectId()]->setBrightness(m->getInt(0), m->getInt(1));
            m->returns(0);
        }
        else if (m->getNArgs() == 1)
        {
            v[m->getObjectId()]->setBrightness(m->getInt(0));
            m->returns(0);
        }
    }
    if (strcmp(m->getName(), "showNumberDec") == 0)
    {
        if (m->getNArgs() == 4)
        {
            int num = m->getInt(0);
            bool leading_zero = m->getBool(1);
            uint8_t length = m->getInt(2);
            uint8_t pos = m->getInt(3);
            v[m->getObjectId()]->showNumberDec(num, leading_zero, length, pos);
        }
        else if (m->getNArgs() == 3)
        {
            int num = m->getInt(0);
            bool leading_zero = m->getBool(1);
            uint8_t length = m->getInt(2);
            v[m->getObjectId()]->showNumberDec(num, leading_zero, length, 0);
        }
        else if (m->getNArgs() == 2)
        {
            int num = m->getInt(0);
            bool leading_zero = m->getBool(1);
            v[m->getObjectId()]->showNumberDec(num, leading_zero, 4, 0);
        }
        else if (m->getNArgs() == 1)
        {
            int num = m->getInt(0);
            v[m->getObjectId()]->showNumberDec(num, false, 4, 0);
        }
        m->returns(0);
    }
    if (strcmp(m->getName(), "showNumberDecEx") == 0)
    {
        if (m->getNArgs() == 5)
        {
            int num = m->getInt(0);
            uint8_t dots = m->getInt(1);
            bool leading_zero = m->getBool(2);
            uint8_t length = m->getInt(3);
            uint8_t pos = m->getInt(4);
            v[m->getObjectId()]->showNumberDecEx(num, dots, leading_zero, length, pos);
        }
        else if (m->getNArgs() == 4)
        {
            int num = m->getInt(0);
            uint8_t dots = m->getInt(1);
            bool leading_zero = m->getBool(2);
            uint8_t length = m->getInt(3);
            v[m->getObjectId()]->showNumberDecEx(num, dots, leading_zero, length, 0);
        }
        else if (m->getNArgs() == 3)
        {
            int num = m->getInt(0);
            uint8_t dots = m->getInt(1);
            bool leading_zero = m->getBool(2);
            v[m->getObjectId()]->showNumberDecEx(num, dots, leading_zero, 4, 0);
        }
        else if (m->getNArgs() == 2)
        {
            int num = m->getInt(0);
            uint8_t dots = m->getInt(1);
            v[m->getObjectId()]->showNumberDecEx(num, dots, false, 4, 0);
        }
        else if (m->getNArgs() == 1)
        {
            int num = m->getInt(0);
            v[m->getObjectId()]->showNumberDecEx(num, 0, false, 4, 0);
        }
        m->returns(0);
    }
    if (strcmp(m->getName(), "showNumberHexEx") == 0)
    {
        if (m->getNArgs() == 5)
        {
            uint16_t num = m->getInt(0);
            uint8_t dots = m->getInt(1);
            bool leading_zero = m->getBool(2);
            uint8_t length = m->getInt(3);
            uint8_t pos = m->getInt(4);
            v[m->getObjectId()]->showNumberHexEx(num, dots, leading_zero, length, pos);
        }
        else if (m->getNArgs() == 4)
        {
            uint16_t num = m->getInt(0);
            uint8_t dots = m->getInt(1);
            bool leading_zero = m->getBool(2);
            uint8_t length = m->getInt(3);
            v[m->getObjectId()]->showNumberHexEx(num, dots, leading_zero, length, 0);
        }
        else if (m->getNArgs() == 3)
        {
            uint16_t num = m->getInt(0);
            uint8_t dots = m->getInt(1);
            bool leading_zero = m->getBool(2);
            v[m->getObjectId()]->showNumberHexEx(num, dots, leading_zero, 4, 0);
        }
        else if (m->getNArgs() == 2)
        {
            uint16_t num = m->getInt(0);
            uint8_t dots = m->getInt(1);
            v[m->getObjectId()]->showNumberHexEx(num, dots, false, 4, 0);
        }
        else if (m->getNArgs() == 1)
        {
            uint16_t num = m->getInt(0);
            uint8_t dots = m->getInt(1);
            v[m->getObjectId()]->showNumberHexEx(num, 0, false, 4, 0);
        }
        m->returns(0);
    }
    if (strcmp(m->getName(), "setSegments") == 0)
    {
        if (m->getNArgs() == 3)
        {
            uint8_t *segments = (uint8_t *)(m->getInt(0));
            uint8_t length = m->getInt(1);
            uint8_t pos = m->getInt(2);
            v[m->getObjectId()]->setSegments(segments, length, pos);
        }
        else if (m->getNArgs() == 2)
        {
            uint8_t *segments = (uint8_t *)(m->getInt(0));
            uint8_t length = m->getInt(1);
            v[m->getObjectId()]->setSegments(segments, length, 0);
        }
        else if (m->getNArgs() == 1)
        {
            uint8_t *segments = (uint8_t *)(m->getInt(0));
            v[m->getObjectId()]->setSegments(segments, 4, 0);
        }
        m->returns(0);
    }
    if (strcmp(m->getName(), "clear") == 0)
    {
        v[m->getObjectId()]->clear();
        m->returns(0);
    }
    if (strcmp(m->getName(), "encodeDigit") == 0)
    {
        uint8_t digit = m->getByte(0);
        m->returns(v[m->getObjectId()]->encodeDigit(digit));
    }
};
#endif