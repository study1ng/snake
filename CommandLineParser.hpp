#ifndef COMMAND_LINE_PARSER_HPP
#define COMMAND_LINE_PARSER_HPP
#include <string>
#include <vector>
#include <map>
#include <set>


namespace CLP
{
    class AliasAlreadyRegisteredException : public std::runtime_error
    {
    public:
        AliasAlreadyRegisteredException() : std::runtime_error("Alias already registered") {}
        AliasAlreadyRegisteredException(std::string const &message) : std::runtime_error(message) {}
        AliasAlreadyRegisteredException(char const *message) : std::runtime_error(message) {}
    };

    class CommandLineParser
    {
        int argc;
        char const **argv;
        std::set<std::string> registered_alias;
        std::map<std::string, std::set<std::string>> alias_dict;
    public:
        CommandLineParser(int argc, char const **argv) : argc(argc), argv(argv) {}

        void registerAlias(std::string const &argument, std::string const &alias)
        {
            if (registered_alias.find(alias) != registered_alias.end())
            {
                throw AliasAlreadyRegisteredException(std::string("Alias already registered: ") + alias);
            }
            registered_alias.insert(alias);
            if (alias_dict.find(argument) == alias_dict.end())
            {
                alias_dict[argument] = std::set<std::string>();
            }
            alias_dict[argument].insert(alias);
        }
        void registerAliasList(std::vector<std::pair<std::string, std::string>> const &aliases)
        {
            for (auto const &alias : aliases)
            {
                registerAlias(alias.first, alias.second);
            }
        }
    };
}
#endif // COMMAND_LINE_PARSER_HPP