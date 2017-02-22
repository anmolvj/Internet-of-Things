#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>


const char *ssid = "anmol"; /*change this to the name the hotspot however you desire*/
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
// change the first parameter in the pinmode function to the desired pin you want to use as a output
  pinMode(4, OUTPUT); /*Led1 is the one connected on this pin*/
  pinMode(5, OUTPUT); /*Led2 is the led connected on this pin*/
	
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
      digitalWrite(4, HIGH);/*This sets the LED 1(here one connected on pin 4) as HIGH*/
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
       
       digitalWrite(5, HIGH);/*This sets the LED 2(here one connected on pin 5) as HIGH*/
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
        digitalWrite(4, LOW);/*This sets the LED 1(here one connected on pin 4) as LOW*/
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
          digitalWrite(5, LOW);/*This sets the LED 2(here one connected on pin 5) as LOW */
          led2 = false;
  
  });
  
 	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
