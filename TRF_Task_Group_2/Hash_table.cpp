#include <bits/stdc++.h>
using namespace std;

class Hash
{
    int BUCKET;             //No. of Buckets in Hash Table
    list<string> *table ;   //pointer to array of buckets

    public:
        Hash(int V);        //Constructor

        //inserts a key into Hashtable
        void insertitem(string s);

        //searches for a key in the Hashtable
        bool searchitem(string s);

        //Function to display the Hashtable
        void displayhash();

        //Function to display suggestions
        void displaysuggestions(int key,string str1);

        //Function to map values
	    int hashfunction(string s)
        {
            int sum=0;

            //converting word to lowercase
            transform(s.begin(), s.end(), s.begin(), ::tolower);

            //calculating sum of ASCII values
            for(int i=0;s[i]!='\0';i++)
                {
                    sum = sum + i;
                }
            sum = sum/BUCKET;
            return sum;
        }
};

Hash::Hash(int b)
{
    this->BUCKET=b;
    table = new list<string>[BUCKET];
}

void Hash::insertitem(string key)
{
    int index = hashfunction(key);
    table[index].push_back(key);
};

bool Hash::searchitem(string s)
{
    int index = hashfunction(s);
    for(auto j:table[index])
    {
        if(s==j)
            return true;
    }
}

void Hash::displaysuggestions(int key,string str1)
{
    cout<<"Suggestions: ";
    for(auto j:table[key])
    {
       if(j[0]==str1[0])
        {
           cout<<j<<",";
        }
    }
    cout<<endl;
}

void Hash::displayhash()
{
    for(int i=0;i<BUCKET;i++)
    {
        cout<<i;
        for(auto j:table[i])
        {
            cout<<"-->"<<j;
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"________________________________________________________________________________________________________________________";
    cout<<"\n-----------------------------------------------------TRF FINAL TASK-----------------------------------------------------";
    
    fflush(stdin);
    vector<string> SetofWords;

    //Reading words from file
    fstream file;
    string word, word2, filename, str;
    filename = "file.txt";

    // used to time the hashtable load
    clock_t beg;
	clock_t end;
    beg = clock() ;

    file.open(filename.c_str());

    //Breaking line into words
    while (file >> word)
    {
        //storing words into vector
        SetofWords.push_back(word);
    }
    file.close();
    end = clock()-beg; // end the timer

	cout<<"\n\nDictionary loaded in "<<
		(double)end / ((double)CLOCKS_PER_SEC)<<" secs!";



    //Creating the object
    Hash h(9);

    //Inserting items into Hash table
    for(int i=0;i<SetofWords.size();i++)
    {
        h.insertitem(SetofWords[i]);
    }

    //Taking input from user
    cout<<"\n\nEnter a string to check : ";
    //string str;
    getline(cin,str);       // Taking multiword string

    //converting input string to lowercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    stringstream iss(str);
    //string word2;

    //Breaking string into words
    while(iss >> word2)
    {
        const string temp = word2;

        //searching word by word
        if(h.searchitem(temp))
            {
                //cout<<"\nWord Found";
            }
        else
            {
                int index = h.hashfunction(temp);
                cout<<"\nWrong word: "<<temp<<endl;
                h.displaysuggestions(index,temp);
            }
    }

    cout<<"\n_________________________________________________________________________________________________________________________";
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx-THANK YOU-xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    
    return 0;
}
