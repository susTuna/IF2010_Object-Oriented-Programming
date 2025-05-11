#include "Playlist.hpp"

Playlist::Playlist(string playlistName) : name(playlistName){}

const string &Playlist::getName() const{ return name; }

const vector<Song> &Playlist::getSongs() const{ return songs; }

void Playlist::addSong(const Song &song){
    for(const auto& _song : songs){
        if(_song == song) return;
        
    }
    songs.push_back(song);
}

bool Playlist::removeSong(const Song &songToRemove){
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if (*it == songToRemove) {
            songs.erase(it);
            return true;
        }
    }
    return false;
}

void Playlist::removeSongByIndex(size_t index){
    if(index >= songs.size()) throw out_of_range("Index out of range");
    songs.erase(songs.begin() + index);
}

size_t Playlist::numberOfSongs() const{ return songs.size(); }

ostream &operator<<(ostream &os, const Playlist &pl){
    int i = 1;
    os << "Playlist: " << pl.getName()
       << " (" << pl.numberOfSongs() << " lagu)\n";
    for (const auto& _songs : pl.getSongs()){
        os << i++ << ". " << _songs << endl;
    }
    return os;
}