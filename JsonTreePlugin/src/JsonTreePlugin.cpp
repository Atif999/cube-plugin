#include "JsonTreePlugin.h"

JsonTreePlugin::JsonTreePlugin() : mainWidget(nullptr), service(nullptr) {
    // Constructor initializes pointers to nullptr (prevents uninitialized memory issues)
}

JsonTreePlugin::~JsonTreePlugin() {
    
// Returns the version of the plugin
void JsonTreePlugin::version(int& major, int& minor, int& bugfix) const {
    major = 1;  // Major version
    minor = 0;  // Minor version
    bugfix = 0;  // Bugfix version
}

// Returns the plugin name to be displayed in CubeGUI
QString JsonTreePlugin::name() const {
    return "JSON Tree Viewer";
}

// Returns the main UI widget of the plugin
QWidget* JsonTreePlugin::widget() {
    return mainWidget;
}

// Called when the plugin is opened in CubeGUI
void JsonTreePlugin::opened(cubepluginapi::PluginServices* service) {
    this->service = service;  // Store the service pointer for later use

    mainWidget = new QWidget();  // Create a new main widget
}