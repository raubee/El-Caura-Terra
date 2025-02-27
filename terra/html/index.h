#ifndef HTML_INDEX
#define HTML_INDEX

const String cHtmlIndex =
    "<!DOCTYPE html>\n"
    "<html>\n"
    "<head><meta charset=\"utf-8\">\n"
    "<title>Index</title>\n"
    "</head>\n"
    "<body>\n"
    "<pre>Index page</pre>\n"
    "</body>\n"
    "</html>\n";

static EndpointMapping sIndexPage = {"/", "text/html"};

#endif // HTML_INDEX