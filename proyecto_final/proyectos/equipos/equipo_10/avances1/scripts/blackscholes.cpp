#include <iostream>

class BlackSch{
    public:
        void bar(){
            std::cout << "Hello" << std::endl;
        }
};

extern "C" {
    BlackSch* BS_new(){ return new BlackSch(); }
    void BS_bar(BlackSch* bs){ bs->bar(); }
}