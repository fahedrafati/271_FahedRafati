//
//  main.cpp
//  FINAL PROJECT - CONTAGION (OPTION 2)
//
//  Created by Fahed Rafati & Mary Henry on 5/1/16.
//  Copyright © 2016 Fahed. All rights reserved.
//

// Required includes
#include <iostream>
#include <fstream>
#include <vector>

// Using the standard namespace
using namespace std;

bool isSearchFailed = false;

class myTreeNode
{
public:
    char Data;
    myTreeNode *childA = NULL;   //A's always go in child1
    myTreeNode *childT = NULL;   //T's always go in child2
    myTreeNode *childC = NULL;   //c's always go in child3
    myTreeNode *childG = NULL;   //G's always go in child4
};

class myTree
{
private:
    myTreeNode *Head;
public:
    myTree()
    {
        Head = new myTreeNode;
        Head->Data = '-';
    }
    bool addWord(string word);
    bool searchWord(string word, int errorCount, myTreeNode *startingPoint);
    myTreeNode *GetHead();
};

// Adding a new word
bool myTree::addWord(string word)
{
    myTreeNode *current = Head;
    for (int i = 0; i < word.length(); i++) // iterate through the word
    {
        if (word[i] == 'a')
        {
            if (current->childA == NULL)
            {
                myTreeNode *newNode = new myTreeNode(); // creating a new node
                newNode->Data = 'a'; // checking for a
                //cout << "new " << current->Data << " to a" << endl;
                current->childA = newNode;
                current = current->childA;
            }
            else {
                //cout << "old " << current->Data << " to a" << endl;
                current = current->childA;
            }
        }
        else if (word[i] == 'c')
        {
            
            if (current->childC == NULL)
            {
                myTreeNode *newNode = new myTreeNode(); // creating a new node
                newNode->Data = 'c'; // checking for c
                //cout << "new " << current->Data << " to c" << endl;
                current->childC = newNode;
                current = current->childC;
            }
            else
            {
                //cout << "old " << current->Data << " to c" << endl;
                current = current->childC;
            }
        }
        else if (word[i] == 't')
        {
            if (current->childT == NULL)
            {
                myTreeNode *newNode = new myTreeNode(); // creating a new node
                newNode->Data = 't'; // checking for t
                //cout << "new " << current->Data << " to t" << endl;
                current->childT = newNode;
                current = current->childT;
            }
            else
            {
                //cout << "old " << current->Data << " to t" << endl;
                current = current->childT;
            }
        }
        else if (word[i] == 'g') // the last possibility
        {
            if (current->childG == NULL)
            {
                myTreeNode *newNode = new myTreeNode(); // creating a new node
                newNode->Data = 'g'; // checking for t
                //cout << "new " << current->Data << " to g" << endl;
                current->childG = newNode;
                current = current->childG;
            }
            else
            {
                //cout << "old " << current->Data << " to g" << endl;
                current = current->childG;
            }
        }
    }
    return 0;
}


