#include <WiFiMan.h>

Config conf;
CustomConfig customConf;
void setup() 
{
  Serial.begin(115200);
  
  //create default object
  WiFiMan wman = WiFiMan();

  //custom config
  wman.addLabel("Custom configuration",true);
  wman.addTextBox("customText","12","text","place holder","required");
  wman.addCheckBox("customCheckBox","checked","Check box example",true);
  wman.addLabel("Radio button",true);
  wman.addRadioButton("customRadioButton","1","choice 1",false);
  wman.addRadioButton("customRadioButton","2","choice 2",false);
  wman.addRadioButton("customRadioButton","3","choice 3",true);

  
  wman.start();

  if(wman.getConfig(&conf))
  {
    //display device status
    Serial.println("Connected to AP");
    Serial.print("SSID : ");
    Serial.println(conf.wifiSsid);
    Serial.print("Passwd : ");
    Serial.println(conf.wifiPasswd);
    Serial.print("Master password : ");
    Serial.println(conf.masterPasswd);
  }
    if(wman.getCustomConfig(&customConf))
  {
    for(int i=0;i<customConf.count;i++)
    {
      Serial.print(customConf.args[i].key);
      Serial.print(" = ");
      Serial.println(customConf.args[i].value);
    }
  }
}

void loop() {
  //
}