#include <string>
extern "C" {
  #include "utils/rtsp-parser.h"
}

namespace vserver {

    class RTSPConnect {
    public:
        RTSPConnect(int socket);
        ~RTSPConnect();
        int readText();
        int handleData();
        int writeText();
    
    private:
        RTSP_MESSAGE request;
        RTSP_MESSAGE response;
        int socket;
        std::string input;
        std::string output;
    };

    class RTSPServer {
    public:
        static RTSPServer* getInstance();
        void setPortbase(int port);
        int MainLoop(void);
    private:
        RTSPServer();
        ~RTSPServer();
    
    private:
        static RTSPServer* instance;
        char hostname[1024];
        int port;
    };
}
