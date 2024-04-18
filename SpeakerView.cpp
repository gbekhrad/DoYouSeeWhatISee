#include "SpeakerView.h"

SpeakerView::SpeakerView(){
    ; // Creating the speakerview object. 
}

string SpeakerView::processFile(string inputFile){
  // numRows and numColumns start off as 0. When the file is read, these variables are updated. 
  numRows = 0;
  numColumns = 0; 
  string output; // String to be returned with the output of the algorithm.

  ifstream file(inputFile); // Open file provided in cl arg
  if (!file.is_open()) { // Check if file is open
    throw runtime_error("File DNE."); // If it's not, throw error. 
  } else { // If file is open,
    string line; // Store in line 
    
    while(getline(file, line)){ // For each line in the file,
      numColumns = count(line.begin(), line.end(), ' ') + 1;  // Count the number of columns
      numRows++; // Count the number of rows
    }

    // Reset the file cursor to the beginning of the file
    file.clear(); 
    file.seekg(0);  // Set file cursor to the beginning
  
    // Creating a 2D array of the audience 
    audience = new double*[numRows];
    for (int i = 0; i < numRows; i++) { 
      audience[i] = new double[numColumns];
    }

    // now it is reset to the beginning, loop through the files again
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numColumns; j++) {
        file >> audience[i][j];
      }
    } 

    // Reset the file cursor to the beginning of the file
    file.clear();  
    file.seekg(0);  // Set file cursor to the beginning

    stackArray = new MonoStack<double>*[numColumns]; // Array of stacks 

    for (int i = numColumns - 1; i >= 0; --i){ // For each column
      stackArray[i] = new MonoStack<double>(numRows, 'd'); // Create a new Monotonically decreasing stack of size numRows
      for (int j = numRows - 1; j >= 0; --j){ 
        stackArray[i]->push(audience[j][i]); // Push the heights onto the stack
      }
    }

    // loop to print out all the values in the stacks
    for (int i = 0; i < numColumns; i++){
      string currHeights; // string to keep track of the heights that can see
      output += "In column " + to_string(i) + " there are " +
                to_string(stackArray[i]->getSize()) + " that can see. ";
      while(!(stackArray[i]->isEmpty())){
        // Truncates decimal to tenths place. Reference in README
        stringstream ss;
        ss << fixed << setprecision(1) << stackArray[i]->pop(); // Grab every value in the stack
        currHeights += ss.str() + ", "; // and print it. 
      }
      currHeights.erase(currHeights.size() - 2); // erase the last 2 chars which is just ", "
      output += "Their heights are: " + currHeights + " inches.\n";
    }
  }
  return output;
}

SpeakerView::~SpeakerView(){
  delete stackArray; // Clean up the 2D array of stacks. 
}