#ifndef AED_FLIGHT_MENU_H
#define AED_FLIGHT_MENU_H


#include "Graph.h"
#include "Parser.h"
#include "Utils.h"
#include "Functions.h"
/**
 * This class is responsible for all display functions, interaction with the user and making requests to the database
 */
class Menu {
    Dataset dataset;
    Graph graph;
    Parser parser;
    Utils utils;
    Functions functions;
public:
    Menu(Dataset dataset,Graph graph,Functions functions) : functions(functions),graph(graph),dataset(dataset) { };
    void showMainMenu();
    void showListingFunctionsMenu();
    void showBestOption();

    void showOption1();
    void showOption2();
    void showOption3();
    void showOption4();
    void showOption5();
    void showOption6();
    void showOption7();
    void showOption8();
    void showOption9();
    void showOption10();

    void showListingOption(string option);

    vector<Airport *> inputAirports(string element);

    vector<Airline> getAirlines();

    vector<Airport> getAirport();
};


#endif //AED_FLIGHT_MENU_H
