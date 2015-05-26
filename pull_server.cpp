//
//  Sample server in C++
//  Binds PULL socket to tcp://*:5555
//

#include <zmq.hpp>
#include <string>
#include <iostream>

int main () {
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_PULL);
    socket.bind ("tcp://*:5555");

    while (true) {
        zmq::message_t request;

        //  Wait for next request from client
        socket.recv (&request);
        std::cout << "Received " << std::string((char*)request.data(), request.size()) << std::endl;
    }
    return 0;
}
