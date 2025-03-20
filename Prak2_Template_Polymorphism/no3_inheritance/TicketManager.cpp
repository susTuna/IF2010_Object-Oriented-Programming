#include "TicketManager.hpp"

TicketManager::TicketManager(string eventName){
    this->eventName = eventName;
    this->vipCapacity = 5;
    this->regularCapacity = 10;
    this->ticketCount = 0;
    this->currentRegularTickets = 0;
    this->currentVIPTickets = 0;

}

TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity) : eventName(eventName), vipCapacity(vipCapacity), regularCapacity(regularCapacity), ticketCount(0), currentVIPTickets(0), currentRegularTickets(0)
{
    if (regularCapacity + vipCapacity > VENUE_CAPACITY)
    {
        cout << "The total capacity you construct is " << regularCapacity + vipCapacity << ", meanwhile the venue capacity is 15" << endl;
    }
}

TicketManager::~TicketManager(){
    for (int i = 0; i < VENUE_CAPACITY ; i ++){
        this->tickets[i] = nullptr;
    }
}

string TicketManager::getEventName() const{
    return this->eventName;
}

void TicketManager::buyTicket(const string &ownerName, bool isVIP){
    if (ticketCount >= VENUE_CAPACITY){
        cout << "Error: All tickets are sold out!" << endl;
        return;
    }

    if (isVIP) {
        if (this->vipCapacity == this->currentVIPTickets) {
        cout << "Error: No VIP tickets left!" << endl;
        return;
        }
        currentVIPTickets++;
        string tix = "V" + to_string(currentVIPTickets);
        tickets[ticketCount] = new VIPTicket(tix,ownerName);
        cout << "Success: " << ownerName << " bought a VIP ticket! Ticket ID: " << tix << endl;
    }
    else {
        if (this->regularCapacity == this->currentRegularTickets) {
        cout << "Error: No Regular tickets left!" << endl;
        return;
         }
        currentRegularTickets++;
        string tix = "R" + to_string(currentRegularTickets);
        tickets[ticketCount] = new RegularTicket(tix,ownerName);
        cout << "Success: " << ownerName << " bought a Regular ticket! Ticket ID: " << tix << endl;
    }
    ticketCount++;
}

void TicketManager::checkTicket(const string &ticketID) const{
    for (int i = 0; i < ticketCount ; i++){
        if (ticketID == tickets[i]->getTicketID()){
            tickets[i]->printTicket();
            return;
        }
    }
    cout << "Ticket ID is invalid!" << endl;
}

void TicketManager::listAudience() const{
    if (ticketCount == 0) {
        cout << "No audience yet!" << endl;
        return;
    }

    for (int i = 0 ; i < ticketCount ; i++){
        cout << i+1 << ". ";
        tickets[i]->printTicket();
    }
}

int TicketManager::calculateRevenue() const{
    return currentRegularTickets * 275 + currentVIPTickets * 500;
}



