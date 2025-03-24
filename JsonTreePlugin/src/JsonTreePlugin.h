#ifndef JSONTREEPLUGIN_H
#define JSONTREEPLUGIN_H

#include <QtPlugin>
#include <QWidget>
#include "PluginServices.h"   //Required to interact with CubeGUI
#include "TabInterface.h"    
#include <cubegui-config.h>  

//JsonTreePlugin class implements the CubeGUI TabInterface
class JsonTreePlugin : public QObject, public cubepluginapi::TabInterface
{
    Q_OBJECT  // Enables Qt's meta-object system (signals/slots, etc.)
    Q_INTERFACES(cubepluginapi::TabInterface)  // Registers the plugin as a CubeGUI tab
    Q_PLUGIN_METADATA(IID "org.scalasca.cubegui.JsonTreePlugin")  // Defines the plugin metadata

private:
    QTreeWidget* treeWidget;  //  Store tree widget for reuse
    void loadJsonTree();  // New function for loading JSON

public:
    explicit JsonTreePlugin();   // Constructor
    virtual ~JsonTreePlugin();   //  Destructor

    // Implement required methods from the TabInterface
    void version(int& major, int& minor, int& bugfix) const override;  // Returns plugin version
    QString name() const override;  // Returns plugin name
    QWidget* widget() override;  // Returns the main UI widget
    void opened(cubepluginapi::PluginServices* service) override;  // Called when plugin is opened

private:
    QWidget* mainWidget;  // Pointer to the plugin's main UI component
    cubepluginapi::PluginServices* service;  // Stores CubeGUI services
};

#endif // JSONTREEPLUGIN_H