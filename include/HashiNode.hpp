#include "json.hpp"

#ifndef HASHINODE_inc
#define HASHINODE_inc

namespace hashi{
    class HashiNode{
        public:
            HashiNode();
            HashiNode(int x, int y);

            int north();
            int east();
            int south();
            int west();

            int x;
            int y;
            int connections;
            int links;

            friend void to_json(nlohmann::json& j, const HashiNode& node);
            friend void from_json(const nlohmann::json& j, HashiNode& node); 
    };
};

#endif

