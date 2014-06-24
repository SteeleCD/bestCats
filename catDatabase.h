//==================================

// define class functions



//================================

// include guard

#ifndef __MYCLASS_h_INCLUDED__  // if myclass.h has not been included

#define __MYCLASS_H_INCLUDED__  // #define this so the compiler knows it has been included



//================================

// forward declared dependencies



//=================================

// included dependencies

#include <vector>

#include <string>





struct results 

    {

    std::string id;

    int maybes;

    } ;



class catDatabase

    {

    public:

        std::vector<std::string> readUserPrefs();

        std::vector<std::vector<std::string> > subsetDefinite(std::vector<std::string> userPrefs);

        std::vector<int> getMaybeMatches(std::vector<std::vector<std::string> > database, std::vector<std::string> userPrefs);

        bool sortFunction(results a, results b);

        std::vector<results> prioritiseMaybe(std::vector<std::vector<std::string> > database, std::vector<int> maybes);

        void printResults(std::vector<results> output);

    };



#endif  // __MYCLASS_H_INCLUDED__

