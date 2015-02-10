#ifndef MQTT_THREAD_H
#define MQTT_THREAD_H

#include "ofMain.h"

#include "mqtt.h"

class mqtt_thread : public ofThread
{
public:
    mqtt_thread(mqtt *m);
    ~mqtt_thread();
    void threadedFunction();

private:
    mqtt *mqtt_obj;
};

#endif // MQTT_THREAD_H
