// TRIE TRAVERSAL FOR SPELL CHECKING SYSTEM

#include<bits/stdc++.h>             // the common library for cpp
#include<iostream>                  // library for file handling
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

int found=0;                        // variable to denote if word is correct... found = 1 then word is correct

class node
{
    public:
        char info;                                // declaring a varible for info which holds the dta part
        string Word;
        class node* ptrs[256];
        node()
        {
            for(int i=0;i<256;i++)                 // as trie stores the characters at different nodes so we have initialised
                                                   // the pointer part of all nodes to be NULL
            {      
                ptrs[i]=NULL;
            }
            info=NULL;
            Word="";
        }
};

void insertword(string word,int pos,class node * root)    // function arguments: input word, position = 0, class node variable pointer
{
    if(word.length()==pos)
    {
        root->Word=word;
        return;
    }
    if( root-> ptrs[word[pos]]==NULL )
    {
        node *newnode;                              // declaring a new pointer to the class node
        newnode= new node;                          // creating a new node                     
        newnode->info=word[pos];                    // inserting the first character of the input word into the trie structure                       
        root->ptrs[word[pos]]=newnode;                      
        insertword(word,pos+1,root->ptrs[word[pos]]);
    }
    else
        insertword(word,pos+1,root->ptrs[word[pos]]);
}


void searchCorrectWord(string key,int pos, class node * root)           // function arguments: input word, position = 0, class node variable pointer
{
    if((key != root->Word) && (root->ptrs[key[pos]] != NULL))           // if the key variable word is not same as our input word   
        searchCorrectWord(key,pos+1,root->ptrs[key[pos]]);              // looking for suggestions for our word
    else if(key==root->Word)                                            // if same then the word is correct
    {                                           
        cout<<"\nThe spelling of the word "<<root->Word<<" is correct "<<endl;
        found=1;
    
    }
    else
        found=0;                         // meaning the word is Incorrect..look for suggestions
}

void printallWords(class node * root)     // function arguments: class node variable pointer
{
    for(int i=0;i<256;i++)
        if(root->ptrs[i]!=NULL)
        {
            printallWords(root->ptrs[i]);
        }
    if(root->Word != "")
        cout<<" -> "<<root->Word<<endl;                                 // prints all the suggested words
}

void suggestCorrectWord(string key,int pos, class node * root)          // function arguments: input word, position = 0, class node variable pointer
{
    if((key != root->Word) && (root->ptrs[key[pos]] != NULL))           // if the key variable word is not same as our input word 
    {         
            suggestCorrectWord(key,pos+1,root->ptrs[key[pos]]);                
    }
    else
    {
            printallWords(root);
    }
}

int main(){
    
    cout<<"________________________________________";
    cout<<"\n-----------------------------------------------------TRF FINAL TASK-----------------------------------------------------";

    ifstream in("file.txt");       // loads the dictionary file        
    string word,current="";
    node *root;                               
    root = new node;
    
    
    clock_t begin;
    clock_t end;
    
    begin = clock();
    
    
    while(in)                                         // reading the words from the file
    {
        in>>word;                         
        insertword(word,0,root);                      // passing the words to create a tree structure
    }
    in.close();                                       // close the file
    
    end = clock()-begin;
    
    cout<<"\n\nDictionary loaded in "<<(double)end/double(CLOCKS_PER_SEC)<<"secs!"<<endl;

    //printall(root);

    string s1;
    cout<<"\n\nWord to be searched : ";
    getline (cin,s1);                                    // get the user input line

    stringstream iss(s1);                               // convert to lowercase

    string s2;

    while(iss>>s2)
    {
         const string r=s2;
        //r = s2;
        searchCorrectWord(r,0,root);
        //cout<<r<<" ";
        if(!found)
        {                               
            cout<<endl<<"Incorrect word-" <<r<<", Possible suggestions :"<<endl;
            suggestCorrectWord(r,0,root);                                       
        }
    }


    cout<<"\n_________________________________________";
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx-THANK YOU-xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    

    return 0;
}