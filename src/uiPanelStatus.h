//
//  uiPanelStatus.h
//  NiceDash
//
//  Created by John Ott on 1/27/15.
//
//

#ifndef __NiceDash__uiPanelStatus__
#define __NiceDash__uiPanelStatus__

#include <sstream>

#include "ofxUI.h"

#include "uiPanel.h"

class uiPanelStatus : public uiPanel
{
public:
    uiPanelStatus();
    ~uiPanelStatus();

    void update(mqtt *mqtt_obj);

private:
    struct status_ui {
        ofxUILabel *conn_status;
        ofxUILabel *clients_connected;
        ofxUILabel *clients_active;
    } ui;
};

#endif /* defined(__NiceDash__uiPanelStatus__) */
