#ifndef HASHIBOARD_inc
#define HASHIBOARD_inc

#include "HashiNode.hpp"
#include "json.hpp"

#include <vector>

namespace hashi{
    class HashiBoard {
        public:
            HashiBoard(int width, int height);
            ~HashiBoard();

            int getWidth();
            int getHeight();
            int getNumNodes();

            friend void to_json(nlohmann::json& j, const HashiBoard board);
            friend void from_json(const nlohmann::json& j, HashiBoard& board);

        private:
            void build();
            void verify();

            int width;
            int height;
            int numNodes;

            std::vector<HashiNode> nodes;
    };
};
#endif

