// main

#include "catDatabase.h"

#include <vector>

#include <string>



using namespace std;



int main()

    {

    vector<int> maybes;

    vector<string> userPrefs;

    vector<results> cats;

    vector<vector<string> > database;

    catDatabase matchCat;

    // get user prefs from file

    // currently defaults to userPrefs.csv

    userPrefs = matchCat.readUserPrefs();

    // subset database based on definite preferences

    // database file currently defaults to database.csv

    database = matchCat.subsetDefinite(userPrefs);

    // get number of user pref "maybes" that are "true" for cat

    maybes = matchCat.getMaybeMatches(database,userPrefs);

    // prioritise cats by maybes

    cats = matchCat.prioritiseMaybe(database,maybes);

    // print results

    matchCat.printResults(cats);

    return 0;

    }
