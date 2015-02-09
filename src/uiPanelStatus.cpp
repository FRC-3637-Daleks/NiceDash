//
//  uiPanelStatus.cpp
//  NiceDash
//
//  Created by John Ott on 1/27/15.
//
//

#include "uiPanelStatus.h"
#define UIPANEL_WIDTH 100

uiPanelStatus::uiPanelStatus() : uiPanel("status")
{
    memset(&ui, 0, sizeof(status_ui));

    // HEADER
    gui->addLabel("STATUS");

    gui->addSpacer(UIPANEL_WIDTH, 1);

    // CONNECTION STATUS
    ui.conn_status = gui->addLabel("CONN", "DISCONNECTED");

    gui->addSpacer(UIPANEL_WIDTH, 1);

    // FPS
    gui->addFPSSlider("FPS", UIPANEL_WIDTH, 20);

    gui->autoSizeToFitWidgets();
    gui->setWidth(UIPANEL_DEFAULT_WIDTH);

}

uiPanelStatus::~uiPanelStatus()
{
    delete gui;
}

void uiPanelStatus::update()
{
//    if (NetworkTable::IsStaticConnected()) {
//        ui.conn_status->setLabel("CONNECTED");
//        ui.conn_status->setColorFill(ofxUIColor(0, 255, 0));
//    } else {
//        ui.conn_status->setLabel("DISCONNECTED");
//        ui.conn_status->setColorFill(ofxUIColor(255, 0, 0));
//    }
}
