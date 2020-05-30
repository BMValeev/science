import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "."
import "../Regulators"
Item{
    id:root
    property var value: modelData
    width:parent.width
    height:parent.height
    Date{
    id:something
        curSecond: 0
        curMinute: value.min
        curHour: value.hour
        curMonth: value.month
        curYear: value.year
        curDay: value.day
        Keys.onReturnPressed:{
            if(focusedItem>0){
                value.min=curMinute;
                value.hour=curHour;
                value.month=curMonth;
                value.year=curYear;
                value.day=curDay;
            }
        }
        Keys.onLeftPressed:  {if(focusedItem==0){main.navStatus("bool"); }}
        Keys.onRightPressed: {main.navStatus("date");}
    }
}
