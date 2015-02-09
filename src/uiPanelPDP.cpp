//
//  uiPanelPDP.cpp
//  NiceDash
//
//  Created by John Ott on 1/26/15.
//
//

#include "uiPanelPDP.h"

uiPanelPDP::uiPanelPDP() : uiPanel("PDP")
{
    memset(&ui, 0, sizeof(pdp_ui));

    // HEADER
    gui->addLabel("PDP");

    gui->addSpacer(UIPANEL_INSIDE_WIDTH, 1);

    // CURRENT
    for (int i=0; i < 16; i++) {
        if (i == 0 or i == 8)
            gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
        else
            gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
        ui.current.push_back(gui->addSlider(ofToString(i+1, 2, '0'), 0.0f, 40.0f, 0.0f, PDP_WIDTH, PDP_HEIGHT));
    }
    gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);

    gui->addSpacer(UIPANEL_INSIDE_WIDTH, 1);

    // VOLTAGE
    ui.voltage = gui->addSlider("Voltage", 0.0f, 16.0f, 0.0f, UIPANEL_INSIDE_WIDTH, 20.0f);

    gui->addSpacer(UIPANEL_INSIDE_WIDTH, 1);

    // TEMPERATURE
    ui.temperature = gui->addSlider("Temperature", 0.0f, 100.0f, 0.0f, UIPANEL_INSIDE_WIDTH, 20.0f);

    gui->autoSizeToFitWidgets();
    gui->setWidth(UIPANEL_DEFAULT_WIDTH);
}

uiPanelPDP::~uiPanelPDP()
{
}

void uiPanelPDP::update(mqtt *mqtt_obj)
{
    for(int i = 0; i < 16; i++) {
        std::stringstream key;
        key << "pdp/current_" << (i + 1);
        ui.current[i]->setValue(float(mqtt_obj->getData(key.str())));
    }

    ui.voltage->setValue(float(mqtt_obj->getData("pdp/voltage")));
    ui.temperature->setValue(float(mqtt_obj->getData("pdp/temperature")));
}