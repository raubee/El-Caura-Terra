// #include "WebServer.h"

// static String extractEndpointFromLine(String line)
// {
//     String endpoint = "";

//     for (int i = 0; i < line.length(); ++i)
//     {
//         if (line[i] == '/' || endpoint.length() != 0)
//         {
//             if (line[i] == ' ')
//                 break;

//             endpoint += line[i];
//         }
//     }

//     return endpoint;
// }

// WebServer::WebServer() : mServer(SERVER_PORT), mRedirectionPages(mEndpointTable)
// {
//     createRedirectionPage(sIndexPage);
//     createRedirectionPage(sFullPage);
//     createRedirectionPage(sSensorPage);
//     createRedirectionPage(sClockPage);
//     createRedirectionPage(sHumidityPage);
//     createRedirectionPage(sLightPage);
// }

// void WebServer::create(bool ownAP)
// {
//     while (!Serial)
//     {
//         ; // wait for serial port to connect. Needed for native USB port only
//     }

//     if (WiFi.status() == WL_NO_MODULE)
//     {
//         Serial.println("Communication with WiFi module failed!");
//         // don't continue
//         while (true)
//             ;
//     }

//     String fv = WiFi.firmwareVersion();
//     if (fv < WIFI_FIRMWARE_LATEST_VERSION)
//     {
//         Serial.println("Please upgrade the firmware");
//     }

//     if (ownAP)
//     {
//         createOwnAP();
//     }
//     else
//     {
//         connectRegisteredWLAN();
//     }

//     Serial.println("Starting server...");

//     // start the web server
//     mServer.begin();

//     // you're connected now, so print out the status
//     printWiFiStatus();
//     printCurrentNet();
// }

// void WebServer::createOwnAP()
// {
//     Serial.println("Access Point Web Server");

//     // by default the local IP address of will be 192.168.4.1
//     // you can override it with the following:
//     // WiFi.config(IPAddress(10, 0, 0, 1));

//     // print the network name (SSID);
//     Serial.print("Creating access point named: ");
//     Serial.println(SERVER_AP_SSID);

//     // Create open network. Change this line if you want to create an WEP network:
//     mStatus = WiFi.beginAP(SERVER_AP_SSID, SERVER_AP_PWD);

//     if (mStatus != WL_AP_LISTENING)
//     {
//         Serial.println("Creating access point failed");
//         // don't continue
//         while (true)
//             ;
//     }

//     Serial.println("Access Point created");
// }

// void WebServer::connectRegisteredWLAN()
// {
//     Serial.println("WLAN Web Server");

//     // attempt to connect to Wifi network:
//     while (mStatus != WL_CONNECTED)
//     {
//         Serial.print("Attempting to connect to WPA SSID: ");
//         Serial.println(WLAN_SSID);
//         // Connect to WPA/WPA2 network:
//         mStatus = WiFi.begin(WLAN_SSID, WLAN_PWD);
//         // wait 2 seconds for connection:
//         delay(10000);
//     }

//     // you're connected now, so print out the data:
//     Serial.println("You're connected to the network");
// }

// void WebServer::listen()
// {
//     updateStatus();

//     WiFiClient client = mServer.available(); // listen for incoming clients

//     if (!client)
//         return;

//     String currentLine;
//     String endpoint;

//     while (client.connected())
//     {
//         // break if client is not available
//         if (!client.available())
//             break;

//         char c = client.read();
//         Serial.write(c);

//         if (c == '\n')
//         { // if the byte is a newline character

//             // if the current line is blank, you got two newline characters in a row.
//             // that's the end of the client HTTP request, so send a response:
//             if (currentLine.length() == 0)
//             {
//                 if (!trySendResponsePage(client, endpoint))
//                 {
//                     sendNotFoundPage(client);
//                 }

//                 client.println(); // add another end-of-line character to finish response.
//                 break;
//             }
//             else
//             {
//                 if (currentLine.startsWith("GET /"))
//                 {
//                     endpoint = extractEndpointFromLine(currentLine);
//                 }

