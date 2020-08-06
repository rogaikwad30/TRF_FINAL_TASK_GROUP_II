#include<bits/stdc++.h>
#include<string.h>
using namespace std;

// Create a 2 dimmenssional array as per row alphabetical rule

string arr[26][3000]={""};

void add_correct_words(string temp)
{
    int row=0,col=0,flag=0,test=0;
   // cout<<"Word :  ( Currently enter lowercase )  ";
   // cin>>temp;
    row = int(temp[0])-97;
    // u need to keep record of column for each row also
    while(test==0)
    {
        if(arr[row][col]=="")
       {
            arr[row][col]=temp;
            test = 1;
       }
    else
       {
          col++;
       }
    }
   // cout<<"Wanna enter another word (1/0) : ";
   // cin>>flag;
   // if(flag)
    //add_correct_words();
    //else
    //return;

}



void print()
{
    int i=0,j=0;
    for(i=0;i<26;i++)
    {
        for(j=0;j<3000;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}


struct Node
{
    string data;
    Node* left, * right;
};

void array_2_BST();
//Node* insertLevelOrder(Node* root, int row_no, int total_colmms,int iter);
//Node* newNode(string data);
//void check_inOrder(Node* root,string word);
void check(string word,int row,int col);

int main()
{
    int choice;

    // creating a array of correct words by taking word to word input from dictionary

    fstream file;
    string word, filename;
    filename = "file.txt";
    clock_t beg; // used to time the array load
	clock_t end;
    beg = clock() ;
    file.open(filename.c_str());

    while (file >> word)
    {
        add_correct_words(word);
    }
    file.close();
    end = clock()-beg; // end the timer
	cout<<"\n\nDictionary loaded in "<<
    (double)end / ((double)CLOCKS_PER_SEC)<<" secs!";




    cout<<"Enter your choice\n0 : Add more correct keywords to Dictionary\n1 : To test a spelled word\n2 : To print entire dictionary available\n3 : To Exit from the code   :   ";
    cin>>choice;
    switch(choice)
    {
        //case 0:
        //add_correct_words();break;
        case 1:
        array_2_BST();break;
        case 2:
        print();break;
        case 3:
        exit;
    }
}


void array_2_BST()
{
    string word;
    int row=0,colm=3000;
    cout<<"Enter a keyword : ";
    cin>>word;

    row = int(word[0])-97;
    // Now u have all words starting with the letter same as input word
    // Take root of tree as letter and add all words to child

    //Node * root = insertLevelOrder(root,row,colm,0);
    //check_inOrder(root,word);
    check(word,row,colm);
}

/*
Node* newNode(string data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}


Node* insertLevelOrder(Node* root, int row_no, int total_colmms,int iter) // r : row obtained from array_2_BST   // c = 3 for now
{
    // Base case for recursion
    if (iter < total_colmms)
    {
        Node* temp = newNode(arr[row_no][iter]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(root->left,row_no,total_colmms,2*iter+1);

        // insert right child
        root->right = insertLevelOrder(root->right,row_no,total_colmms,2*iter+2);
    }
    return root;
}


void check_inOrder(Node* root,string word)
{
    int flag = 0;
    if (root != NULL)
    {
        inOrder(root->left);
        if (word==root->data)
        {
            flag = 1;
            cout << "Word is correct"<<endl;
            exit;
        }
        inOrder(root->right);
    }
    if(flag==0)
    {
        cout<<"Word is mispelled"<<endl;
    }
}
*/
void check(string word,int row,int col)
{
    int i=0,test=0;
    while(i<col)
    {
        if(arr[row][i]==word)
        {
            test = 1;
            cout<<"Correct word "<<endl;
            exit;
        }
        i++;
    }
    if(test==0)
        {
            cout<<"Mis-spelled"<<endl;
        }
}