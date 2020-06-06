#include "HashiNode.hpp"
#include "json.hpp"

namespace hashi{
    HashiNode::HashiNode() : HashiNode(0,0) {}

    HashiNode::HashiNode(int x, int y) : x{x}, y{y} {

    }

    int HashiNode::north(){
        return (links >> 6) & 0b11;
    }

    int HashiNode::east(){
        return (links >> 4) & 0b11;
    }

    int HashiNode::south(){
        return (links >> 2) & 0b11;
    }

    int HashiNode::west(){
        return links & 0b11;
    }

    void to_json(nlohmann::json& j, const HashiNode& node){
        j = nlohmann::json{{"x", node.x}, {"y", node.y}, {"connections", node.connections}, {"links", node.links}};
    }

    void from_json(const nlohmann::json& j, HashiNode& node){
        j.at("x").get_to(node.x);
        j.at("y").get_to(node.y);
        j.at("connections").get_to(node.connections);
        j.at("links").get_to(node.links);
    }

};
