//
//  mqtt.cpp
//  NiceDash
//
//  Created by John Ott on 2/9/15.
//
//

#include "mqtt.h"

mqtt::mqtt() : mosqpp::mosquittopp()
{
    status = mqtt::STATUS_DISCONNECTED;
}

mqtt::~mqtt()
{
}

void mqtt::on_connect(int rc)
{
    std::cout << "on_connect: " << rc << std::endl;
    // Subscribe to all
    if(rc){
        std::cout << "Failed to connect! rc: " << rc << std::endl;
        status = mqtt::STATUS_DISCONNECTED;
    }else{
        subscribe(NULL, "$SYS/broker/clients/#", 0);
        subscribe(NULL, "#", 0);
        status = mqtt::STATUS_CONNECTED;
    }
}

void mqtt::on_disconnect(int rc)
{
    std::cout << "on_disconnect: " << rc << std::endl;
    status = mqtt::STATUS_DISCONNECTED;
}

void mqtt::on_message(const struct mosquitto_message *message)
{
    std::string topic = (char*)message->topic;
    std::string payload = (char*)message->payload;

    std::cout << topic << ": " << payload << std::endl;

    data[std::string((char*)message->topic)] = atof(payload.c_str());
}

double mqtt::getData(std::string key)
{
    return data[key];
}
