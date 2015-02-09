//
//  uiPanelPDP.h
//  NiceDash
//
//  Created by John Ott on 1/26/15.
//
//

#ifndef __NiceDash__uiPanelPDP__
#define __NiceDash__uiPanelPDP__

#include <sstream>

#include "ofxUI.h"

#include "uiPanel.h"

#define PDP_WIDTH   15
#define PDP_HEIGHT  120

class uiPanelPDP : public uiPanel
{
public:
    uiPanelPDP();
    ~uiPanelPDP();

    void update(mqtt *mqtt_obj);

    void init();

private:
    struct pdp_ui {
        vector<ofxUISlider *> current;
        ofxUISlider *voltage;
        ofxUISlider *temperature;
    } ui;
};

#endif /* defined(__NiceDash__uiPanelPDP__) */
