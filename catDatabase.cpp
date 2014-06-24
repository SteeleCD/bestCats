// define functions within MyClass class

#include "catDatabase.h"



// include dependencies

#include <string>

#include <iostream>

#include <fstream>

#include <vector>

#include <algorithm>



using namespace std;



// read in the user preferences for a cat

vector<string> catDatabase::readUserPrefs()

    {

    // declare variables

    vector<string> userPrefs;

    vector<string>::iterator itStr; 

    string fileName = "userPrefs.txt";

    string tmpstring1, tmpstring2, tmpstring3, tmpstring4, tmpstring5, tmpstring6, tmpstring7, tmpstring8, tmpstring9;

    ifstream myfile;

    // Ask for filename

    //cout << "Please enter filename:" << endl;

    // get file name from user

    //cin >> fileName;

    // convert filename to c_str, then open

    myfile.open(fileName.c_str());

    // open file

    //myfile.open(fileName);

    // get data from file

    if(myfile.is_open())

        {

        // get current line into temporary strings

        while(myfile >> tmpstring1 >> tmpstring2 >> tmpstring3 >> tmpstring4 >> tmpstring5 >> tmpstring6 >> tmpstring7 >> tmpstring8 >> tmpstring9)

            {

            // clear previos vector (rownames in this case)

	        userPrefs.clear();

            // add tmpstring to vector of strings

            userPrefs.push_back(tmpstring1);

    	    userPrefs.push_back(tmpstring2);

    	    userPrefs.push_back(tmpstring3);

    	    userPrefs.push_back(tmpstring4);

    	    userPrefs.push_back(tmpstring5);

    	    userPrefs.push_back(tmpstring6);

    	    userPrefs.push_back(tmpstring7);

           	userPrefs.push_back(tmpstring8);

        	userPrefs.push_back(tmpstring9);

            }

        }

	else cout << "Could not open user prefs file";

    // close file

    myfile.close();

    return(userPrefs);

    }





// get a vector of all cats in database that match all the "yes" criteria of the user

vector<vector<string> > catDatabase::subsetDefinite(vector<string> userPrefs)

    {

    // declare variables 

    vector<string> tmpVec;

    vector<string>::iterator itStr1, itStr2;

    vector<vector<string> > outVec;

    string fileName = "database.txt";

    string tmpstring1, tmpstring2, tmpstring3, tmpstring4, tmpstring5, tmpstring6, tmpstring7, tmpstring8, tmpstring9, tmpstring10;

    ifstream myfile;

    bool flag = true, quitflag = false;

    // convert filename to c_str, then open

    myfile.open(fileName.c_str());

    // get data from file

    if(myfile.is_open())

        {

        // get current line into temporary strings

        while(myfile >> tmpstring1 >> tmpstring2 >> tmpstring3 >> tmpstring4 >> tmpstring5 >> tmpstring6 >> tmpstring7 >> tmpstring8 >> tmpstring9 >> tmpstring10)

            {

            // clear previos vector (rownames in this case)

	        tmpVec.clear();

            // add tmpstring to vector of strings

            tmpVec.push_back(tmpstring1);

    	    tmpVec.push_back(tmpstring2);

    	    tmpVec.push_back(tmpstring3);

    	    tmpVec.push_back(tmpstring4);

    	    tmpVec.push_back(tmpstring5);

    	    tmpVec.push_back(tmpstring6);

    	    tmpVec.push_back(tmpstring7);

           	tmpVec.push_back(tmpstring8);

        	tmpVec.push_back(tmpstring9);

        	tmpVec.push_back(tmpstring10);

        	// check if all 'yes' values from userPrefs are 'true' for current database entry

        	for (itStr1=userPrefs.begin(),itStr2=tmpVec.begin()+1; itStr1!=userPrefs.end(),itStr2!=tmpVec.end(); itStr1++, itStr2++)

                {

                if(*itStr1=="yes")

                    {

                    if(*itStr2=="true")

                        {

                        flag = true;

                        }

                    else {

                        // do not add this vector to output and tell outer loop to abondon this vector

                        flag = false;

                        quitflag = true;

                        }

                    }

                // skip to next element of vector if userPref is not "yes"    

                else continue;

                if(quitflag==true)

                    {

                    quitflag = false;

                    break;

                    }

                }

            // add tmpVec to outVec only if all "yes" from userPrefs are "true" in database entry

            if(flag==true) outVec.push_back(tmpVec);

            }

        }

	else cout << "Could not open user prefs file";

    // close file

    myfile.close();

    // return out vector

    return(outVec);

    }





// order the eligble cats by the number of "maybe" user preferences that are satisfied

// (more maybes are better)

vector<int> catDatabase::getMaybeMatches(vector<vector<string> > database, vector<string> userPrefs)

    {

    int tmpCount;

    vector<int> out;

    vector<vector<string> >::iterator itVec;

    vector<string> tmpVec;

    vector<string>::iterator itStr1, itStr2;

    // count number of matching maybes for every entry in database

    for(int i=0;  i<database.size(); i++) 

        {

        if(i==database.size()) break;

        tmpCount = 0;

        for(int j=0; j<userPrefs.size(); j++)

            {

            if(database[i][j+1]=="true"&&userPrefs[j]=="maybe") tmpCount++;



            }

        out.push_back(tmpCount);

        }

    return(out);

    }



struct sortByMaybes

    {

    bool operator()(results const  &a, results const &b)

        {

        return(a.maybes>b.maybes);

        }

    };



// order the eligble cats by the number of "maybe" user preferences that are satisfied

// (more maybes are better)

vector<results> catDatabase::prioritiseMaybe(vector<vector<string> > database, vector<int> maybes)

    {

    results tmpRes;

    vector<results> out;

    // convert catID and maybes into a data structure

    for(int i=0; i<maybes.size(); i++)

        {

        tmpRes.id = database[i][0];

        tmpRes.maybes = maybes[i];

        out.push_back(tmpRes);

        }

    // sort results vector by the number of matched maybes

    sort(out.begin(), out.end(), sortByMaybes());

    return(out);

    }





// print out the sorted results

void catDatabase::printResults(vector<results> output)

    {

    cout << "catID \t matchedMaybes" << endl;

    for(int i=0; i<output.size(); i++)

        {

        cout << output[i].id << " \t " << output[i].maybes << endl;

        } 

    // pause

    cout << "Paused, press ENTER to continue." << endl;

    cin.ignore();

    }











































    
