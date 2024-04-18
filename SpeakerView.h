#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.h"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm> // for counting columns, "count". view references
#include <iomanip> // for setprecision, view references
using namespace std; 

/**
 * Class SpeakerView
 * @brief class representing the view of the audience members of the speaker. 
*/
class SpeakerView {
    public: 
        /**
         * Constructor for the SpeakerView object.
        */
        SpeakerView();

        /**
         * processFile function
         * @brief function that uses a monotonically decreasing stack to determine the number of people 
         * in each column of seats that are able to see the speaker clearly, as well as the heights of those people.
         * @param inputFile string representation of an input file to be passed in, consisting of N lines
         * with each line consisting of P doubles (representing heights) separated by spaces
         * @return string output indicating who can see in which column, and the height of each person. 
        */
        string processFile(string inputFile);

        /**
         * Default destructor for the SpeakerView object.
        */
       ~SpeakerView();

    private:
        MonoStack<double>** stackArray; // 2D array of MonoStacks to be dynamically allocated based on the amount of rows and columns provided at runtime through the input file.
        double** audience; // 2D array of the numbers/heights, to be dynamically allocated.
        int numRows; // Integer value keeping track of the number of rows. 
        int numColumns; // Integer value keeping track of the number of columns.  
};

#endif