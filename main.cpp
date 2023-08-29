#include <boost/format.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include "SnakeErrors.hpp"
#include "ConsoleScreen.hpp"
#include "SnakeGame.hpp"

namespace po = boost::program_options;
using boost::bad_any_cast;
namespace snake
{
    template <typename ScreenType>
    void mainloop(int width, int height, int speed)
    {
        try
        {
            snake::SnakeMap map;
            ScreenType screen(width, height);
            snake::SnakeGame game(screen, map, speed);
            game.mainloop();
        }
        catch (const snake::InvalidEnvironmentException &e)
        {
            throw e;
        }
    }
} // namespace snake

int main(int argc, char const **argv)
{
    int width = -1;
    int height = -1;
    double speed = 2.;
    const char *version = "0.8.0-20230829";
    po::options_description desc("Allowed options");
    desc.add_options()("help,h", "produce help message")(
        "version,v", "print version string")(
        "speed,s", po::value<double>(), "set game speed")(
        "width", po::value<int>(), "set map width")(
        "height", po::value<int>(), "set map height");
    po::variables_map vm;
    try
    {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    }
    catch (po::error &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << desc << std::endl;
        return -1;
    }
    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }
    if (vm.count("version"))
    {
        std::cout << "snake version " << version << std::endl;
        return 0;
    }
    if (vm.count("width"))
    {
        try
        {
            width = vm["width"].as<int>();
            if (width < 10)
            {
                std::cerr << "width must be greater equal 10" << std::endl;
                return -1;
            }
        }
        catch (const bad_any_cast &e)
        {
            std::cerr << "width must be integer" << std::endl;
            return -1;
        }
    }
    if (vm.count("height"))
    {
        try
        {
            height = vm["height"].as<int>();
            if (height < 10)
            {
                std::cerr << "height must be greater equal 10" << std::endl;
                return -1;
            }
        }
        catch (const bad_any_cast &e)
        {
            std::cerr << "height must be integer" << std::endl;
            return -1;
        }
    }
    if (vm.count("speed"))
    {
        try
        {
            speed = vm["speed"].as<double>();
        }
        catch (const bad_any_cast &e)
        {
            std::cerr << "speed must be double" << std::endl;
            return -1;
        }
    }
    try
    {
        snake::mainloop<snake::ConsoleScreen>(width, height, speed);
    }
    catch (snake::InvalidEnvironmentException &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
