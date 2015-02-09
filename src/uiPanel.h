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

#define UIPANEL_DEFAULT_WIDTH 170

class uiPanel
{
public:
    uiPanel(string name);
    ~uiPanel();

    void setLocation(const int x, const int y);
    void setWidth(const float width);
    ofxUICanvas* getGUI() { return gui; };

protected:
    ofxUICanvas *gui;
};

#endif
