#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

const byte DNS_PORT = 53;
IPAddress apIP(193, 168, 0, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);

const char* ssid="AJNIN";
const char* passwd="f!oxyou!!!.";

int led_0 = 16; //D0 or GPIO16
int led_1 = 5; //D1 or GPIO5
int led_2 = 4; //D2 or GPIO4
int led_3 = 0; //D3 or GPIO0
int led_4 = 2; //D4 or GPIO2
int led_5 = 14; //D5 or GPIO14
int led_6 = 12; //D6 or GPIO12
int led_7 = 13; //D7 or GPIO13
int led_8 = 15; //D8 or GPI015

String responseHTML = ""
  "<!DOCTYPE html><html><head>"
  "<meta charset='utf-8'>"
  "<meta name='viewport' content='width=device-width, initial-scale=1'>"
  "<title>Ninja</title></head><body>"
  "<center><br><br><br>"
  "<h2>Ninja Switch</h2>"
  "<div class='bg'>"
  "<a class='grn' href=/bon>BuiltIn LED Turn On</a>"
  "<a class='red' href=/boff>BuiltIn LED Turn Off</a>"
  "</div>"
  "<div class='bg'>"
  "<a class='grn' href=/0on>D0|GPIO16 Turn On</a>"
  "<a class='red' href=/0off>D0|GPIO16 Turn Off</a>"
  "</div>"
  "<div class='bg'>"
  "<a class='grn' href=/1on>D1|GPIO5 Turn On</a>"
  "<a class='red' href=/1off>D1|GPIO5 Turn Off</a>"
  "</div>"
  "<div class='bg'>"
  "<a class='grn' href=/2on>D2|GPIO4 Turn On</a>"
  "<a class='red' href=/2off>D2|GPIO4 Turn Off</a>"
  "</div>"
  "<div class='bg'>"
  "<a class='grn' href=/3on>D3|GPIO0 Turn On</a>"
  "<a class='red' href=/3off>D3|GPIO0 Turn Off</a>"
  "</div>"
  "<div class='bg'>"
  "<a class='grn' href=/4on>D4|GPIO2 Turn On</a>"
  "<a class='red' href=/4off>D4|GPIO2 Turn Off</a>"
  "</div>"
  "<div class='bg'>"
  "<a class='grn' href=/5on>D5|GPIO14 Turn On</a>"
  "<a class='red' href=/5off>D5|GPIO14 Turn Off</a>"
  "</div>"
  "<div class='bg'>"
  "<a class='grn' href=/6on>D6|GPIO12 Turn On</a>"
  "<a class='red' href=/6off>D6|GPIO12 Turn Off</a>"
  "</div>"
  "<div class='bg'>"
  "<a class='grn' href=/7on>D7|GPIO13 Turn On</a>"
  "<a class='red' href=/7off>D7|GPIO13 Turn Off</a>"
  "</div>"
  "<div class='bg'>"
  "<a class='grn' href=/8on>D8|GPIO15 Turn On</a>"
  "<a class='red' href=/8off>D8|GPIO15 Turn Off</a>"
  "</div>"
  "</center>"
  "</body>"
  "<style>.bg{background-color:#232323; margin: 10px; border-radius: 10px; border: 3px dotted darkcyan; padding:10px; width: 20%;}body{user-select: none;background-color: #303030;margin: 0;height: 100vh;}center{height: 100%;}.grn{background-color: green;}.red{background-color: maroon;}h2{color: cyan;font-family: sans-serif;margin: 0;}a{user-select: none;color: cyan;font-family: sans-serif;text-decoration: none;display: block;padding: 10px;margin: 5px;border-radius: 10px;border: 1px solid cyan;}a:active{background-color: rgb(0,0,0, 0.1);}@media (max-width: 900px){.bg{width: 70%}}</style>"
  "</html>";

String led_onBuilt(){
  digitalWrite(LED_BUILTIN, LOW);
  return responseHTML;
}

String led_offBuilt(){
  digitalWrite(LED_BUILTIN, HIGH); 
  return responseHTML;
}

