import QtQuick 2.7

Page1Form {
    button1.onClicked: {
        console.log("Button 1 clicked.");
 //       swipeView.currentIndex=2;
        swipeView.itemAt(1);
    }
    button2.onClicked: {
        console.log("Button 2 clicked.");
        swipeView.itemAt(2);
    }
    button3.onClicked: {
        console.log("Button 3 clicked.");
    }
}
