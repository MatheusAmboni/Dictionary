#include "dictionary.hpp"

#define NDEBUG 0

int main() {
    vector< vector < string > > globalWordList;
    vector< string > dictNameList;

    for(;;)
    {
        if (NDEBUG) cout << "DICTIONARY MANIPULATOR HACK" << endl;
        if (NDEBUG) cout << "Select an option: " << endl;
        if (NDEBUG) cout << "1. Open Dictionary... " << endl;
        if (NDEBUG) cout << "2. Search Substrings..." << endl;
        if (NDEBUG) cout << "3. Remove Words Containing Substring.." << endl;
        if (NDEBUG) cout << "4. Show Statistics" << endl;
        if (NDEBUG) cout << "5. Exit" << endl;

        if (NDEBUG) cout << "Option: ";

        char ch;
        cin >> ch;

        if( ch == '1' )
        {
            if (NDEBUG) cout << "Enter a dictionary file: " << endl;
            string path;
            cin >> path;

            vector< string > wordlist;
            if(LoadDictionary(path, wordlist) == true)
            {
                globalWordList.push_back(wordlist);
                dictNameList.push_back(path);
            }
            else
            {
                if (NDEBUG) cout << "Error, file not found" << endl;
            continue;
            }
            
        }

        if( ch == '2' )
        {
            if (NDEBUG) cout << "Enter a substring to search: " << endl;
            string query;
            cin >> query;

            for(size_t i=0; i<globalWordList.size(); i++){
                vector < string > substringsList = SearchSubstrings(globalWordList[i], query);

                for(size_t j=0; j<substringsList.size(); j++){
                    cout << substringsList.at(j) << endl;
                }
            }
    

            continue;
        }

        if( ch == '3' )
        {
            if (NDEBUG) cout << "Enter a substring to remove all occurrences: " << endl;
            string query;
            cin >> query;

            for (size_t i = 0; i < globalWordList.size(); i++){
                for (size_t j = 0; j < globalWordList[i].size(); j++){
                    string wordTemp = globalWordList[i].at(j);
                    if (wordTemp.find(query) < wordTemp.length()){
                        globalWordList[i].erase(globalWordList[i].begin() + j);
                        j--;
                    }
                }
            }
            continue;
        }

        if( ch == '4' )
        {
            cout << "Statistics:" << endl;

            for(size_t i = 0; i < globalWordList.size(); i++)
            {
                cout << dictNameList.at(i) << " -> " << globalWordList.at(i).size() << " words" << endl;
            }
            continue;
        }
        if( ch == '5' )
        {
            break;
        }
    }
}