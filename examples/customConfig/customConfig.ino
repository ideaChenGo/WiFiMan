#include <WiFiMan.h>
Config conf;
CustomConfig customConf;
void setup() 
{
  Serial.begin(115200);
  
  //create default object
  WiFiMan wman = WiFiMan();

  //add custom config, this must be called before wman.start()
  //with laber and addition required filed
  wman.addCustomArg("number","test-number","6","number","test number","required");
  //with label
  wman.addCustomArg("password","test-password","6","password","test password","");
  //or just the input text field
  wman.addCustomArg("","test-txt","6","text","test txt","");

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

  //get custom config parameters
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