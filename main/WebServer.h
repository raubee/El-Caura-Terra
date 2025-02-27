#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <SPI.h>
#include <WiFiNINA.h>
#include <Vector.h>
#include "WebSettings.h"
#include "html/index.h"
#include "html/404.h"

#define MAX_ENDPOINTS 10

typedef String (*FuncPage)();

struct EndpointMapping
{
    String endpoint;
    String mimetype;
    FuncPage function;

    String GetPage()
    {
        if (function == nullptr)
        {
            return cHtml404;
        }

        return function();
    }
};

static EndpointMapping sFullPage = {"/full", "application/json"};
static EndpointMapping sSensorPage = {"/sensors", "application/json"};
static EndpointMapping sClockPage = {"/clock", "application/json"};
static EndpointMapping sHumidityPage = {"/humidity_calendar", "application/json"};
static EndpointMapping sLightPage = {"/light_calendar", "application/json"};

class WebServer
{
public:
    WebServer();
    void create(bool ownAP = false);
    void createRedirectionPage(EndpointMapping mapping);
    void listen();
    void printWiFiStatus();
    void printCurrentNet();

private:
    WiFiServer mServer;
    uint8_t mStatus;

    Vector<EndpointMapping> mRedirectionPages;
    EndpointMapping mEndpointTable[MAX_ENDPOINTS];

    void createOwnAP();
    bool trySendResponsePage(const WiFiClient &client, String endpoint);
    void sendPage(const WiFiClient &client, EndpointMapping page);
    void sendNotFoundPage(const WiFiClient &client);
    void setMimetype(const WiFiClient &client, String mimetype);
    void setSuccessHeader(const WiFiClient &client);
    void setNotFoundHeader(const WiFiClient &client);
    void connectRegisteredWLAN();
    void updateStatus();
    void printMacAddress(byte mac[]);
};

#endif // WEBSERVER_H