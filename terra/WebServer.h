// #ifndef WEBSERVER_H
// #define WEBSERVER_H

// #include <SPI.h>
// #include <WiFiNINA.h>
// #include <Vector.h>
// #include "WebSettings.h"

// #define MAX_ENDPOINTS 10

// struct EndpointMapping
// {
//     String endpoint;
//     String mimetype;
    
//     template<class FunctionT>
//     String GetPage(FunctionT func)
//     {
//         return func();
//     }
// };

// class WebServer
// {
// public:
//     WebServer();
//     void create(bool ownAP = false);
//     void createRedirectionPage(EndpointMapping mapping);
//     void listen();
//     void printWiFiStatus();
//     void printCurrentNet();

// private:
//     WiFiServer mServer;
//     uint8_t mStatus;

//     Vector<EndpointMapping> mRedirectionPages;
//     EndpointMapping mEndpointTable[MAX_ENDPOINTS];

//     void createOwnAP();
//     bool trySendResponsePage(const WiFiClient& client, String endpoint);
//     void sendPage(const WiFiClient& client, EndpointMapping page);
//     void sendNotFoundPage(const WiFiClient& client);
//     void setMimetype(const WiFiClient& client, String mimetype);
//     void setSuccessHeader(const WiFiClient& client);
//     void setNotFoundHeader(const WiFiClient& client);
//     void connectRegisteredWLAN();
//     void updateStatus();
//     void printMacAddress(byte mac[]);
// };

// #endif // WEBSERVER_H