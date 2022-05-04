#include "Form.h"
#include <iostream>
#include <fstream>

//Intent: Set the given word of the game
//Pre: The input word is not set yet
//Post: Input word is set
void Form::SetInputWord(string inputWord) {
	this->inputWord = inputWord;
}

//Intent: Do some necessary pre-process of the given word. (e.g. upper or lower case transition.)
//Pre: The input word is set
//Post: Turn the input word into lower case 
void Form::ProcessInputWord() {
	for (int i = 0; i < this->inputWord.size(); i++) {
		if (this->inputWord[i] >= 'A' && this->inputWord[i] <= 'Z')
			this->inputWord[i] += 32;
	}
}

//Intent: Set the file name of the file that contains all the valid words.
//Pre: The file name is not set yet
//Post: The file name is set
void Form::SetFileName(string fileName) {
	this->fileName = fileName;
}

//Intent: Load the valid words from the file, and find out all the valid words composed by the letters in the given word.
//Pre: The given word and the file name are set
//Post: Save all valid words
void Form::Load_CompareWord() {
	string word;
	ifstream file;
	file.open(this->fileName);

	while (file >> word) {
		//separate each character of the given word
		vector<char> copyWord;
		for (int i = 0; i < inputWord.size(); i++)
			copyWord.push_back(inputWord[i]);

		//when the word is longer than the given word, it is not possible to be valid
		if (word.size() > this->inputWord.size())
			continue;			

		else {
			bool valid = false;
			string word2 = word;
			for (int i = word.size() - 1; i >= 0; i--) {
				vector<char>::iterator iter = find(copyWord.begin(), copyWord.end(), word[i]);

				//does not find the same character
				if (iter == copyWord.end())
					break;

				//erase the same character from both
				else {
					copyWord.erase(iter);
					word.erase(word.end() - 1);
				}
			}

			//when the characters in the word are all valid, the word is valid
			if (word.empty())
				valid = true;

			//save the valid word
			if (valid) {
				this->foundWords.push_back(word2);
			}
				
		}
	}

	file.close();
}

//Intent: Print the words found in the function Load_CompareWord().
//Pre: Already found the valid words
//Post: Print out the words
void Form::PrintFoundWords() {
	for (int i = 0; i < this->foundWords.size(); i++)
		cout << this->foundWords[i] << endl;
}