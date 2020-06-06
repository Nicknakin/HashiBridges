#include "HashiBoard.hpp"

namespace hashi{
    HashiBoard::HashiBoard(int width, int height) : width{width}, height{height} {
        build();
    }

    HashiBoard::~HashiBoard(){

    }


    int HashiBoard::getWidth(){
        return width; 
    }

    int HashiBoard::getHeight(){
        return height;
    }

    int HashiBoard::getNumNodes(){
        return numNodes;
    }

    void HashiBoard::build(){
        //Implement generation logic
    }

    void HashiBoard::verify(){
        //Implement Verification Logic
    }

    void to_json(nlohmann::json& j, const HashiBoard board){
        j = nlohmann::json{{"width", board.width}, {"height", board.height}, {"numNodes", board.numNodes}, {"nodes", board.nodes}};
    }

    void from_json(const nlohmann::json& j, HashiBoard& board){
        j.at("width").get_to(board.width);
        j.at("height").get_to(board.height);
        j.at("numNodes").get_to(board.numNodes);
        j.at("nodes").get_to(board.nodes);
    }
};

