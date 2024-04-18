/**
 * main.cpp file:  
 * consists only of a main method that takes the input file name as a command line argument, 
 * and then uses the SpeakerView class to compute the output.
*/

#include "SpeakerView.h"

int main(int argc, char **argv){
    try{
        SpeakerView *speakerObj = new SpeakerView(); // Create a new speakerview object.
        cout << speakerObj->processFile(argv[1]); // Process the file with argv. 
    } catch(runtime_error &excpt){ // store it in reference 
        cout << excpt.what() << endl; // File DNE. 
    }

    return 0; // return 0 means successful
}