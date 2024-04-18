Name: Gabriella Bekhrad
ID: 2417841
Email: gbekhrad@chapman.edu
Class Section: CPSC 350-01
Date Due: 4/5/24

Brief: 

Imagine there is a speaker, and an audience with a fixed number of chairs arranged in an N x P rectangle
with row 0 being the closest to the speaker. The event planners decide to assign seats, but there are 
concerns that with assigned seating, some short audience members may not be able to see the speaker if 
people that are sitting in front of them (in their column of seats) are taller than them. 

To solve this problem, this program is provided a text file that consists of candidate seat assignments in 
the form of N lines, each with P entries, where each entry is the height of the person assigned to the seat 
at that location represented as a floating point number. For each column of seating, they would like to 
determine how many people have an unobstructed view of the speaker. 

Source Files: 
- MonoStack.h
- SpeakerView.h
- SpeakerView.cpp
- main.cpp

Instructions to compile and run:
g++ *.cpp
./a.out input.txt

Sources: 
https://stackoverflow.com/questions/45034343/passing-reference-of-the-current-object-in-a-class-member-function-in-c
https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/64beb1e31a5d38cdee24dfde 
https://www.reddit.com/r/cpp_questions/comments/lcezap/can_someone_explain_how_seekg_works_exactly/
https://cplusplus.com/forum/general/222965/ 
https://stackoverflow.com/questions/843154/fastest-way-to-find-the-number-of-lines-in-a-text-c 