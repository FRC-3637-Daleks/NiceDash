//
//  mqtt.h
//  NiceDash
//
//  Created by John Ott on 2/9/15.
//
//

#ifndef __NiceDash__mqtt__
#define __NiceDash__mqtt__

#include <iostream>

#include "mosquitto/cpp/mosquittopp.h"

class mqtt : public mosqpp::mosquittopp
{
public:
    mqtt(const char* id);
    ~mqtt();

    void on_connect(int rc);
    void on_disconnect(int rc);
    void on_message(const struct mosquitto_message *message);

    void start_thread();
};

#endif /* defined(__NiceDash__mqtt__) */
