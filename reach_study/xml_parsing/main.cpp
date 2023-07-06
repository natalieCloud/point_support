#include "xml_parser.hpp"

/**
 * Used in manual testing, the actual func written above does the brunt of it 
 * (and should be able to be called elsewhere)
*/
int main(int argc, char **argv) { 

    reachXML::xmlParser::parseXML(argv[1]);

    return 0;
}