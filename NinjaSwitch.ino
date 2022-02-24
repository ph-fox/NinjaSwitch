#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

const byte DNS_PORT = 53;
IPAddress apIP(193, 168, 0, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);

const char* AP_name="NINJA";
int led_1 = 16; //D0 or GPIO16
int led_2 = 5; //D1 or GPIO5
int led_3 = 4; //D2 or GPIO4
int led_4 = 14; //D5 or GPIO14
int led_5 = 12; //D6 or GPIO12
int led_6 = 13; //D7 or GPIO13

String responseHTML = ""
  "<!DOCTYPE html><html><head>"
  "<meta charset='utf-8'>"
  "<meta name='viewport' content='width=device-width, initial-scale=1'>"
  "<title>Ninja</title></head><body>"
  "<center><br><br><br>"
  "<h2>Ninja Switch</h2>"
  "<a class='grn' href=/bon>Built in Turn On</a>"
  "<a class='red' href=/boff>Built in Turn Off</a>"
  "<a class='grn' href=/1on>1 Turn On</a>"
  "<a class='red' href=/1off>1 Turn Off</a>"
  "<a class='grn' href=/2on>2 Turn On</a>"
  "<a class='red' href=/2off>2 Turn Off</a>"
  "<a class='grn' href=/3on>3 Turn On</a>"
  "<a class='red' href=/3off>3 Turn Off</a>"
  "<a class='grn' href=/4on>4 Turn On</a>"
  "<a class='red' href=/4off>4 Turn Off</a>"
  "<a class='grn' href=/5on>5 Turn On</a>"
  "<a class='red' href=/5off>5 Turn Off</a>"
  "<a class='grn' href=/6on>6 Turn On</a>"
  "<a class='red' href=/6off>6 Turn Off</a>"
  "</center>"
  "</body>"
  "<style>body{user-select: none;background-color: #303030;margin: 0;height: 100vh;}center{background-color: #151515;height: 100%;}.grn{background-color: green;}.red{background-color: maroon;}h2{color: cyan;font-family: sans-serif;margin: 0;}a{user-select: none;color: cyan;font-family: sans-serif;text-decoration: none;display: block;padding: 10px;margin: 5px;width: 20%;border-radius: 10px;border: 1px solid cyan;}a:active{background-color: rgb(0,0,0, 0.1);}@media (max-width: 900px){a{width: 60%;}}</style>"
  "</html>";

String led_onBuilt(){
  digitalWrite(LED_BUILTIN, LOW);
  return responseHTML;
}

String led_offBuilt(){
  digitalWrite(LED_BUILTIN, HIGH); 
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

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(AP_name);

  // if DNSServer is started with "*" for domain name, it will reply with
  // provided IP to all DNS request
  dnsServer.start(DNS_PORT, "*", apIP);
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
  webServer.on("/bon",[]() { webServer.send(200, "text/html", led_onBuilt()); });
  webServer.on("/boff",[]() { webServer.send(200, "text/html", led_offBuilt()); });
  webServer.onNotFound([]() {
    webServer.send(200, "text/html", responseHTML);
  });
  webServer.begin();
}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();
}
