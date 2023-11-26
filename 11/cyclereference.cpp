#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

class Song;

class Album {
    std::string name_;
    std::shared_ptr<Song> ptr;
public:
    Album(std::string name, Song *song); 
   ~Album();
   void release();
};

class Song {
   std::string title_;
   std::string artist_;
   std::shared_ptr<Album> ptr;
public:
   Song(std::string title, std::string artist = "Unknown")  
       :  title_(title), artist_(artist) {
       std::cout << "Create Song(" << title_ << ", " << artist_ << ')' << std::endl;
   }
   ~Song() {
       if (nullptr != ptr) {
           std::cout << "Delete Song(" << title_ << ", " << artist_ << ')' 
                   << ", use count: " << ptr.use_count() << std::endl;
           ptr->release();        
           ptr.reset();
       } 
   }
   
   void Setptr(Album *a) {
       ptr.reset(a);
   }    
   const char * GetTitle() const {
       return title_.data();
   }    
   const char * GetArtist() const {
       return artist_.data();
   }
   
   void release() {
    if (nullptr != ptr) {
        std::cout << "Delete Album from Song" << std::endl;
        ptr.reset();
    } 
}    
};

Album::Album(std::string name, Song *song): name_(name){
    ptr.reset(song); 
    song->Setptr(this);
    std::cout << "Song(" << ptr->GetTitle() << ", " << ptr->GetArtist() << ')' 
              << ", use count: " << ptr.use_count() << std::endl;
}

Album::~Album() {
       if (nullptr != ptr) {
            std::cout << "Delete Album{Song(" << ptr->GetTitle() << ", " << ptr->GetArtist() << ')' 
            << ", use count: " << ptr.use_count() << '}' << std::endl;
            ptr->release(); 
            ptr.reset();
       } 
}
   
void Album::release() {
    if (nullptr != ptr) {
            std::cout << "Song(" << ptr->GetTitle() << ", " << ptr->GetArtist() << ')' 
                    << ", use count: " << ptr.use_count() << "from Album" << std::endl;
            ptr.reset();
    } 
}    

int main() {
   Song *sp = new Song("Ode to Joy", "베토벤");
   Album a("베토벤 1집", sp);
   delete sp;  
}
