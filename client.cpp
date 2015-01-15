//
//  Sample client in C++
//  Connects REQ socket to tcp://localhost:5555
//
#include <zmq.hpp>
#include <string>
#include <iostream>

int main ()
{
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    std::cout << "Connecting to sample server…" << std::endl;
    socket.connect ("tcp://localhost:5555");

    //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        zmq::message_t request (6);
        memcpy ((void *) request.data (), "Check", 5);
        std::cout << "Sending check " << request_nbr << "…" << std::endl;
        socket.send (request);

        //  Get the reply.
        zmq::message_t reply;
        socket.recv (&reply);
        std::cout << "Received " << std::string((char*)reply.data(), reply.size()); << request_nbr << std::endl;
    }
    return 0;
}
