//
//  uiPanelStatus.cpp
//  NiceDash
//
//  Created by John Ott on 1/27/15.
//
//

#include "uiPanelStatus.h"

uiPanelStatus::uiPanelStatus() : uiPanel("status")
{
    memset(&ui, 0, sizeof(status_ui));

    // HEADER
    gui->addLabel("STATUS");

    gui->addSpacer(UIPANEL_INSIDE_WIDTH, 1);

    // CONNECTION STATUS
    ui.conn_status = gui->addLabel("CONN", "DISCONNECTED");

    //gui->addSpacer(UIPANEL_INSIDE_WIDTH, 1);

    // CLIENTS CONNECTED
    ui.clients_connected = gui->addLabel("CLIENTS", "CLIENTS:", OFX_UI_FONT_SMALL);

    // CLIENTS ACTIVE
    ui.clients_active = gui->addLabel("ACTIVE", "ACTIVE:", OFX_UI_FONT_SMALL);

    gui->addSpacer(UIPANEL_INSIDE_WIDTH, 1);

    // FPS
    gui->addFPSSlider("FPS", UIPANEL_INSIDE_WIDTH, 20);

    gui->autoSizeToFitWidgets();
    gui->setWidth(UIPANEL_DEFAULT_WIDTH);
}

uiPanelStatus::~uiPanelStatus()
{
}

void uiPanelStatus::update(mqtt *mqtt_obj)
{
    if (mqtt_obj->getStatus() == mqtt::STATUS_CONNECTED) {
        ui.conn_status->setLabel("CONNECTED");
        ui.conn_status->setColorFill(ofxUIColor(0, 255, 0));
    } else {
        ui.conn_status->setLabel("DISCONNECTED");
        ui.conn_status->setColorFill(ofxUIColor(255, 0, 0));
    }

    stringstream clients;
    clients << "CLIENTS: " << mqtt_obj->getData("$SYS/broker/clients/total");
    ui.clients_connected->setLabel(clients.str());

    stringstream active;
    active << "ACTIVE: " << mqtt_obj->getData("$SYS/broker/clients/active");
    ui.clients_active->setLabel(active.str());
}
