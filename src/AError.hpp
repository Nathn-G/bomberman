#ifndef __ERROR_HPP__
    #define __ERROR_HPP__

    #include "IndieNamespace.hpp"
    #include <exception>
    #include <string>
    #include <iostream>

class Indie::AError : public std::exception {
    private:
    std::string message = "";
    std::string location = "";

    public:
    AError(const std::string &what, const std::string &where = "Unknown");
    void printError();
    const char *what() const noexcept;
    const char *where() const noexcept;
};

#endif