//
//  uiPanelConfig.h
//  NiceDash
//
//  Created by John Ott on 1/26/15.
//
//

#ifndef __NiceDash__uiPanelConfig__
#define __NiceDash__uiPanelConfig__

#include <sstream>

#include "ofxUI.h"

#include "uiPanel.h"

class uiPanelConfig : public uiPanel
{
public:
    uiPanelConfig();
    ~uiPanelConfig();

    void update(mqtt *mqtt_obj);

    void init();

private:
    struct pdp_ui {
        ofxUILabel *precision;
        ofxUILabel *auton_mode;
    } ui;
};

#endif /* defined(__NiceDash__uiPanelConfig__) */
