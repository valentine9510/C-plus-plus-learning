#ifndef CHAINPRINTER_H
#define CHAINPRINTER_H

#include <string>
#include "ChainPrinterDriver.h"
#include "Printer.h"
#include <vector>

/**
 * Fill out this class to implement the {@link Printer} interface.
 */
class ChainPrinter {
private:
    static const int numOfSolenoids = 8; //keep number of solenoids
    static const int distanceBtnSolenoids = 3; //3mm between each solenoid
    static const int distanceBtnHammers = 4; //4mm between each hammer

    ChainPrinterDriver* driver;

    std::vector<char> hammerArray = {'0','1','0','1','0','1','0','1'};
    int millimeterDisplacementFromOrigin; //Helps us keep track of where we are in the cycle. circular number, whenever it reaches 8mm, we reset to zero. 

    //methods
    /**
     * @brief Custom method to step
     * 
     * @param numberOfSteps Number of steps to take. Default is 1
     */
    void chainPrintStep(int numberOfSteps = 1);

   
    /**
     * @brief Handles all printing activities
     * 
     * @param line Line to print
     * @param unknownCharacterHandle Will you handle unknown characters
     */
    void chainPrinterUniversalPrint(const std::string& line, bool unknownCharacterHandle );
public:
    /**
     * Constructor for ChainPrinter.
     * 
     * @param driver A pointer to a ChainPrinterDriver object.
     */
    ChainPrinter(ChainPrinterDriver* driver);

    /**
     * Destructor for ChainPrinter.
     */
    ~ChainPrinter();

    /**
     * Prints a line.
     * 
     * @param line The string to be printed.
     */
    void println(const std::string& line);

    /**
     * Dotted print of a line.
     * 
     * @param line The string to be dotted printed.
     */
    void dprintln(const std::string& line);

    /**
     * Parallel print of a line.
     * 
     * @param line The string to be parallel printed.
     */
    void pprintln(const std::string& line);
};

#endif // CHAINPRINTER_H
