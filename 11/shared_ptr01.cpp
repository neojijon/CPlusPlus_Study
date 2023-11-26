#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

class Song {
   std::string title_;
   std::string artist_;

public:
   Song(std::string title, std::string artist = "Unknown") : title_(title), artist_(artist) {
       std::cout << "Create Song(" << title_ << ", " << artist_ << ')' << std::endl;
   }
   ~Song() {
       std::cout << "Delete Song(" << title_ << ", " << artist_ << ')' << std::endl;
   }
   const char * GetTitle() const {
       return title_.data();
   }    
   const char * GetArtist() const {
       return artist_.data();
   }    
};

int main() {
    std::shared_ptr<Song> sp0(new Song("Ode to Joy", "베토벤"));
        std::cout << sp0->GetTitle() << ", use count: " << sp0.use_count() << '\n';
   
        auto sp1 = std::make_shared<Song>("Yesterday", "비틀즈");
        std::shared_ptr<Song> sp2(sp1);
        std::cout << sp1->GetTitle() << ", use count: " << sp1.use_count() << '\n';
        
        sp2.reset(new Song("Blackbird", "비틀즈"));

        auto sp3 = std::make_shared<Song>("Greensleeves", "영국 전통 민요");

        std::shared_ptr<Song> sp4;
        sp4 = std::make_shared<Song>("I'm Still Standing", "엘튼 존");

        // The playlist vector makes copies of the shared_ptr pointers.
        std::vector<std::shared_ptr<Song>> playlist;
         
        playlist.push_back(std::move(sp0));
        playlist.push_back(std::move(sp1));
        playlist.push_back(std::move(sp2));
        playlist.push_back(sp3);
        playlist.push_back(sp4);
        for (auto& sp : playlist) {
            std::cout << "Playing " << sp->GetTitle() << 
                " by " << sp->GetArtist() << ", use count: " << 
                sp.use_count() << std::endl;
        }
}