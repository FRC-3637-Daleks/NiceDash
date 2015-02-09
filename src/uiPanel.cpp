//
//  uiPanel.cpp
//  NiceDash
//
//  Created by John Ott on 2/9/15.
//
//

#include "uiPanel.h"

uiPanel::uiPanel(string name)
{
    gui = new ofxUICanvas();
    gui->setName(name);
    gui->setPadding(3.0f);
    gui->setFont("GUI/Roboto-Regular.ttf");

    gui->setWidth(UIPANEL_DEFAULT_WIDTH);
}

uiPanel::~uiPanel()
{
    delete gui;
}

void uiPanel::setLocation(const int x, const int y)
{
    gui->setPosition(x, y);
}

void uiPanel::setWidth(const float width)
{
    gui->autoSizeToFitWidgets();
    gui->setWidth(width);
}