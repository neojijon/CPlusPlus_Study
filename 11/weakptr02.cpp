#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

class Album;

class Song {
    std::string title_;
    std::string artist_;
    std::weak_ptr<Album> ptr;
public:
    Song( std::string title, std::string artist, std::shared_ptr<Album>& ab);
    ~Song();

    const char * GetAlbum() const;
    const char * GetTitle() const;
    const char * GetArtist() const;
};

class Album {
    std::string name_;
    std::vector<std::shared_ptr<Song>> ptr;
    friend const char * Song::GetAlbum() const;

public:
    Album( std::string name ) : name_( name ) {
        std::cout << "Create Album(" << name_.c_str() << ')' << std::endl;
    }
    ~Album() {
        for (auto& p : ptr) { p.reset(); }
        std::cout << "Delete Album(" << name_.c_str() << ')' << std::endl;
    }

    const char * GetAlbum() const{ 
        return name_.data();
    }

    void SetSong(const std::shared_ptr<Song>& sp ) {
        ptr.push_back(std::move(sp));
    }

    void GetSong() {
        for (auto& p : ptr) {
            std::cout << "Playing " << p->GetTitle() 
                      << " by " << p->GetArtist() 
                      << ", use count: " << p.use_count() << std::endl;
        }
    }
};

Song::Song( std::string title, std::string artist, std::shared_ptr<Album>& ab)
        : title_( title ), artist_( artist ), ptr(ab) {
    std::cout << "Create Song(" << title_.c_str() << ", " << artist_.c_str() << ')' << std::endl;
}

Song::~Song() {
    ptr.reset();
    std::cout << "Delete Song(" << title_.c_str() << ", " << artist_.c_str() << ')' << std::endl;
}

const char * Song::GetAlbum() const {
    if (const std::shared_ptr<Album>& p = ptr.lock()) {
        return p->name_.c_str();
    }
    return nullptr;
}

const char * Song::GetTitle() const {
    return title_.data();
}
const char * Song::GetArtist() const {
    return artist_.data();
}

int main() {
    std::shared_ptr<Album> ab  = std::make_shared<Album>("베토벤 1집");

    std::shared_ptr<Song> sp0( new Song( "Ode to Joy", "베토벤", ab ) );
    ab->SetSong(sp0);
    std::cout << "Album : " << sp0->GetAlbum() << std::endl;
    
    ab->SetSong(std::make_shared<Song>( "Yesterday", "비틀즈", ab) );
    std::shared_ptr<Song> sp2( new Song( "Blackbird", "비틀즈", ab ) );
    ab->SetSong(sp2);
    sp2.reset();
    
    ab->SetSong( std::make_shared<Song>( "Greensleeves", "영국 전통 민요", ab ));

    std::shared_ptr<Song> sp4(nullptr);
    sp4 = std::make_shared<Song>("I'm Still Standing", "엘튼 존", ab);
    ab->SetSong( sp4 );
    ab->GetSong();
}