String led_on0(){
  digitalWrite(led_0, HIGH);
  return responseHTML;
}

String led_off0(){
  digitalWrite(led_0, LOW); 
  return responseHTML;
}

String led_on1(){
  digitalWrite(led_1, HIGH);
  return responseHTML;
}

String led_off1(){
  digitalWrite(led_1, LOW); 
  return responseHTML;
}

String led_on2(){
  digitalWrite(led_2, HIGH);
  return responseHTML;
}

String led_off2(){
  digitalWrite(led_2, LOW); 
  return responseHTML;
}

String led_on3(){
  digitalWrite(led_3, HIGH);
  return responseHTML;
}

String led_off3(){
  digitalWrite(led_3, LOW); 
  return responseHTML;
}

String led_on4(){
  digitalWrite(led_4, HIGH);
  return responseHTML;
}

String led_off4(){
  digitalWrite(led_4, LOW); 
  return responseHTML;
}

String led_on5(){
  digitalWrite(led_5, HIGH);
  return responseHTML;
}

String led_off5(){
  digitalWrite(led_5, LOW); 
  return responseHTML;
}

String led_on6(){
  digitalWrite(led_6, HIGH);
  return responseHTML;
}

String led_off6(){
  digitalWrite(led_6, LOW); 
  return responseHTML;
}

String led_on7(){
  digitalWrite(led_7, HIGH);
  return responseHTML;
}

String led_off7(){
  digitalWrite(led_7, LOW); 
  return responseHTML;
}

String led_on8(){
  digitalWrite(led_8, HIGH);
  return responseHTML;
}

String led_off8(){
  digitalWrite(led_8, LOW); 
  return responseHTML;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led_0, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(led_7, OUTPUT);
  pinMode(led_8, OUTPUT);

  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(ssid);

  WiFi.begin(ssid, passwd);

  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

  // if DNSServer is started with "*" for domain name, it will reply with
  // provided IP to all DNS request
  dnsServer.start(DNS_PORT, "*", apIP);
  webServer.on("/bon",[]() { webServer.send(200, "text/html", led_onBuilt()); });
  webServer.on("/boff",[]() { webServer.send(200, "text/html", led_offBuilt()); });
  webServer.on("/0on",[]() { webServer.send(200, "text/html", led_on0()); });
  webServer.on("/0off",[]() { webServer.send(200, "text/html", led_off0()); });
  webServer.on("/1on",[]() { webServer.send(200, "text/html", led_on1()); });
  webServer.on("/1off",[]() { webServer.send(200, "text/html", led_off1()); });
  webServer.on("/2on",[]() { webServer.send(200, "text/html", led_on2()); });
  webServer.on("/2off",[]() { webServer.send(200, "text/html", led_off2()); });
  webServer.on("/3on",[]() { webServer.send(200, "text/html", led_on3()); });
  webServer.on("/3off",[]() { webServer.send(200, "text/html", led_off3()); });
  webServer.on("/4on",[]() { webServer.send(200, "text/html", led_on4()); });
  webServer.on("/4off",[]() { webServer.send(200, "text/html", led_off4()); });
  webServer.on("/5on",[]() { webServer.send(200, "text/html", led_on5()); });
  webServer.on("/5off",[]() { webServer.send(200, "text/html", led_off5()); });
  webServer.on("/6on",[]() { webServer.send(200, "text/html", led_on6()); });
  webServer.on("/6off",[]() { webServer.send(200, "text/html", led_off6()); });
  webServer.on("/7on",[]() { webServer.send(200, "text/html", led_on7()); });
  webServer.on("/7off",[]() { webServer.send(200, "text/html", led_off7()); });
  webServer.on("/8on",[]() { webServer.send(200, "text/html", led_on8()); });
  webServer.on("/8off",[]() { webServer.send(200, "text/html", led_off8()); });

  webServer.onNotFound([]() {
    webServer.send(200, "text/html", responseHTML);
  });
  webServer.begin();
}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();
}
