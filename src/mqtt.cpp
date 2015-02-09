//
//  mqtt.cpp
//  NiceDash
//
//  Created by John Ott on 2/9/15.
//
//

#include "mqtt.h"

mqtt::mqtt(const char* id) : mosqpp::mosquittopp(id)
{
}

mqtt::~mqtt()
{
}

void mqtt::on_connect(int rc)
{
    std::cout << "on_connect: " << rc << std::endl;
    // Subscribe to all functions
    if(rc){
        std::cout << "Failed to connect! rc: " << rc << std::endl;
    }else{
        subscribe(NULL, "$SYS/broker/clients/total", 0);
    }
    return;
}

void mqtt::on_disconnect(int rc)
{
    std::cout << "on_disconnect: " << rc << std::endl;
}

void mqtt::on_message(const struct mosquitto_message *message)
{
    // Update value in local data store
    std::cout << (char*)message->topic << ": " << (char*)message->payload << std::endl;
}