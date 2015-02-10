#include "mqtt_thread.h"

mqtt_thread::mqtt_thread(mqtt *m)
{
    mqtt_obj = m;
}

mqtt_thread::~mqtt_thread()
{
}

void mqtt_thread::threadedFunction()
{
    mqtt_obj->loop_forever();
}
