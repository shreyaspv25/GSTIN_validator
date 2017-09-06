# GSTIN_validator
A linux shell based tool using 'zenity' - a GTK package for UI, and C++ to validate the GSTIN's present in a CSV file provided as input in a predefined format.

### No Installation Required ###
* Compile the source file gstin.cpp
    * g++ gstin.cpp -o gstin
*  Run the Shell script gstin.sh
*  The file input prompt (using zenity) will appear asking for CSV file input.
*  The output i.e the invalid GSTIN's will be displayed in a text box.