// This is used to search for the word
bool myTree::searchWord(string word, int errorCount, myTreeNode *startingPoint) // accounting for errors
{
    cout << word << endl;
    if (errorCount <= 3) // Only if the errors exceed 3.
    {
        myTreeNode *current = startingPoint;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == 'a')
            {
                if (current->childA == NULL)
                {
                    cout << "error at a (" << i << "), searching from c, t, g, starting with string " << word.substr(i + 1,word.length()-1) << "  Error Count: " << errorCount + 1 << endl;
                    if (current ->childC != NULL) searchWord('c' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    if (current ->childT != NULL) searchWord('t' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    if (current ->childG != NULL) searchWord('g' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    break;
                    //return 0;
                }
                
                else
                {
                    current = current->childA;//shift to the child for next iteration
                }
                
            }
            else if (word[i] == 'c')
            {
                if (current->childC == NULL)
                {
                    cout << "error at c (" << i << "), searching from a, t, g, starting with string " << word.substr(i + 1,word.length()-1) << "   Error Count: " << errorCount + 1 << endl;
                    if (current ->childA != NULL) searchWord('a' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    if (current ->childT != NULL) searchWord('t' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    if (current ->childG != NULL) searchWord('g' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    
                    break;
                    //return 0;
                }
                else
                {
                    current = current->childC;//shift to the child for next iteration
                }
            }
            else if (word[i] == 't')
            {
                if (current->childT == NULL)
                {
                    cout << "error at t (" << i << "), searching from c, a, g, starting with string " << word.substr(i + 1,word.length()-1) << "   Error Count: " << errorCount + 1 << endl;
                    if (current ->childC != NULL) searchWord('c' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    if (current ->childA != NULL) searchWord('a' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    if (current ->childG != NULL) searchWord('g' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    
                    break;
                    //return 0;
                }
                else
                {
                    current = current->childT;//shift to the child for next iteration
                }
            }
            else if (word[i] == 'g')
            {
                if (current->childG == NULL)
                {
                    cout << "error at g (" << i << "), searching from c, a, t, starting with string " << word.substr(i + 1,word.length()-1) << "   Error Count: " << errorCount + 1 << endl;
                    if (current ->childC != NULL) searchWord('c' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    if (current ->childA != NULL) searchWord('a' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    if (current ->childT != NULL) searchWord('t' + word.substr(i + 1,word.length()-1),errorCount+1, current);//branches into 3 different searches with each alternative letter
                    
                    break;
                    //return 0;
                }
                else {current = current->childG;}//shift to the child for next iteration
            }
        }
        //completed search successfully
        return 1;
    }
    //could not complete search
    isSearchFailed = true;
    return 0;
}

myTreeNode* myTree::GetHead()
{
    return Head;
}

/*******************************************************************************
 This function takes the genome file's name
 that it will read in. It will then read all of the overlapping
 words of size 30 that are present in the file.
 Each word it reads will then be stored in a vector.
 The vector is passed to this function as a parameter -- by reference.
 Doing so will allow the calling function has access to the vector of words.
 *******************************************************************************/
bool get_words_from_the_file(char * my_file_name, vector<string> &vector_of_words)
{
    int i, j;
    int len = 0;
    ifstream in;
    in.open(my_file_name); // Open the file
    if (!in.is_open())
    {
        cout << "I could not find " << my_file_name << endl;
        cout << "Check the location.\n";
        return false;
    }
    
    char * my_word = new char[31]; // Looking at words of size 30.
    while (in.peek() != EOF)
        // getting the length of the sequence
    {
        in >> my_word[0];
        len++;
    }
    
    // Cleaning up!
    in.clear();
    in.close();
    in.open(my_file_name);             //have to close and reopen file to reset filestream to beginning of file
    
    for (i = 0; i<30; i++)
    {
        in >> my_word[i];
        if (my_word[i]<97) my_word[i] += 32;     //makes it lowercase
    }
    my_word[30] = '\0';
    vector_of_words.push_back(my_word);
    
    for (i = 1; i<(len - 30 - 1); i++)   //read until the end of the file
    {
        //shift
        for (j = 0; j<29; j++) my_word[j] = my_word[j + 1];
        in >> my_word[29];
        if (my_word[29]<97) my_word[29] += 32;     //makes it lowercase
        my_word[30] = '\0';
        //cout << i << "\t" << my_word << endl; cout.flush();
        vector_of_words.push_back(my_word);
    }
    
    // Cleaning up!
    in.clear();
    in.close();
    
    return true;
}

/*******************************************************************************
 This function takes the reads file name to read and reads each individual word
 in the file and stores each word in a vector.
 The vector is passed to this function as a parameter -- by reference such
 that the calling function has access to the vector of words.
 *******************************************************************************/
bool get_the_reads_from_file(char * my_file_name, vector<string> &reads)
{
    int i;
    ifstream in;
    in.open(my_file_name); // open the file
    if (!in.is_open())
    {
        cout << "The read file " << my_file_name << " could not be opened.\nCheck the location.\n";
        return false;
    }
    
    char * word = new char[60];   // looking at words of size 30, so must be bigger
    
    while (in.peek() != EOF) // checking to see it's not the end of the file
    {
        in.getline(word, 60, '\n');
        for (i = 0; i<30; i++)
        {
            if (word[i]<97) word[i] += 32; // makes everything lowercase
        }
        reads.push_back(word); // push back onto the stack
        //cout << "\t" << word << endl; cout.flush();
    }
    
    // Cleaning up!
    in.clear();
    in.close();
    delete[] word;
    return true;
}

/*******************************************************************************
 This function writes out the vector of words to the screen. Written here to help
 you with debugging.
 *******************************************************************************/
bool write_out_the_vector_to_screen(vector<string> my_vector)
{
    int i;
    for (i = 0; i<my_vector.size(); i++)
        cout << my_vector[i] << endl; // this gets printed to the console
    return true;
}

/*******************************************************************************
 This function writes out the vector of words to file.
 *******************************************************************************/
bool write_out_the_vector_to_file(vector<string> my_vector, char * my_file_name)
{
    ofstream out;
    out.open(my_file_name); // open the file
    int i;
    for (i = 0; i<my_vector.size(); i++)
        out << my_vector[i] << endl; // putting the data into the output file
    
    // Cleaning up!
    out.clear();
    out.close();
    return true;
}


int main()
{
    
    int i;
    myTree geneTree; // Create a tree
    ofstream w;
    w.open("myResults.txt"); // Open myResults to print out in it
    
    vector<string> words_in_genome; // words in the genome
    char * genome_file_name = "genome.txt";          //make certain to place this file in the correct folder. Do not change path
    if (!get_words_from_the_file(genome_file_name, words_in_genome))
        return 1; // if not found, return a 1 to avoid crashing
    
    // 1. Create a tree based on myTreeNode --> transforming the vector of words into the tree
    // 2. Read in file reads using function get_the_reads_from_file
    vector<string> reads_to_be_tested; // The rest of the reads that need to be tested
    char * reads_file_name = "6.reads.2.txt";                 //make certain to place this file in the correct folder. Do not change path
    if (!get_the_reads_from_file(reads_file_name, reads_to_be_tested))
        return 1;
    
    for (i = 0; i < words_in_genome.size(); i++)
    {
        geneTree.addWord(words_in_genome[i]); // add the words into the vector
    }
    
    for (i = 0; i < reads_to_be_tested.size(); i++) // iterating through the loop
    {
        isSearchFailed = false;
        geneTree.searchWord(reads_to_be_tested[i], 0, geneTree.GetHead()); // it's in the genome!
        if (!isSearchFailed)
        {
            cout << reads_to_be_tested[i] << ": Yes" << endl;
            w << reads_to_be_tested[i] << ": Yes" << endl;
        }
        else {
            cout << reads_to_be_tested[i] << ": No" << endl; // not in genome
            w << reads_to_be_tested[i] << ": No" << endl; // not in genome
        }
    }
    w.close(); // close the file
    
    cout << "\n\nresults in file: myResults.txt\n" << endl; // tells the user where the results can be found
}