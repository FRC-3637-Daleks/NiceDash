//
//  uiPanelConfig.cpp
//  NiceDash
//
//  Created by John Ott on 1/26/15.
//
//

#include "uiPanelConfig.h"

uiPanelConfig::uiPanelConfig() : uiPanel("Config")
{
    memset(&ui, 0, sizeof(pdp_ui));

    // HEADER
    gui->addLabel("CONFIG");

    gui->addSpacer(UIPANEL_INSIDE_WIDTH, 1);

    // PRECISION
    gui->addLabel("PRECISION", OFX_UI_FONT_MEDIUM);
    ui.precision = gui->addLabel("PERCISION", "DISABLED", OFX_UI_FONT_LARGE);

    gui->addSpacer(UIPANEL_INSIDE_WIDTH, 1);

    // AUTON MODE
    gui->addLabel("AUTO MODE", OFX_UI_FONT_MEDIUM);
    ui.auton_mode = gui->addLabel("AUTOMODE", "", OFX_UI_FONT_LARGE);

    gui->addSpacer(UIPANEL_INSIDE_WIDTH, 1);

    gui->autoSizeToFitWidgets();
    gui->setWidth(UIPANEL_DEFAULT_WIDTH);
}

uiPanelConfig::~uiPanelConfig()
{
}

void uiPanelConfig::update(mqtt *mqtt_obj)
{
    ui.precision->setLabel(mqtt_obj->getDataRaw("roborio/operatorconsole/precision"));
    ui.auton_mode->setLabel(mqtt_obj->getDataRaw("roborio/config/auto_mode"));
}
