
import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import QtCharts 2.1
import "../Delegates"
import "../Regulators"
import "../Pages"
import "../Popups"
import "../MenuClasses"
Item{
    Component.onCompleted:{console.log("main created");}
    Component.onDestruction:{console.log("main destructed");}
    property var defaultFocusItem: test1
    property var numel: 8
    property color mainColor: "#000000"
    width: parent.width
    height: parent.height
    focus: true
    id:secondpage
property var locale: Qt.locale()
    Column{
    property var elHeight: parent.height/numel;
    property var elWidth: 0.3*parent.width;
    anchors.left: parent.left;
    id:test1;
    spacing: 0
    width:elWidth;
    height:parent.height
        Button{text: "  R вала";   height:parent.elHeight;width:parent.elWidth;enabled:false;     }
        Button{text: "  R датчика №1";height:parent.elHeight;width:parent.elWidth;enabled:false;         }
        Button{text: "  R датчика №2";height:parent.elHeight;width:parent.elWidth;enabled:false;      }
        Button{text: "  R датчика №3";height:parent.elHeight;width:parent.elWidth;enabled:false;      }
        Button{text: "  T sample";height:parent.elHeight;width:parent.elWidth;enabled:false;      }
        Button{text: "  Diff";height:parent.elHeight;width:parent.elWidth;enabled:false;      }
        Button{text: "  Частота";height:parent.elHeight;width:parent.elWidth;enabled:false;      }
        Button{text: "  Назад";height:parent.elHeight;width:parent.elWidth;  onClicked: {dataSource.saveData();dataSource.reconf();dataSource.generateNet();stackView.source="ThirdPage.qml";}    }
    }
    Column{
    property var elHeight:parent.height/(numel);
    property var elWidth:0.65*parent.width;
    anchors.right: parent.right;
    id:test2;
    spacing: 0
    width:0.65*parent.width;
    height:parent.height;
        MenuInt{height:parent.elHeight; width:parent.elWidth; value:dataSource.c_R; }
        MenuInt{height:parent.elHeight; width:parent.elWidth; value:dataSource.c_r1}
        MenuInt{height:parent.elHeight; width:parent.elWidth; value:dataSource.c_r2}
        MenuInt{height:parent.elHeight; width:parent.elWidth; value:dataSource.c_r3}
        MenuInt{height:parent.elHeight; width:parent.elWidth; value:dataSource.t}
        MenuBool{height:parent.elHeight; width:parent.elWidth; value:dataSource.diff}
        MenuInt{height:parent.elHeight; width:parent.elWidth; value:dataSource.freqVal}
        //Regulator{height:parent.height/5; width:parent.width;  maxValue:100; currentVal: dataSource.c_R;     }
        //Regulator{height:parent.height/5; width:parent.width;  maxValue:10;   currentVal:  dataSource.c_r1;    }
        //Regulator{height:parent.height/5; width:parent.width;  maxValue:10;   currentVal:  dataSource.c_r2;     }
        //Regulator{height:parent.height/5; width:parent.width;    maxValue:10;  currentVal:  dataSource.c_r2;    }
    }

}
