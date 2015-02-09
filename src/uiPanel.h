//
//  uiPanel.h
//  NiceDash
//
//  Created by John Ott on 1/27/15.
//
//

#ifndef NiceDash_uiPanel_h
#define NiceDash_uiPanel_h

#include "ofxUI.h"
#include "mqtt.h"

#define UIPANEL_DEFAULT_WIDTH   180
#define UIPANEL_INSIDE_WIDTH    (UIPANEL_DEFAULT_WIDTH - 8)

class uiPanel
{
public:
    uiPanel(string name);
    ~uiPanel();

    void setLocation(const int x, const int y);
    void setWidth(const float width);
    ofxUICanvas* getGUI() { return gui; };

    virtual void update(mqtt *mqtt_obj) { return; };

protected:
    ofxUICanvas *gui;
};

#endif
