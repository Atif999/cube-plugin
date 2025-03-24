# JSON Tree Viewer Plugin for CubeGUI

## 📌 Overview

This project is a **CubeGUI Plugin** that provides a **JSON Tree Viewer**. It allows users to **load a JSON file (`system_tree.json`) and visualize its key-value structure** inside the CubeGUI framework.

## 🎯 Features

✅ Integrates with **CubeGUI** as a plugin  
✅ Displays **JSON data** in a hierarchical **tree view**  
✅ Reads from `system_tree.json` and parses **key-value pairs**  
✅ Uses **Qt5** for GUI implementation  
✅ Structured code with **modular design**

---

## 🛠 Installation & Setup

### **1⃣ Prerequisites**

Ensure you have the following installed on your system:

- **C++17 or later**
- **Qt5 (Core, Widgets)**
- **CMake (≥ 3.10)**
- **CubeGUI Framework** (with headers and libraries available)

### **3⃣ Build the Plugin**

```sh
mkdir build && cd build
cmake ..
make
```

### **4⃣ Install the Plugin into CubeGUI**

```sh
make install
```

This will copy the plugin `.so` file into CubeGUI’s `cube-plugins` directory.

---

---

## 💂️‍♂️ Project Structure

```
json-tree-plugin/
│── src/
│   ├── JsonTreePlugin.h       # Plugin header (interface definitions)
│   ├── JsonTreePlugin.cpp     # Plugin implementation (logic & UI)
│── CMakeLists.txt             # Build system configuration
│── system_tree.json           # Sample JSON data file
│── README.md                  # Project documentation
```
