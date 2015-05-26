//
//  Sample client in C++
//  Connects PUSH socket to tcp://localhost:5555
//
#include <zmq.hpp>
#include <string>
#include <iostream>

int main ()
{
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_PUSH);

    std::cout << "Connecting to sample server…" << std::endl;
    socket.connect ("tcp://localhost:5555");

    //  Send 10 messages
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        zmq::message_t request (6);
        memcpy ((void *) request.data (), "Check", 5);
        std::cout << "Sending check " << request_nbr << "…" << std::endl;
        socket.send (request);
    }
    return 0;
}

