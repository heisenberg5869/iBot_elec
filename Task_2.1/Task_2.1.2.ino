// Task 2.1.2: ESP32 Web Server to toggle LED via browser
#include <WiFi.h>
    #include <WebServer.h>

        const char* ssid = "Poco65";
        const char* password = "sarr2008";

        #define LED_PIN 2

        WebServer server(80);

        // HTML page served at root "/"
        const char* htmlPage = R"rawhtml(
        <!DOCTYPE html>
        <html>

        <head>
            <title>ESP32 LED Control</title>
            <meta name="viewport" content="width=device-width, initial-scale=1">
            <style>
                body {
                    font-family: Arial;
                    text-align: center;
                    margin-top: 50px;
                }

                button {
                    padding: 15px 30px;
                    font-size: 20px;
                    margin: 10px;
                    cursor: pointer;
                    border-radius: 8px;
                    border: none;
                }

                .on {
                    background-color: #4CAF50;
                    color: white;
                }

                .off {
                    background-color: #f44336;
                    color: white;
                }
            </style>
        </head>

        <body>
            <h1>ESP32 LED Control</h1>
            <a href="/on"><button class="on">Turn ON</button></a>
            <a href="/off"><button class="off">Turn OFF</button></a>
        </body>

        </html>
        )rawhtml";

        void handleRoot() {
        server.send(200, "text/html", htmlPage);
        }

        void handleOn() {
        digitalWrite(LED_PIN, HIGH);
        server.send(200, "text/html", htmlPage);
        Serial.println("LED ON");
        }

        void handleOff() {
        digitalWrite(LED_PIN, LOW);
        server.send(200, "text/html", htmlPage);
        Serial.println("LED OFF");
        }

        void handleNotFound() {
        server.send(404, "text/plain", "404: Not Found");
        }

        void setup() {
        Serial.begin(115200);
        pinMode(LED_PIN, OUTPUT);
        digitalWrite(LED_PIN, LOW);

        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, password);

        Serial.print("Connecting");
        while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        }

        Serial.println("\nConnected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());

        server.on("/", handleRoot);
        server.on("/on", handleOn);
        server.on("/off", handleOff);
        server.onNotFound(handleNotFound);

        server.begin();
        Serial.println("Web server started.");
        }

        void loop() {
        server.handleClient();
        }