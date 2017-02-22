#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "anmol";
const char *password = "";
boolean led1 = false;
boolean led2 = false;

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
	server.send(200, "text/html", "<!DOCTYPE html><html><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><title>•Lets Play•</title></head><body style='height: 100vh;padding:0px;margin: 0px;text-align: center; background-color: lightgrey'><main style='height: 100%;padding:0px;margin: 0px;text-align: center;'><header ><h1 style='padding:0px;margin: 0px;text-align: center;background-color: grey;color: white;height: 50px;'>Click the buttons below to switch the state of the led</h1></header><ul style='margin-top: 100px;'><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on1' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: red; border-radius: 50px;'> LED1</a></li><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on2' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: red; border-radius: 50px'>LED 2</a></li></ul></main></body></html>");
}

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
  server.on("/on1", []()
  {
      if(led2)
      {
        server.send(200, "text/html", "<!DOCTYPE html><html><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><title>•Lets Play•</title></head><body style='height: 100vh;padding:0px;margin: 0px;text-align: center; background-color: lightgrey'><main style='height: 100%;padding:0px;margin: 0px;text-align: center;'><header ><h1 style='padding:0px;margin: 0px;text-align: center;background-color: grey;color: white;height: 50px;'>Click the buttons below to switch the state of the led</h1></header><ul style='margin-top: 100px;'><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/off1' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: green; border-radius: 50px;'> LED1</a></li><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/off2' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: green; border-radius: 50px'>LED 2</a></li></ul></main></body></html>");
      }

      else
      {
        server.send(200, "text/html", "<!DOCTYPE html><html><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><title>•Lets Play•</title></head><body style='height: 100vh;padding:0px;margin: 0px;text-align: center; background-color: lightgrey'><main style='height: 100%;padding:0px;margin: 0px;text-align: center;'><header ><h1 style='padding:0px;margin: 0px;text-align: center;background-color: grey;color: white;height: 50px;'>Click the buttons below to switch the state of the led</h1></header><ul style='margin-top: 100px;'><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/off1' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: green; border-radius: 50px;'> LED1</a></li><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on2' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: red; border-radius: 50px'>LED 2</a></li></ul></main></body></html>");
      }
      digitalWrite(4, HIGH);
      led1 = true;
      
  });
server.on("/on2", []()
  {
       if(led1)
       {
            server.send(200, "text/html", "<!DOCTYPE html><html><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><title>•Lets Play•</title></head><body style='height: 100vh;padding:0px;margin: 0px;text-align: center; background-color: lightgrey'><main style='height: 100%;padding:0px;margin: 0px;text-align: center;'><header ><h1 style='padding:0px;margin: 0px;text-align: center;background-color: grey;color: white;height: 50px;'>Click the buttons below to switch the state of the led</h1></header><ul style='margin-top: 100px;'><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/off1' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: green; border-radius: 50px;'> LED1</a></li><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/off2' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: green; border-radius: 50px'>LED 2</a></li></ul></main></body></html>");
       }
       else
       {           
          server.send(200, "text/html", "<!DOCTYPE html><html><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><title>•Lets Play•</title></head><body style='height: 100vh;padding:0px;margin: 0px;text-align: center; background-color: lightgrey'><main style='height: 100%;padding:0px;margin: 0px;text-align: center;'><header ><h1 style='padding:0px;margin: 0px;text-align: center;background-color: grey;color: white;height: 50px;'>Click the buttons below to switch the state of the led</h1></header><ul style='margin-top: 100px;'><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on1' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: red; border-radius: 50px;'> LED1</a></li><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/off2' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: green; border-radius: 50px'>LED 2</a></li></ul></main></body></html>");
       }
       
       digitalWrite(5, HIGH);
        led2 = true;
          
  });
  
  server.on("/off1", []()
  {
        if(led2)
        {          
                  server.send(200, "text/html", "<!DOCTYPE html><html><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><title>•Lets Play•</title></head><body style='height: 100vh;padding:0px;margin: 0px;text-align: center; background-color: lightgrey'><main style='height: 100%;padding:0px;margin: 0px;text-align: center;'><header ><h1 style='padding:0px;margin: 0px;text-align: center;background-color: grey;color: white;height: 50px;'>Click the buttons below to switch the state of the led</h1></header><ul style='margin-top: 100px;'><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on1' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: red; border-radius: 50px;'> LED1</a></li><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/off2' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: green; border-radius: 50px'>LED 2</a></li></ul></main></body></html>");
        }

        else
        {
          server.send(200, "text/html", "<!DOCTYPE html><html><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><title>•Lets Play•</title></head><body style='height: 100vh;padding:0px;margin: 0px;text-align: center; background-color: lightgrey'><main style='height: 100%;padding:0px;margin: 0px;text-align: center;'><header ><h1 style='padding:0px;margin: 0px;text-align: center;background-color: grey;color: white;height: 50px;'>Click the buttons below to switch the state of the led</h1></header><ul style='margin-top: 100px;'><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on1' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: red; border-radius: 50px;'> LED1</a></li><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on2' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: red; border-radius: 50px'>LED 2</a></li></ul></main></body></html>");
         }
        digitalWrite(4, LOW);
        led1 = false;
  });

  server.on("/off2", []()
  {
           if(led1)
           {       
                  server.send(200, "text/html", "<!DOCTYPE html><html><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><title>•Lets Play•</title></head><body style='height: 100vh;padding:0px;margin: 0px;text-align: center; background-color: lightgrey'><main style='height: 100%;padding:0px;margin: 0px;text-align: center;'><header ><h1 style='padding:0px;margin: 0px;text-align: center;background-color: grey;color: white;height: 50px;'>Click the buttons below to switch the state of the led</h1></header><ul style='margin-top: 100px;'><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on1' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: green; border-radius: 50px;'> LED1</a></li><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on2' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: red; border-radius: 50px'>LED 2</a></li></ul></main></body></html>");
           }

           else
           {
            server.send(200, "text/html", "<!DOCTYPE html><html><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><title>•Lets Play•</title></head><body style='height: 100vh;padding:0px;margin: 0px;text-align: center; background-color: lightgrey'><main style='height: 100%;padding:0px;margin: 0px;text-align: center;'><header ><h1 style='padding:0px;margin: 0px;text-align: center;background-color: grey;color: white;height: 50px;'>Click the buttons below to switch the state of the led</h1></header><ul style='margin-top: 100px;'><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on1' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: red; border-radius: 50px;'> LED1</a></li><li style='padding:0px;margin: 0px;text-align: center;display: inline;'><a href='http://192.168.4.1/on2' style='margin: 10px;text-align: center;font-size: 40px;padding: 10px;text-decoration: none;color: white;background-color: red; border-radius: 50px'>LED 2</a></li></ul></main></body></html>");
            }
          digitalWrite(5, LOW);
          led2 = false;
  
  });
  
 	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
