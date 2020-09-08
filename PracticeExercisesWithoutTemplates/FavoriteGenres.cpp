//
// Created by Nitish Mohan Shandilya on 9/2/20.
// https://leetcode.com/discuss/interview-question/373006

unordered_map<string, string> buildSongToGenreMap(unordered_map<string, vector<string>>& genreSongs) {
    unordered_map<string, string> songToGenreMap;
    for (auto genreSong : genreSongs) {
        const string& genre = genreSong.first;
        const vector<string>& songs = genreSong.second;
        for (const string& song : songs) {
            songToGenreMap.emplace(song, genre);
        }
    }
    return songToGenreMap;
}

unordered_map<string, vector<string>> findFavoriteGenres(
    unordered_map<string, vector<string>>& userSongs,
    unordered_map<string, vector<string>>& genreSongs) {

    unordered_map<string, string> songToGenreMap = buildSongToGenreMap(genreSongs);

    unordered_map<string, vector<string>> result;
    unordered_map<string, int> genreCount;

    for (auto userRec : userSongs) {
        const string& user = userRec.first;
        const vector<string>& songs = userRec.second;
        int maxCount = 0;
        for (const string& song : songs) {
            auto it = songToGenreMap.find(song);
            if (it != songToGenreMap.end()) {
                auto genreIt = genreCount.find(it->second);
                int count = ( genreIt == genreCount.end()) ? 1 : genreIt->second+1;
                genreCount[it->second] = count;
                maxCount = max(maxCount, count);
            }
        }
        result.emplace(user, (0));
        for (auto genres : genreCount) {
            if (genres.second == maxCount)
                result[user].emplace_back(genres.first);
        }
        genreCount.clear();
    }
    return result;
}

int main() {
    unordered_map<string, vector<string>> userSongs;
    userSongs.emplace("David", initializer_list<string>{"song1", "song2", "song3", "song4", "song8"});
    userSongs.emplace("Emma", initializer_list<string>{"song5", "song6", "song7"});

    unordered_map<string, vector<string>> genreSongs;
    genreSongs.emplace("Rock", initializer_list<string> {"song1", "song3"});
    genreSongs.emplace("Dubstep", initializer_list<string> {"song7"});
    genreSongs.emplace("Techno", initializer_list<string> {"song2", "song4"});
    genreSongs.emplace("Pop", initializer_list<string> {"song5", "song6"});
    genreSongs.emplace("Jazz", initializer_list<string> {"song8", "song9"});

    unordered_map<string, vector<string>> result = findFavoriteGenres(userSongs, genreSongs);
    for (auto rec : result) {
        cout << rec.first << "->";
        for (string& genre : rec.second)
            cout << genre << " : ";
        cout << endl;
    }
}


// -----------------------------------------------------------------------------------------------
// Using lists instead of vector


unordered_map<string, string> buildSongToGenreMap(unordered_map<string, list<string>>& genreSongs) {
    unordered_map<string, string> songToGenreMap;
    for (auto genreSong : genreSongs) {
        const string& genre = genreSong.first;
        const list<string>& songs = genreSong.second;
        for (const string& song : songs) {
            songToGenreMap.emplace(song, genre);
        }
    }
    return songToGenreMap;
}

unordered_map<string, list<string>> findFavoriteGenres(
    unordered_map<string, list<string>>& userSongs,
    unordered_map<string, list<string>>& genreSongs) {

    unordered_map<string, string> songToGenreMap = buildSongToGenreMap(genreSongs);

    unordered_map<string, list<string>> result;
    unordered_map<string, int> genreCount;

    for (auto userRec : userSongs) {
        const string& user = userRec.first;
        const list<string>& songs = userRec.second;
        int maxCount = 0;
        for (const string& song : songs) {
            auto it = songToGenreMap.find(song);
            if (it != songToGenreMap.end()) {
                auto genreIt = genreCount.find(it->second);
                int count = ( genreIt == genreCount.end()) ? 1 : genreIt->second+1;
                genreCount[it->second] = count;
                maxCount = max(maxCount, count);
            }
        }
        result.emplace(user, (0));
        for (auto genres : genreCount) {
            if (genres.second == maxCount)
                result[user].emplace_back(genres.first);
        }
        genreCount.clear();
    }
    return result;
}

int main() {
    unordered_map<string, list<string>> userSongs;
    userSongs.emplace("David", initializer_list<string>{"song1", "song2", "song3", "song4", "song8"});
    userSongs.emplace("Emma", initializer_list<string>{"song5", "song6", "song7"});

    unordered_map<string, list<string>> genreSongs;
    genreSongs.emplace("Rock", initializer_list<string> {"song1", "song3"});
    genreSongs.emplace("Dubstep", initializer_list<string> {"song7"});
    genreSongs.emplace("Techno", initializer_list<string> {"song2", "song4"});
    genreSongs.emplace("Pop", initializer_list<string> {"song5", "song6"});
    genreSongs.emplace("Jazz", initializer_list<string> {"song8", "song9"});

    unordered_map<string, list<string>> result = findFavoriteGenres(userSongs, genreSongs);
    for (auto rec : result) {
        cout << rec.first << "->";
        for (string& genre : rec.second)
            cout << genre << " : ";
        cout << endl;
    }
}