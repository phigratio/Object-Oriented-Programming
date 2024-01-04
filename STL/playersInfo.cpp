#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
using namespace std;
class Player
{
public:
    string name;
    int score;

    Player(const string &n, int s) : name(n), score(s) {}
};

bool compareScore(const Player &p1, const Player &p2)
{
    return p1.score > p2.score;
}

int main()
{
    vector<Player> players;

    ifstream inputFile("players.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        string name;
        int score;
        if (getline(iss, name, ',') and iss >> score)
        {
            players.emplace_back(name, score);
        }
    }

    cout << "1. Players in alphabetical order without vowels and with a random number:\n";
    srand(time(0));
    for (auto &player : players)
    {
        player.name.erase(remove_if(player.name.begin(), player.name.end(),
                                    [](char c)
                                    { return tolower(c) == 'a' ||tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u'; }),
                          player.name.end());
        cout << player.name << rand() % 100 << "\n";
    }
    cout << "\n";

    cout << "2. Top five scorers in descending order:\n";
    stable_sort(players.begin(), players.end(), compareScore);
    for (size_t i = 0; i < min(players.size(), static_cast<size_t>(5)); ++i)
    {
        cout << players[i].name << " - Score: " << players[i].score << "\n";
    }
    cout << "\n";

    reverse(players.begin(), players.end());

    cout << "3. Players in reverse order:\n";
    for (const auto &player : players)
    {
        cout << player.name << " - Score: " << player.score << "\n";
    }
    cout << "\n";

    int x = 50;
    int countGreater = count_if(players.begin(), players.end(), [x](const Player &p)
                                { return p.score > x; });
    cout << "4. Number of players with a score greater than " << x << ": " << countGreater << "\n\n";


    int countEqual = count_if(players.begin(), players.end(), [x](const Player &p)
                              { return p.score == x; });
    cout << "5. Number of players who scored exactly " << x << ": " << countEqual << "\n\n";


    vector<Player> copiedPlayers(players);
    bool isSame = equal(players.begin(), players.end(), copiedPlayers.begin(), copiedPlayers.end(),
                        [](const Player &p1, const Player &p2)
                        { return p1.name == p2.name && p1.score == p2.score; });
    cout << "6. Are the two containers equal? " << (isSame ? "Yes" : "No") << "\n\n";

    vector<Player> otherPlayers = {{"Alice", 60}, {"Bob", 55}, {"Charlie", 70}};
    vector<Player> mergedPlayers;
    merge(players.begin(), players.end(), otherPlayers.begin(), otherPlayers.end(), back_inserter(mergedPlayers), compareScore);

    cout << "7. Merged list:\n";
    for (const auto &player : mergedPlayers)
    {
        cout << player.name << " - Score: " << player.score << "\n";
    }
    cout << "\n";

    double averageScore = accumulate(players.begin(), players.end(), 0.0,
                                          [](double sum, const Player &p)
                                          { return sum + p.score; }) /
                          players.size();
    cout << "8. Average score: " << averageScore << "\n";

    return 0;
}