//
// Created by mrble on 19/10/2026.
//

#ifndef WEAVE2_REPOSITORY_H
#define WEAVE2_REPOSITORY_H

#include <filesystem>

namespace weave::core {
    class Repository {
        public:
        Repository() = default;

        // Does specified path exist in repo?
        bool existsAt(const std::filesystem::path& path) const;
    };
} // core

#endif //WEAVE2_REPOSITORY_H
