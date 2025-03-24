#include "JsonTreePlugin.h"
#include <QVBoxLayout>
#include <QTreeWidget
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

JsonTreePlugin::JsonTreePlugin() : mainWidget(nullptr), service(nullptr) {
    // Constructor initializes pointers to nullptr (prevents uninitialized memory issues)
}

JsonTreePlugin::~JsonTreePlugin() {


}
    
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
    this->service = service;

    
    mainWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(mainWidget);
    treeWidget = new QTreeWidget();
    treeWidget->setHeaderLabels({"Key", "Value"});

    loadJsonTree();  //New function for JSON loading

    layout->addWidget(treeWidget);
    mainWidget->setLayout(layout);

}

// New function to handle JSON loading
void JsonTreePlugin::loadJsonTree() {
    QFile file("system_tree.json");
    if (!file.open(QIODevice::ReadOnly)) {  // Ensure file is successfully opened
        qWarning("Failed to open JSON file.");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull() || !jsonDoc.isObject()) {  //  Ensure JSON is valid
        qWarning("Invalid JSON format.");
        return;
    }

    QJsonObject rootObject = jsonDoc.object();
    for (auto key : rootObject.keys()) {  // Iterate through JSON keys
        QTreeWidgetItem* item = new QTreeWidgetItem(treeWidget);
        item->setText(0, key);  // Set key
        item->setText(1, rootObject[key].toString());  // Set value
        treeWidget->addTopLevelItem(item);
    }
}