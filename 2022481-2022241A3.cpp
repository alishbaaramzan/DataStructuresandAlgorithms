#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compare pairs based on frequency
bool sortByFrequency(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;
}

int main()
{
    cout << "Enter your text below\n";
    
    // Map to store word frequencies
    unordered_map<string, int> wordFrequencies;

    while (true)
    {
        cout << " ";
        string inputSentence;
        
        // Get input sentence from the user
        getline(cin, inputSentence);

        // Tokenize the input sentence into words
        istringstream wordStream(inputSentence);
        string word;
        
        // Count word frequencies
        while (wordStream >> word)
        {
            wordFrequencies[word]++;
        }

        // Convert the map to a vector for sorting
        vector<pair<string, int>> sortedWordFrequencies(wordFrequencies.begin(), wordFrequencies.end());
        
        // Sort words based on frequency
        sort(sortedWordFrequencies.begin(), sortedWordFrequencies.end(), sortByFrequency);

        cout << "Suggested Words" << endl;
        
        // Display the top 4 suggested words
        for (int i = 0; i < min(4, static_cast<int>(sortedWordFrequencies.size())); ++i)
        {
            cout << 1 + i << "-) " << sortedWordFrequencies[i].first << endl;
        }

        int check = 0;
        cout << "Press any other key to Continue\n";
        cout << "Choose: ";
        int userChoice;
        
        // Get user choice for word selection
        cin >> userChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string selectedWord;

        // Switch based on user choice
        switch (userChoice)
        {
        case 1:
            selectedWord = sortedWordFrequencies[0].first;
            break;
        case 2:
            selectedWord = sortedWordFrequencies[1].first;
            break;
        case 3:
            selectedWord = sortedWordFrequencies[2].first;
            break;
        case 4:
            selectedWord = sortedWordFrequencies[3].first;
            break;
        default:
            check++;
            break;
        }

        if (check == 0)
        {
            // Append the selected word to the input sentence
            inputSentence += " ";
            inputSentence += selectedWord;
        }

        cout << endl << inputSentence;
    }

    return 0;
}