//                 currentLine = "";
//             }
//         }
//         else if (c != '\r')
//         {                     // if you got anything else but a carriage return character,
//             currentLine += c; // add it to the end of the currentLine
//         }
//     }

//     client.stop();
// }

// void WebServer::updateStatus()
// {
//     // compare the previous status to the current status
//     if (mStatus != WiFi.status())
//     {
//         // it has changed update the variable
//         mStatus = WiFi.status();

//         if (mStatus == WL_AP_CONNECTED)
//         {
//             // a device has connected to the AP
//             Serial.println("Device connected to AP");
//         }
//         else
//         {
//             // a device has disconnected from the AP, and we are back in listening mode
//             Serial.println("Device disconnected from AP");
//         }
//     }
// }

// void WebServer::createRedirectionPage(EndpointMapping page)
// {
//     mRedirectionPages.push_back(page);
// }

// bool WebServer::trySendResponsePage(const WiFiClient &client, String endpoint)
// {
//     for (int i = 0; i < mRedirectionPages.size(); ++i)
//     {
//         if (endpoint == mRedirectionPages[i].endpoint)
//         {
//             sendPage(client, mRedirectionPages[i]);
//             return true;
//         }
//     }

//     return false;
// }

// void WebServer::sendPage(const WiFiClient &client, EndpointMapping page)
// {
//     setSuccessHeader(client);
//     setMimetype(client, page.mimetype);

//     WiFiClient &c = const_cast<WiFiClient &>(client);
//     c.println();
//     c.println(page.GetPage());
// }

// void WebServer::sendNotFoundPage(const WiFiClient &client)
// {
//     setNotFoundHeader(client);
//     setMimetype(client, "text/html");

//     WiFiClient &c = const_cast<WiFiClient &>(client);
//     c.println();
//     c.println(cHtml404);
// }

// void WebServer::setSuccessHeader(const WiFiClient &client)
// {
//     WiFiClient &c = const_cast<WiFiClient &>(client);
//     c.println("HTTP/1.1 200 OK");
// }

// void WebServer::setNotFoundHeader(const WiFiClient &client)
// {
//     WiFiClient &c = const_cast<WiFiClient &>(client);
//     c.println("HTTP/1.1 404 Not Found");
// }

// void WebServer::setMimetype(const WiFiClient &client, String mimetype)
// {
//     WiFiClient &c = const_cast<WiFiClient &>(client);
//     c.println("Content-type:" + mimetype);
// }

// void WebServer::printWiFiStatus()
// {
//     // print the SSID of the network you're attached to:
//     Serial.print("SSID: ");
//     Serial.println(WiFi.SSID());

//     // print your WiFi shield's IP address:
//     IPAddress ip = WiFi.localIP();
//     Serial.print("IP Address: ");
//     Serial.println(ip);

//     // print where to go in a browser:
//     Serial.print("To see this page in action, open a browser to http://");
//     Serial.println(ip);
// }

// void WebServer::printCurrentNet()
// {
//     // print the SSID of the network you're attached to:
//     Serial.print("SSID: ");
//     Serial.println(WiFi.SSID());

//     // print the MAC address of the router you're attached to:
//     byte bssid[6];
//     WiFi.BSSID(bssid);
//     Serial.print("BSSID: ");
//     printMacAddress(bssid);

//     // print the received signal strength:
//     long rssi = WiFi.RSSI();
//     Serial.print("signal strength (RSSI):");
//     Serial.println(rssi);

//     // print the encryption type:
//     byte encryption = WiFi.encryptionType();
//     Serial.print("Encryption Type:");
//     Serial.println(encryption, HEX);
//     Serial.println();
// }

// void WebServer::printMacAddress(byte mac[])
// {
//     for (int i = 5; i >= 0; i--)
//     {
//         if (mac[i] < 16)
//         {
//             Serial.print("0");
//         }

//         Serial.print(mac[i], HEX);

//         if (i > 0)
//         {
//             Serial.print(":");
//         }
//     }

//     Serial.println();
// }