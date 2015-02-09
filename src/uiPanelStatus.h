//
//  uiPanelStatus.h
//  NiceDash
//
//  Created by John Ott on 1/27/15.
//
//

#ifndef __NiceDash__uiPanelStatus__
#define __NiceDash__uiPanelStatus__

#include "ofxUI.h"

#include "uiPanel.h"

class uiPanelStatus : public uiPanel
{
public:
    uiPanelStatus();
    ~uiPanelStatus();

    void update();
    
private:

    struct status_ui {
        ofxUILabel* conn_status;
    } ui;
};

#endif /* defined(__NiceDash__uiPanelStatus__) */
