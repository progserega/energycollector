import QtQuick 2.4

ByAddressP1Form {
    buttonCitySearch.onClicked: {

        //cppObject.cppMethod();
  //      listModelCitySearchId.append({name:"text", colorCode:"red"});
        /*listModelCitySearchId.append("text1");
        listModelCitySearchId.append("test2");
        listModelCitySearchId.append({name:"text3"});
        listModelCitySearchId.append({text:"text4"});
*/
        console.log("Поиск:" + textFieldCityName.text);
        cppObject.cppMethod(textFieldCityName.text);

    }
}
