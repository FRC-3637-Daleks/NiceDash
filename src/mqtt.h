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
#include <map>

#include "mosquitto/cpp/mosquittopp.h"

class mqtt : public mosqpp::mosquittopp
{
public:
    enum mqtt_status {
        STATUS_DISCONNECTED,
        STATUS_CONNECTED
    };

    mqtt();
    ~mqtt();

    void on_connect(int rc);
    void on_disconnect(int rc);
    void on_message(const struct mosquitto_message *message);

    mqtt_status getStatus() { return status; };
    double getData(std::string key);
    std::string getDataRaw(std::string key);

private:
    mqtt_status status;
    std::map<std::string, double> data;
    std::map<std::string, std::string> data_raw;
};

#endif /* defined(__NiceDash__mqtt__) */
