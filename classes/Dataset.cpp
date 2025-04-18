#include "Dataset.h"
#include "Flight.h"
#include "Utils.h"
#include <cmath>


Graph Dataset::getNetwork() const {
    return network;
}

Dataset::Dataset() {}

Dataset::Dataset(list<vector<string>> rawFlights, list<vector<string>> rawAirports, list<vector<string>> rawAirlines){
    loadAirports(rawAirports);
    loadAirlines(rawAirlines);
    loadFlights(rawFlights);
}

/**
 * Populates the graph nodes (airports) and also maps the (city, country) pair to all airports in it
 * @param rawAirports vector with all airports
 */
void Dataset::loadAirports(list<vector<string>> rawAirports) {
    for(vector<string> airports : rawAirports){
        Airport *airport = new Airport(airports[0], airports[1], airports[2], airports[3], Coordinate(stof(airports[4]), stof(airports[5])));
        this->network.addAirport(airport);
        cityAirports[make_pair(airports[2],airports[3])].push_back(airport);
    }
}
/**
 * Populates the graph edges (flights)
 * @param rawFlights vector with all flights
 */
void Dataset::loadFlights(list<vector<string>> rawFlights) {
    for(vector<string> flight : rawFlights){
        Airport* srcAirport = network.findAirport(Airport(flight[0]));
        Airport* destAirport = network.findAirport(Airport(flight[1]));
        srcAirport->addFlight(new Flight(destAirport, this->airlines[flight[2]], Utils::computeDistance(srcAirport->getCoordinates(), destAirport->getCoordinates())));
    }
}
/**
 * Populates the airlines hashmap
 * @param rawAirlines vector with all airlines
 */
void Dataset::loadAirlines(list<vector<string>> rawAirlines) {
    for(vector<string> airline : rawAirlines){
        this->airlines[airline[0]] = Airline(airline[0], airline[1], airline[2], airline[3]);
    }
}

hashCityAirport Dataset::getCityAirports() const {
    return this->cityAirports;
}

