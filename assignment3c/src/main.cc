#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define FILE "Data.CS.SFSU.txt"

using namespace std;

/* 
    2D vector declared as globally, you could declare this in main
    and pass a reference to parse, then pass another reference to 
    search vector only to have to return it back to main for the out out
    put. I decided to make it global for lack of time...
*/
vector<vector<string>> v(20, vector<string>(20));

/* help function */
void help(void)
{
    cout << "PARAMETER HOW-TO: " << endl;
    cout << "1. A Search Key" << endl;
    /*
    cout << "2. An optional 'grammar' word i.e Noun, Verb..." << endl;
    cout << "3. An optional 'distinct' keyword" << endl;
    cout << "4. An optional 'reverse' keyword" << endl;
    */
    cout << endl;
}

/* introduction function */
void introduction(void)
{
    cout << endl;
    cout << endl;
    cout << "====== Dictionary 340 C++ ======" << endl;
    cout << "------ Keywords: " << v.size() << endl;
    cout << "------ Definitions: " << v.size() << endl;
    cout << endl;
    help();
}

/* search the vector for the term */
void search_vector(string phrase)
{
    vector<vector<string>>::const_iterator row;

    for (row = v.begin(); row != v.end(); row++)
    {
        if (find(row->begin(), row->end(), phrase) != row->end())
        {
            cout << endl;
            cout << "Term: [" << phrase << "] was found at location => " << row - v.begin() << endl;
            int r = (row - v.begin());
            cout << "Speech: " << v[r][1] << endl;
            cout << "Meaning: " << v[r][2] << endl;
            cout << endl;
        }
    }
}

void parse(void)
{
    /* Variables for Definiton, Keyword and Search*/
    string d, k, s, input;

    /* Open output file stream */
    fstream file(FILE, ios::in);

    /* Variables needed for assigning values to the vector */
    int a = 0, b = 0, c = 0, e = 0;

    cout << "Words to search for: " << endl;

    if (file.is_open())
    {
        while (getline(file, input, '\n'))
        {
            getline(file, k, '|');
            getline(file, s, '-');
            getline(file, d, '.');
            for (a = 0; a < 1; ++a)
            {
                /* First Column of Data.CS.SFSU.txt */
                v[e][c] = k;
                cout << v[e][c] << " ";
                for (int b = 1; b <= 2; b++)
                {

                    /* Second Column of Data.CS.SFSU.txt */
                    v[e][b] = s;
                    /* Output Speech by uncommenting the line below */
                    /* cout << v[e][b] << endl; */
                    /* "b" is incremented so that it can add the 'definition' to the vector.  */
                    b += 1;
                    /* Third Colum of Data.CS.SFSU.txt */
                    v[e][b] = d;
                    /* output the Definition by uncommenting the line below */
                    //cout << v[e][b] << endl;
                }
                e++;
            }
            c++;
        }
    }
}

int main(void)
{
    int i = 0;
    string search_term;

    parse();
    introduction();

    do
    {
        cout << "Search[" << i << "]: ";
        cin >> search_term;

        if (search_term.compare("!help") == 0)
            help();

        search_vector(search_term);
        i += 1;
    } while (i < v.size());

    return 0;
}